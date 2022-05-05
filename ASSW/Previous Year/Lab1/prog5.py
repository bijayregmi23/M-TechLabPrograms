n = int(input("Enter the number of fibonacci numbers to print"))
f1 = 1
f2 = 1
if n==1:
    print(f1)
elif n==2:
    print(f1)
    print(f2)
elif n>2:
    print(f1)
    print(f2)
    for i in range(2,n):
        f3 = f1 + f2
        print(f3)
        f1 = f2
        f2 = f3
else:
    print("Please enter the valid number")
