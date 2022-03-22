print('Name : Bijay Regmi\nRegistration Number : 210913032\n')

def first_diff(s1,s2):
    n = len(s1) if len(s1) < len(s2) else len(s2)
    for i in range(n):
        if s1[i] != s2[i]:
            return i
    return -1

s1 = input('Enter String 1 : ')
s2 = input('Enter String 2 : ')
value =  first_diff(s1, s2)
if value == -1:
    print("String are equal. Value returned is ",value)
else:
    print("String are Unequal. Value returned is ",value)