class Investment:
    def __init__(self, principal, rate):
        self.principal = principal
        self.rate = rate

    def __str__(self):
        return '\nPrincipal - '+str(self.principal)+', Interest Rate - '+str(self.rate)+'%'

    def value_after(self, n):
        return self.principal * pow(( 1 + self.rate),n)


p = float(input("Enter Principal : "))
r = float(input("Enter Rate : "))
i = Investment(p,r)

print(i.__str__())

n=float(input("\n\nEnter number of years : "))
print("Value after",n,"is",i.value_after(n))
