s = input("Enter the string")
match_index = []
L = ['aabaabac', 'cabaabca', 'aaabbcba', 'aabacbab', 'acababba']
for i in range(len(L)):
    match = True
    for j in range(len(s)):
        if s[j]!='*' and s[j]!=L[i][j]:
            match = False
    if(match):
        match_index.append(i+1)
print("The strings in the list which match the user string are : ")
for x in match_index:
    print(x)
