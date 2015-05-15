#!/usr/bin/env python3
#encoding:utf-8

import textwrap
from textwrap_example import sample_text

dedented_text = textwrap.dedent(sample_text).strip()
for width in [ 45, 70 ]:
    print("%d Colums:\n" % width)
    print (textwrap.fill(dedented_text, 
                         initial_indent=' ',
                         subsequent_indent=' ' * 4,
                         width=width))
    print()
