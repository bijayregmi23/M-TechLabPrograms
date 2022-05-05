print('Name : Bijay Regmi\nRegistration Number : 210913032\n')

dic = {
    'Path' : "2003",
    'walla' : "1809",
    'Portal' : "1912",
    'Express' : "2003",
    'Computer' : "9834",
    'Python' : "1990",
    'Mysql' : "2001",
    'c++' : "1996",
    'java' : "1998",
    'html' : "1999" 
    }

username = input("Enter Username : ")
if username in dic :
    password = input("Enter Password : ")
    if dic[username] == password :
        print ("You are now logged into the system.")
    else :
        print ("ERROR | Invalid Password.")
else :
    print ("ERROR | You are not valid user.")
print("\n\n")