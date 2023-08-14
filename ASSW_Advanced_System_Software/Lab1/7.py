s = input("Enter String : ")

print("\n\n\n")

print("Number of Characters :",len(s))
print("String repeated 10 times :",s*10)
print("First Character :",s[0])
print("First 3 Characters :",s[0:3])
print("Last 3 Characters :",s[-3:len(s)])
print("String Backwards :",s[::-1])
if len(s)>7:
  print("Seventh Character : ",s[6])
else:
  print("String does not have seventh character")
print("First and Last Character removed :",s[1:-1])
print("Uppercase :",s.upper())
print("After replacing e : ",s.replace('e','a'))
print("After replacing every letter with space(_) : ",s.replace(s,' '))