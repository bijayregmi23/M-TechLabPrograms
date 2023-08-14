print('Name : Bijay Regmi\nRegistration Number : 210913032\n')

pairs = []
temp=0
for num in range(100000,1000000):
    if str(num) == str(num)[::-1]:
        if(num-temp) <= 20:
            pairs.append((temp,num))
        temp = num

print(pairs)