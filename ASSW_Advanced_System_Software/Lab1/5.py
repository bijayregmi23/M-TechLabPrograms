a = 1
b = 1
n = int(input("Enter n : "))
i = 2
print(a)
print(b)
while i<n:
  c = a + b
  print(c)
  a=b
  b=c
  i += 1
