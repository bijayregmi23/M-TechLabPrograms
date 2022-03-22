class Wordplay:
    words=[]

    def __init__(self,words):
        self.words=words

    def words_with_length(self,length):
        p=[]
        for i in self.words:
            if len(i)==length:
                p.append(i)
        return p
    def starts_with(self,s):
        p=[]
        for i in self.words:
            if i[0]==s:
                p.append(i)
        return p
    def ends_with(self,s):
        p=[]
        for i in self.words:
            if i[-1]==s:
                p.append(i)
        return p
    def palindromes(self):
        p=[]
        for i in self.words:
            if i==i[::-1]:
                p.append(i)
        return p
    def only(self,L):
        p=[]
        for i in self.words:
            a=0
            for j in range(0,len(i)):
                if i[j]!=L:
                    a=1
                    break
                if a==0:
                    p.append(i)
        return p
    def avoids(self, L):
        p=[]
        for i in self.words:
            a=0
            for j in range(0,len(i)):
                if i[j]==L:
                    a=1
                    break
            if a==0:
                p.append(i)
        return p


play1 = Wordplay(["Apple","Ball","Bob","shell","Geek","Train","sell",'lllll'])
print("\nThe words with length 5 are",play1.words_with_length(5))
print("\n\nThe words that start with s are",play1.starts_with("s"))
print("The words that end with k are",play1.ends_with("k"))
print("The words containing only l are ",play1.only('l'))
print("The words avoiding l are ",play1.avoids('l'),"\n\n")
