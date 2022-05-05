print('Name : Bijay Regmi\nRegistration Number : 210913032\n')

with open("6.txt") as f:
    namesInFile = f.read()
names = namesInFile.split(', ')

key = input("Enter Initials : ")
for name in names:
    initial = ''
    temp = name.upper().split(' ')
    initial = temp[0][0] + temp[-1][0]
    if initial == key:
        print(name)