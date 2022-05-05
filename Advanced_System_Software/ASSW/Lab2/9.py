print('Name : Bijay Regmi\nRegistration Number : 210913032\n')

num = input("Enter number : ")

print("Digital Root of", num, "is : ", end='')
while len(num) > 1:
    num = str(sum([int(i) for i in [j for j in num]]))

print(num,"\n\n")