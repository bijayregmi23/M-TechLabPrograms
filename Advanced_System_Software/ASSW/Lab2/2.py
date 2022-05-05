print('Name : Bijay Regmi\nRegistration Number : 210913032\n')

test_string = input("Enter String : ")

# printing original string
print("Original String : " + str(test_string))

# using join() + sorted()
# Sorting a string
res = ''.join(sorted(test_string))

# print result
print("Sorted String : " + str(res))