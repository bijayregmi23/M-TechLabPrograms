strings = []
n = int(input('\nEnter total number of strings : '))
for i in range(n):
    strings.append(input())

strings.sort( key=len)

print('Sorted Strings are : ', strings)