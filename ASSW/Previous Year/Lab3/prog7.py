fin = open("input.txt", "rt")
fout = open("output.txt", "wt")
for line in fin:
	fout.write(' '.join(line.split()))	
fin.close()
fout.close()
