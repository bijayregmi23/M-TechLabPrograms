def first_diff(s1,s2):
    if s1==s2:
        return -1
    else:
        l1 = len(s1)
        l2 = len(s2)
        for i in range(min(l1,l2)):
            if s1[i]!=s2[i]:
                return(i)
location = first_diff('Rajat','Rajeev')
if location==-1:
    print("The two strings are same")
else:
    print(f"The two strings first differ in the location {location}")
