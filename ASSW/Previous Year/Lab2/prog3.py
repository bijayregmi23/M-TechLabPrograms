import random
import itertools
import operator
five_dim = [[random.randint(1,5) for b in range(0,5)]for a in range(0,5)]
flat_list = [num for num in itertools.chain(*five_dim)]
key_set = set(flat_list)
freq_dict ={k: flat_list.count(k) for k in key_set}
x= sorted(freq_dict.items(), key = operator.itemgetter(1))[-3:]
print(f"The 5*5 list list is {five_dim}")
print(f"The dictionary is {freq_dict}")
print("The three most common numbers are : ")
for i in x:
    print(i[0])
