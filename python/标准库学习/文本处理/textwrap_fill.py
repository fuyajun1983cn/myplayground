#!/usr/bin/env python3

import textwrap
from textwrap_example import sample_text

print("No dedent:\n")
print(textwrap.fill(sample_text, width=50))

