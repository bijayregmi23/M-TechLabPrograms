class Solution(object):

    def romanToInt(self, s):
        roman = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000,}

        i = 1
        num = 0
        start = 0
        while i < len(s):
            if roman[s[i-1]] < roman[s[i]]:
                num = num + roman[s[i]] - roman[s[i-1]]
            elif roman[s[i-1]] == roman[s[i]]:
                if i-1 == 0:
                    num += roman[s[i]]
                num += roman[s[i]]
            elif roman[s[i-1]] > roman[s[i]]:
                if(i == len(s)-1):
                    num += roman[s[i]]
                else:
                    if roman[s[i]] >= roman[s[i+1]]:
                        num += roman[s[i]]
            # print(num)
            i+=1
        return num

ob1 = Solution()
print(ob1.romanToInt("III"))
print(ob1.romanToInt("CDXLIII"))