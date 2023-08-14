print('Name : Bijay Regmi\nRegistration Number : 210913032\n')

def compare(key,str,n):
    for i in range(n):
        if key[i] != '*' and key[i] != s[i]:
            return 0
    return 1

L = ['aabaabac', 'cabaabca', 'aaabbcba', 'aabacbab', 'acababba']
n = 8
print("Enter search string of", n, "letters : ", end='')
key = input()


print("Matched String(s) are : ")
for s in L:
    if compare(key,s,n):
        print(s)