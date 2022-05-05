import re
  

regex = '^[A-Za-z_][A-Za-z0-9_]*'

def check(string): 
  
    if(re.search(regex, string)): 
        print("Valid Identifier") 
          
    else: 
        print("Invalid Identifier") 

if __name__ == '__main__' : 
      

    string = input("Enter String : ")
      
    check(string)
  

