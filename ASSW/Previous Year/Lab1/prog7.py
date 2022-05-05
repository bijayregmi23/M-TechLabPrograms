s = input("Enter the string")
total_char = 0
for i in s:
    total_char = total_char + 1
print(f"The total number of characters in the string is {total_char}")
print(f"The string repeated 10 times : {s*10}")
print(f"The first character of the string is {s[0]}")
print(f"The first three characters of the string is {s[:3]}")
print(f"The last three characters of the string is {s[-3:]}")
print(f"The string backwards is {s[::-1]}")
if len(s)<7:
    print("The string is not long enough")
else:
    print(f"The seventh character of the string is {s[6]}")
print(f"The string with its first and last characters removed is {s[1:-1]}")
print(f"The string in all caps is {s.upper()}")
print(f"The string with every 'a' replaced with an 'e' is {s.replace('a','e')}")
for i in range(0,len(s)):
    if s[i].isalpha()==True:
        s=s.replace(s[i],' ')
print(f"The string with every letter replaced by a space is {s}")
