# -*- coding: utf-8 -*- 

import os

pos = 0
line = 0
word = 0
last_token = -1

"""
     parse state
"""
T_EOF=0
T_WORD_START=1
T_WORD_END=2
T_NEWLINE=3

def load_file(path):
    if not os.path.isfile(path):
        print("invalid file path!")
    f = open(path, 'r')
    text = f.read()
    return text
	
def next_token(text):
    global pos
    global line
    global word
    global last_token

    while True:
        #print ("POS: {0}".format(text[pos]))
        c = text[pos]
        if c == '\0':
            print("SHOULD ONLY ONCE")
            return T_EOF
        elif c == '\n':
            pos=pos+1
            return T_NEWLINE
        elif c in [' ', '\t', '\r', ':', '#', ',', ';','.']:
            pos+=1
            if last_token == T_WORD_START:
                return T_WORD_END
            else:
                continue
        else:
            pos=pos+1
            return T_WORD_START
	

	
def parse_file_content(text):
    global pos
    global line
    global word
    global last_token
    
    pos = 0
    line = 0
    word = 0
    
    while True:
        current_token = next_token(text)
        if current_token == T_EOF:
            break
        elif current_token == T_NEWLINE:
            line += 1
            if last_token == T_WORD_START:
                word += 1
        elif current_token == T_WORD_END:
            word += 1
        else:
            #print("Do Nothing")
            pass
        last_token = current_token   
	

if __name__ == "__main__":
    FILE_PATH=r"E:\mysoft\mypythontool\test.txt"
    file_content = load_file(FILE_PATH)
    file_content = file_content + '\n\0'
    parse_file_content(file_content)
	
    print("LINE: {0}, COUNT: {1}".format(line, word))
