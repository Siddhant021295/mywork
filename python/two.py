import sys

n,k = raw_input().strip().split(' ')
n,k = [int(n),int(k)]
rQueen,cQueen = raw_input().strip().split(' ')
rQueen,cQueen = [int(rQueen),int(cQueen)]

i1=min(n-rQueen,n-cQueen)
i3=min(cQueen-1,rQueen-1)
i4=min(n-rQueen,cQueen-1)
i2=min(n-cQueen,rQueen-1)

i5 = cQueen -1
i6 = rQueen -1
i7 = n-rQueen
i8 = n-cQueen
for p in range(k):
    rObstacle,cObstacle = raw_input().strip().split(' ')
    rObstacle,cObstacle = [int(rObstacle),int(cObstacle)]
    if (rQueen-rObstacle ==0):
        a=abs(cQueen-cObstacle)-1
    else:
        a=abs(rQueen-rObstacle)-1
    if cQueen == cObstacle and rQueen>rObstacle:
        if a<i5:
            i5=a
            #print 'asd5' 
    elif rQueen == rObstacle and cQueen>cObstacle:
        if a<i6:
            i6=a
            #print 'asd6' 
    elif rQueen == rObstacle and cQueen<cObstacle:
        if a<i7:
            i7=a
           # print 'asd7' 
    elif cQueen == cObstacle and rQueen<rObstacle:
        if a<i8:
            i8=a   
    elif cQueen<cObstacle and rQueen<rObstacle and ((cQueen-cObstacle)/(rQueen-rObstacle))==1:
        if a<i1:
            i1=a
           # print 'asd1' 
    elif cQueen<cObstacle and rQueen>rObstacle and ((cQueen-cObstacle)/(rQueen-rObstacle))==-1: 
        if a<i2:
            i2=a
            #print 'asd2' 
    elif cQueen>cObstacle and rQueen>rObstacle and ((cQueen-cObstacle)/(rQueen-rObstacle))==1:
        if a<i3:
            i3=a
            #print 'asd3' 
    elif cQueen>cObstacle and rQueen<rObstacle and ((cQueen-cObstacle)/(rQueen-rObstacle))==-1:
        if a<i4:
            i4=a
            #print 'asd4' 
print i1
print i2
print i3
print i4
print i5
print i6
print i7
print i8
