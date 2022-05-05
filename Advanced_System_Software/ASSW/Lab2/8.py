print('Name : Bijay Regmi\nRegistration Number : 210913032\n')

noOfElements = int(input("Enter total number of elements in L : "))
print("Enter elements of L : ")
L = []
for i in range(noOfElements):
    L.append(int(input()))

n = int(input("Enter n : "))

print("\nMaximum element is : ",max([num for num in L if num<n]))