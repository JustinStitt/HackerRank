import sys
import os
import re
if(len(sys.argv) < 3): print('too few args')

inp = open(sys.argv[1], 'r').read()
out = open(sys.argv[2], 'w+')


matches = re.findall('\d{9}', inp)

for i in range(len(matches)):
    out.write(matches[i] + ',\n') if i != len(matches) - 1 \
                    else out.write(matches[i])

