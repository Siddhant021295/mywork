import sys

def alternatingCharacters(s):
    i=0
    s1=[]
    s1+=s
    x=0
    while(len(s1)-1-x):
        if s1[x]==s1[x+1]:
            s1.pop(x+1)
        else:
            x+=1
    return len(s)-len(s1)
            

q = int(raw_input().strip())
for a0 in xrange(q):
    s = raw_input().strip()
    result = alternatingCharacters(s)
    print(result)