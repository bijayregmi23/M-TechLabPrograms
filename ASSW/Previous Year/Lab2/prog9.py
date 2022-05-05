num = input("Ener the number")
num1 = num
while int(num)>9:
    sum = 0
    for digit in str(num):
        sum+=int(digit)
    num=sum
print(f"The digital root of the number {num1} is {sum}")
