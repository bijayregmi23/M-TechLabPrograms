file=open("student.txt",'r')
file2=open("student2.txt",'w')
l=[]
for i in file:
    r=i.split()
    file2.write(r[0].capitalize()+" "+r[1].capitalize()+" "+r[2]+" "+"301-"+r[3]+"\n")
file.close()
file2.close()
