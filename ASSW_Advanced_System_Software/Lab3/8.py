import keyword
import re
s1 = input("\nEnter string : ")
if(re.match("[_A-Za-z][_a-zA-Z0-9]*",s1) and not keyword.iskeyword(s1)):
    print(s1, 'is an identifier')
else:
    print(s1, 'is not an identifier\n')
