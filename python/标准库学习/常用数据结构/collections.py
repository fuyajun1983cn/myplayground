#!/usr/bin/env python3

import collections

c = collections.Counter("abcdaab")

for letter in 'abcde': 
    print('%s : %d' % (letter, c[letter]))





