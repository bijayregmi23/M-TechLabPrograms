class Password_manager:
    old_passwords=[]
    def get_password(self):
        return self.old_passwords[-1]
    def set_password(self,password):
        for i in self.old_passwords:
            if i==password:
                print("{} is an old password".format(password))
                return 1
        self.old_passwords.append(password)
        print("{} has been appended to the list of all passwords".format(password))
    def is_correct(self,password):
        if password==self.get_password():
            return True
        else:
            return False
print()
password=Password_manager()
password.set_password("Amazing")
password.set_password("Amaze")
password.set_password("Apple")
password.set_password("Ball")
password.set_password("Cat")
password.set_password("Dog")
password.set_password("Ball")

print("\nThe latest password is : ",password.get_password())
print("\nThe set of all old passwords are : ",password.old_passwords)