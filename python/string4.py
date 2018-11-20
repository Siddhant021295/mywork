#!/bin/python

import sys


n = int(raw_input().strip())
s1 = raw_input().strip()
k = int(raw_input().strip())
k = k%26
s=''
for x in s1:
    if 65<=ord(x)<=90:
        if ord(x)+k <=90:
            s= s+ chr(ord(x)+k)
        else:
            s=s+chr(ord(x)+k-26)
    elif 97<=ord(x)<=122:
        if ord(x)+k <=122:
            s= s+ chr(ord(x)+k)
        else:
            s=s+chr(ord(x)+k-26)
    else:
        s=s+x
print s