print('Name : Bijay Regmi\nRegistration Number : 210913032\n')


n = int(input("Enter n : "))
print("Enter ",n*n," numbers : ")
a=[]
for i in range(n * n):
    a.append(int(input()))
        
b={}
for num in a:
    if num not in b.keys():
        b[num] = 1
    else:
        b[num] = b[num] + 1

print("Dictionary : ", b)

from collections import Counter
k = Counter(b)
high = k.most_common(3)
print("Three Most Common Numbers : ")
for key,value in high:
    print("Key :", key, "    Value :",value)