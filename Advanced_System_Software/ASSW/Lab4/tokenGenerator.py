import re

keyWords = [
    'auto','double','int','struct',
    'break','else','long','switch',
    'case','enum','register','typedef',
    'char','extern','return','union',
    'continue','for','signed','void',
    'do','if','static','while',
    'default','goto','sizeof','volatile',
    'const','float','short','unsigned',
]

lexBegin = 0
lexEnd = 0


with open('input.c') as inputFile:
    def replacer(match):
        s = match.group(0)
        if s.startswith('/'):
            return ""
        else:
            return s
    pattern = re.compile(
        r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
        re.DOTALL | re.MULTILINE
    )
    print(re.sub(pattern, replacer, text))
