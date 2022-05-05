name_pass={"harish":"hari@2002","raghu":"r123@ghu","shri":"shri@98","ritesh":"ritz@2001","karthik":"kar@904","rajaht":"rajath@1223","ashwin":"ash@1998","manisha":"manisha@1289","aditya":"desai@1992","anusha":"anusha@2002"}

login_name = str(input("Enter your username.\n"))
login_pass = str(input("Enter your password.\n"))
if login_name in name_pass.keys():
    print("correct username.")
    if login_pass == name_pass[login_name]:
        print("Correct password")
        print ("Logged in...!")
    else:
        print("Wrong password cannot login...")
else:
    print("Wrong username cannot login...")
