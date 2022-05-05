n = int(input("Enter the number of email addresses to be entered : "))
print(f"Enter {n} email addresses : ")
email = input()
email_list = email.split(" ")
count = 0
for x in email_list:
    if 'prof' in x:
        count=count+1
if count>0:
    print(f"There are {count} professor email addresses")
else:
    print("All email addresses are student email addresses")
