pali=[]

def isPalindrome(s):
    return s == s[::-1]
 
 
# Driver code
for i in range(100000,1000000):
    ans = isPalindrome(str(i))
 
    if ans:
       pali.append(int(i))
    else:
        pass
    

for i in range(0,len(pali)):
    
    j=i+1
    while(j!=len(pali)):
        if(pali[j]!=pali[i]):
            if (pali[j] -pali[i] < 20) :
                    
                    print(pali[i],pali[j])
        j+=1
