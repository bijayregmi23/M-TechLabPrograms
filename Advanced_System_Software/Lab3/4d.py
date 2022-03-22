import re

text=input("Enter a string: ")
caps = re.findall("[A-Z][a-z]",text)
for x in caps:
    replace = x.lower()
    text = re.sub(x,replace,text)
print("Modified text is :",text)