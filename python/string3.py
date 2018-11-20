import sys
def dup(s,s_len):
    while True:
        i=1
        a=s
        for x in range(s_len-1):
            if s[x] == s[x+1]:
                i=0
                a = s.replace(s[x],'')
                break
            
        s=a
        s_len=len(s)
        if i==1:
            break
    return s
s_len = int(raw_input().strip())
s = raw_input().strip()

s=dup(s,s_len)
s_len=len(s)
#print s
#print s_len
#sys.exit()
list1 = []
for x in s:
    if x not in list1:
        list1.append(x)
#print list1
if len(list1)==2:
    print s_len
    sys.exit()
if len(list1)==1 or len(list1)==0:
    print 0
    sys.exit()

x=0
y=x+1
z=''
list2=[]

while x < len(list1):
    y=x+1
    #print y
    while y < len(list1):
        for r in s:
            if r==list1[x]: 
                z=z+r
            elif r==list1[y]:
                z=z+r
        t=dup(z,len(z))
        if len(t)==len(z) :
            list2.append(len(t))
        z=''
        y+=1
    x+=1    
if list2:
    print max(list2)
else:
    print 0