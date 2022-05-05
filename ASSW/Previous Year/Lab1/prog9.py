list=[8,9,10]
print("Orignal List: ",list)
list[1]=17
print("List after modifing index 1: ",list)
list.extend([4,5,6])
print("List after appending 4,5 and 6: ",list)
list.pop(0)
print("List after removing first element: ",list)
list.sort()
print("List after sorting:",list)
list=list*2
print("List after doubling:",list)
list.insert(3, 25) 
print("After inserting 25:",list)
