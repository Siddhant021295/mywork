#!/bin/python

import sys

def birthdayCakeCandles(n, ar):
    x = 0
    ar=sorted (ar,reverse=True)
    z=ar[0]
    print z
    for y in ar:
        if z==y:
            x=x+1
        else:
            break
    return x

n = int(raw_input().strip())
ar = map(int, raw_input().strip().split(' '))
result = birthdayCakeCandles(n, ar)
print(result)
