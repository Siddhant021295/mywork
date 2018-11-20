def quicksort(s,low,up):
    if up<low:
        return
    pivloc=partition(s,low,up)
    quicksort(s,low,pivloc-1)
    quicksort(s,pivloc+1,up)
def partition(s,low,up):
    piv=s[low]
    i=low+1
    j=up
    while j>=i:
        while(s[i]<piv and i<j):
            i+=1
        while(s[j]>piv):
            j-=1
        if(i<j):
            temp=s[i]
            s[i]=s[j]
            s[j]=temp
            j-=1
            i+=1
        else:
            i+=1
    s[low]=s[j]
    s[j]=piv
    return j
s=map(int,raw_input().strip().split(' '))
quicksort(s,0,len(s)-1)
print s