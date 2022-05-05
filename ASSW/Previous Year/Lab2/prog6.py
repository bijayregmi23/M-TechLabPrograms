with open("namelist.txt") as n:
    s = n.readlines()
lines = [line.strip() for line in s]
str_data = [line.split(" ") for line in lines]
Init = (input("Enter User Initial: "))
initial = list(Init)

for list in str_data:
    if len(initial)>=2:
        if len(list)==3:
            if initial[0] == list[0][:1] and initial[1] == list[1][:1] or initial[1] == list[2][:1]:
                print(list)
        elif len(list)==2:
            if initial[0] == list[0][:1] and initial[1] == list[1][:1]:
                print(list)
    else :
        print("Enter either two or three initials")
        break
