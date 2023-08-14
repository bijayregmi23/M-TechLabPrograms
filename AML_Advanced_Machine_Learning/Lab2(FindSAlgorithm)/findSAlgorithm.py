import csv


a = []
with open('enjoy_sport.csv') as f:
  for row in csv.reader(f):
    a.append(row)
  for i in a:
    print(i)
print("\nThe total number of training instances are :",len(a))

num_attribute = len(a[0])-1

print("\nThe initial hypothesis is : ")
hypothesis = ['0']*num_attribute
print(hypothesis)

for i in range(0,len(a)):
  if a[i][num_attribute] == 'yes':
    for j in range(0,num_attribute):
      if hypothesis[j] == '0' or hypothesis[j] == a[i][j]:
        hypothesis[j] = a[i][j]
      else:
        hypothesis[j] = '?'
    print("\nThe hypothesis for training instance {} is : ".format(i), hypothesis)

print("\nThe Maximally specific hypothesis for training instanc is : ")
print(hypothesis)