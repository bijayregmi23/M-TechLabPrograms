nStudents = 0
nProfs = 0
a=int(input('Enter total number of emails : '))
for i in range(a):
  b=input('Enter Email : ')
  if b.endswith('@student.college.edu'):
    nStudents += 1
  elif b.endswith('@prof.college.edu'):
    nProfs += 1
print('Number of students :',nStudents,'\nNumber of professors :',nProfs)