def factorial(n):
	if n==0:
		return 1
	return n*factorial(n-1)

x = int(raw_input("enter a no:"))
print factorial(x)
