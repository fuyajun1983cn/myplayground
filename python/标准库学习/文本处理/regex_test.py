#!/usr/bin/env python3
#encoding:utf-8

import re

pattern = 'this'
text = 'Does this text match the pattern?'

match = re.search(pattern, text)

s = match.start()
e = match.end()

print('Found "{0}"\n in "{1}"\nfrom {2} to {3} ("{4}")'.format(match.re.pattern,
    match.string, s, e, text[s:e]))


'''
results:

Found "this"
 in "Does this text match the pattern?"
from 5 to 9 ("this")

'''


#
# Compiling Expressions
#
regexes = [re.compile(p) for p in ['this', 'that'] ]
text = 'Does this text match the pattern?'
print('Text: {0}\n'.format(text))

for regex in regexes:
    print('Seeking "%s" -->' % regex.pattern )

    if regex.search(text):
        print('Match!')
    else:
        print('no match')

#
# Multiple Matches
#
text = 'abbaaabbbbaaaaa'
pattern = 'ab'

for match in re.findall(pattern, text):
    print('Found "%s"' % match)
# return an iterator, for each match, the iterator
# return a match object
for match in re.finditer(pattern, text):
    s = match.start()
    e = match.end()
    print('Found "%s" at %d:%d' %(text[s:e], s, e))


#
# pattern syntax
#
def test_patterns(text, patterns=[]):
    """
    Given source text and a list of patterns, look for matches for each pattern
    within the text and print them to stdout.
    """
#Looking for each pattern in the text and print the results
    for pattern, desc in patterns:
        print('Pattern %r (%s)' % (pattern, desc))
        print('   %r' % text)
        for match in re.finditer(pattern, text):
            s = match.start()
            e = match.end()
            substr = text[s:e]
            n_backslashes = text[:s].count('\\')
            prefix = '.' * (s + n_backslashes)
            print ('   %s%r' % (prefix, substr))

    return


if __name__ == '__main__':
    test_patterns('abbaaabbbbaaaaa', [('ab', "'a' followed by 'b'"), ])
    
    test_patterns(
        'abbaabbba',
        [ ('ab*',   'a followed by zero or more b'),
        ('ab+',     'a followed by one or more b'),
        ('ab?',     'a followed by zero or one b'),
        ('ab{3}',   'a followed by three b'),
        ('ab{2,3}', 'a followed by two to three b'),
        ])

   # turn off greedy consumption of the input 
    test_patterns(
        'abbaabbba',
        [ ('ab*?',   'a followed by zero or more b'),
        ('ab+?',     'a followed by one or more b'),
        ('ab??',     'a followed by zero or one b'),
        ('ab{3}?',   'a followed by three b'),
        ('ab{2,3}?', 'a followed by two to three b'),
        ])

   #Character Sets
    test_patterns(
       'abbaabbba',
       [('[ab]', 'either a or b'),
       ('a[ab]+', 'a followed by 1 or more a or b'),
       ('a[ab]+?', 'a followed by 1 or more a or b, not greedy'),
       ])

    test_patterns(
       'This is some text -- with punctuation.',
       [('[^-. ]+', 'sequences without -, ., or space'),
       ])

    test_patterns(
        'This is some text -- with punctuation.',
        [ ('[a-z]+', 'sequences of lowercase letters'),
        ('[A-Z]+', 'sequences of uppercase letters'),
        ('[a-zA-Z]+', 'sequences of lowercase or uppercase letters'),
        ('[A-Z][a-z]+', 'one uppercase followed by lowercase'),
        ])

    test_patterns(
        'A prime #1 example!', 
        [(r'\d+', 'sequence of digits'),
         (r'\D+', 'sequence of nondigits'),
         (r'\s+', 'sequence of whitespace'),
         (r'\S+', 'sequence of nonwhitespace'),
         (r'\W+', 'alphanumeric characters'),
         (r'\W+', 'nonalphanumeric'),
         ])

    test_patterns(
        'This is some text -- with punctuation.',
        [ (r'^\w+', 'word at start of string'),
        (r'\A\w+', 'word at start of string'),
        (r'\w+\S*$', 'word near end of string, skip punctuation'),
        (r'\w+\S*\Z', 'word near end of string, skip punctuation'),
        (r'\w*t\w*', 'word containing t'),
        (r'\bt\w+', 't at start of word'),
        (r'\w+t\b', 't at end of word'),
        (r'\Bt\B',  't, not start or end of word'),
        ])


    text = 'This is some text -- with punctuation.'
    print (text)
    for pattern in [ r'^(?P<first_word>\w+)',
                r'(?P<last_word>\w+)\S*$',
                r'(?P<t_word>\bt\w+)\W+(?P<other_word>\w+)',
                r'(?P<ends_with_t>\w+t)\b',
                ]:
        regex = re.compile(pattern)

        match = regex.search(text)
        print('Matching "%s"' % pattern)
        print(' ', match.groups())
        print(' ', match.groupdict())

#
#Verbose Mode
#
    address = re.compile(
            '''
            [\w\d.+-]+    #username
            @
            ([\w\d.]+\.)+  #domain name prefix
            (com|org|edu)
            ''',
            re.VERBOSE)
    candidates = [
            'first.last@example.com',
            'first.last+category@gmail.com',
            'valid-address@mail.example.com',
            'not=valid@example.foo',
            ]

    for candidate in candidates:
        match = address.search(candidate)
        print('%-30s    %s' % (candidate, 'Matches' if match else 'No Match'))


    address = re.compile(
            '''
# A name is made up of letters, and may include "."
#for title abbreviations and middle initials.
            ((?P<name>
            ([\w.,]+\s+)*[\w.,]+)
            \s*
#Email address are wrapped in angle
            <
            )?
#The address itself: username@domain.tld
            (?P<email>
            [\w\d.+-]+   #username
            @
            ([\w\d.]+\.)+
            (com|org|edu)
            )
            >?
            ''',
            re.VERBOSE)
    candidates = [
            'first.last@example.com',
            'first.last+categroy@gmail.com',
            'valid-address@mail.example.com',
            'not-valid@example.foo',
            'First Last <first.last@example.com>',
            'No Brackets first.last@example.com',
            'First Last',
            'First Middle Last <first.last@example.com>',
            'First M. Last <first.last@example.com>',
            'First M. Last <first.last@example.com>',
            '<first.last@example.com>',
            ]

    for candidate in candidates:
        print('Candidate:', candidate)
        match = address.search(candidate)
        if match:
            print('    Name :', match.groupdict()['name'])
            print('    Email:', match.groupdict()['email'])
        else:
            print('    No match')


#
# embedding flags in pattern
#
    text = 'This is some text -- with punctuation.'
    pattern = r'(?i)\bT\w+' #寻找包含t和T的单词
    regex = re.compile(pattern)

    print('Text        :', text)
    print('Pattern     :', pattern)
    print('Matches     :', regex.findall(text))


#
#positive looking ahead
#
    address = re.compile(
            '''
# A name is made up of letters, and may include "."
#for titile abbreviations and middle initials.
            ((?P<name>
            ([\w.,]+\s+)*[\w.,]+
            )
            \s+
            )

#LookAhead
#只有当Email地址包<>包含或没有被<>包含时，整个匹配才成立
#
            (?=(<.*>$)
            |
            ([^<].*[^>]$) #remainder *not* wrapped in angle brackets
            )

            <?  #optional opening angle bracket
            (?P<email>
            [\w\d.+-]+
            @
            ([\w\d.]+\.)+
            (com|org|edu)
            )

            >?
            ''',
            re.VERBOSE)

    candidates = [
            'First Last <first.last@example.com>',
            'NO Brackets first.last@example.com',
            'Open bracket <first.last@example.com',
            'Close bracket first.last@example.com>',
            ]

    for candidate in candidates:
        print('Candidate:', candidate)
        match = address.search(candidate)
        if match:
            print('    Name  :', match.groupdict()['name'])
            print('    Email :', match.groupdict()['email'])
        else:
            print('    No match')


    address = re.compile(
            r'''
#the regular name
            (\w+)  #first name
            \s+
            (([\w.]+)\s+)?  #optional middle name or initial
            (\w+)           #last name

            \s+

            <

#The address: first_name.last_name@domain.tld
            (?P<email>
            \1
            \.
            \4
            @
            ([\w\d.]+\.)+  #domain name prefix
            (com|org|edu)
            )

            >
            ''',
            re.VERBOSE | re.IGNORECASE)

    candidates = [
            'First Last  <first.last@example.com>',
            'Different Name <first.last@example.com>',
            'First Middle Last <first.last@example.com>',
            'First M. Last  <first.last@example.com>',
            ]

    for candidate in candidates:
        print('Candidates: ', candidate)
        match = address.search(candidate)
        if match:
            print('    Match name  :', match.group(1), match.group(4))
            print('    Match email :', match.group(5))
        else:
            print('    No match')


    address = re.compile(
            r'''
#the regular name
            (?P<first_name>\w+)  #first name
            \s+
            (([\w.]+)\s+)?  #optional middle name or initial
            (?P<last_name>\w+)           #last name

            \s+

            <

#The address: first_name.last_name@domain.tld
            (?P<email>
            (?P=first_name)
            \.
            (?P=last_name)
            @
            ([\w\d.]+\.)+  #domain name prefix
            (com|org|edu)
            )

            >
            ''',
            re.VERBOSE | re.IGNORECASE)

    candidates = [
            'First Last  <first.last@example.com>',
            'Different Name <first.last@example.com>',
            'First Middle Last <first.last@example.com>',
            'First M. Last  <first.last@example.com>',
            ]

    for candidate in candidates:
        print('Candidates: ', candidate)
        match = address.search(candidate)
        if match:
            print('    Match name  : ', match.groupdict()['first_name'], match.groupdict()['last_name'])
            print('    Match email :', match.groupdict()['email'])
        else:
            print('    No match')


    #self modifying strings with patterns
    bold = re.compile(r'\*{2}(.*?)\*{2}')
    text = 'Make this **bold**. This **too**.'

    print('Text: ', text);
    print('Bold: ', bold.sub(r'<b>\1</b>', text))


    bold = re.compile(r'\*{2}(?P<bold_text>.*?)\*{2}')
    text = 'Make this **bold**. This **too**.'

    print('Text: ', text);
#use count to limit the number of substitutions performed.
    print('Bold: ', bold.sub(r'<b>\g<bold_text></b>', text, count=1)) 


#Splitting with Patterns 
    text = '''Paragraph one
    on two lines.


    Paragraph two.



    Paragraph three. '''

    for num, para in enumerate(re.split(r'\n{2,}', text)):
            print(num, repr(para))

