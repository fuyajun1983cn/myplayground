# -*- coding: utf-8 -*- 

import os
import re
import inspect

current_dir = os.path.dirname(inspect.getfile(inspect.currentframe()))
in_filepath = os.path.join(current_dir, "input.txt")
out_filepath = os.path.join(current_dir, "output.txt")

in_file = open(in_filepath)
out_file = open(out_filepath, 'w');

##
#  <4>[  295.097046] >>>RTP Current Sequence: 16!!!
##
try:
    for line in in_file:
        regex = re.compile(".*Sequence:\s(\d+)!!!$")
        result = regex.match(line)
        seq = result.group(1)
        out_file.write(seq + "\n")
        print(seq)
finally:
        in_file.close()
        out_file.close()



print("Done!")

