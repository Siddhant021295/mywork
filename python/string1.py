
def super_reduced_string(s):
    i=1
    for x in range(len(s)-1):
        if s[x]==s[x+1]:
            i =0 
            print 
            a=s[:x]+s[x+2:]
    x=a
    if i == 1:
        print 'x'
    return a
            
print super_reduced_string('siddhant')