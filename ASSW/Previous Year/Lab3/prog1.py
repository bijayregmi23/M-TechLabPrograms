class investment:
    def __init__(self,p,i):
        self.principal = p
        self.interest = i
    def value_after(self,n):
        value = self.principal*((1+self.interest)**n)
        return value
    def __str__(self):
        return 'Principal - ${self.principal}, Interest rate - {self.interest}%'.format(self=self)

ob1 = investment(1000.00,5.12)
print(ob1)
print(f"The value after 5 years is {ob1.value_after(5)}")
