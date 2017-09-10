#!/bin/python
#Between Two Sets
import sys
    
def hcf(b):
    b=sorted(b)
    c = b[0]
    if len(b)==1:
        return b[0]
    for x in range(len(b)-1):
        r = 9999 
        a = b[x+1]
        while(r!=0):
            r = a-c*(a/c)
            a,c= c,r
        c=a
    #print a
    return a
#hcf([16, 32 ,96])           
def mul(a):
    ans = 1
    for x in a:
        ans = x*ans
    #print ans
    return ans
def getTotalX(a, b):
    p=1
    if len(a)>1:
        for f in range(len(a)-1):
            p = hcf([a[0+f],a[1+f]])
            a[1+f] = (a[0+f]*a[1+f])/p  
        #print p
    x=a[-1]
    y= hcf (b)
    print x,y
    i=0
    if x>y:
        return 0
    for t in range(y-x+1):
       if (t+x)% x ==0 and  y%(t+x)==0:
           i =i+1

    return i

if __name__ == "__main__":
    n, m = raw_input().strip().split(' ')
    n, m = [int(n), int(m)]
    a = map(int, raw_input().strip().split(' '))
    b = map(int, raw_input().strip().split(' '))
    total = getTotalX(a, b)
    print total