import re

user_input = input("Enter String : ")
x = re.findall("[bh][aiu]t",user_input)

if len(x) != 0:
    print('\nStrings recognised are :', x)
else:
    print('\nNothing recognised in given string :\n'+user_input)