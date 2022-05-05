class Password_manager:
    def __init__(self,old) -> None:
        self.old=old
 
    def getPassword(self):
        return self.old[len(self.old)-1]
 
    def setPassword(self, newPw):
        if newPw not in self.old:
            newPw=input("enter a new password: ")
            self.old.append(newPw)
            print(self.old[len(self.old)-1])
        else:
            print("correct password")
 
    def is_correct(self,curPw):
        if curPw == self.old[len(self.old)-1]:
            return True
        return False
        
old_passwords=['abc123','abc*123','abc@123','def123','def*123'] #last password is current password
 
ob1=Password_manager(old_passwords)
 
#print(ob1.getPassword())
 
newPass=input("enter the password: ")
ob1.setPassword(newPass)
 
curPass=input("enter current password: ")
print(ob1.is_correct(curPass))
