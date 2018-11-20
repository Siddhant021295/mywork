def fun(s):
    for x in range(len(s)):
        if (s[x] in s[x+1:]):
            return s[x]
s=raw_input()
print fun(s)