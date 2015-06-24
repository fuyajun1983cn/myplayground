#!/usr/bin/env python3

import difflib
from difflib_data import *

d = difflib.Differ()
diff = d.compare(text1_lines, text2_lines)
print('\n'.join(diff))

diff = difflib.unified_diff(text1_lines,
        text2_lines, lineterm=' ', )
print('\n'.join(diff))
