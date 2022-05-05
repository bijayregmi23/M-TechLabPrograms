import re
def removeComments(string):
    string = re.sub(re.compile("/\*.*?\*/",re.DOTALL ) ,"" ,string) # remove all occurrences streamed comments (/*COMMENT */) from string
    string = re.sub(re.compile("//.*?\n" ) ,"" ,string) # remove all occurrence single-line comments (//COMMENT\n ) from string
    return string

with open('cprogram.c','r') as file:
    text = file.read()
modified_program = removeComments(text)
print("C Program after removing the single line and multi-line comments : ")
print(modified_program)
