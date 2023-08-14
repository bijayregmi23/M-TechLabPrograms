para = input("Enter a paragraph: ")
k1 = 0
k2 = 0
k3 = 0
words = para.split()
for i in words:
  if(i=='a'):
    k1=k1+1
  elif(i=='an'):
    k2=k2+1
  elif(i=='the'):
    k3=k3+1
print("Occurrences of the words a,an and the are respectively:")
print(k1,k2,k3)
print('total article in the paragraph are ',k1+k2+k3)