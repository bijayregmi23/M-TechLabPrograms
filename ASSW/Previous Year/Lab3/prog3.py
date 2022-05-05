class Wordplay:
    def __init__(self,words):
        self.words = words
    def words_with_length(self,n):
        return_list = []
        for i in self.words:
            if len(i)==n:
                return_list.append(i)
        return return_list
    def starts_with(self,s):
        return_list = []
        for i in self.words:
          if i[0]==str(s):
              return_list.append(i)
        return return_list
    def ends_with(self,s):
        return_list = []
        for i in self.words:
            if i[-1]==str(s):
                return_list.append(i)
        return return_list
    def palindromes(self):
        return_list = []
        for i in self.words:
            if i == i[::-1]:
                return_list.append(i)
        return return_list

    def only(self,L):
        return_list = []
        for i in self.words:
            match = True
            for j in i:
                if j not in L:
                    match = False
                    break
            if match==True:
                return_list.append(i)
        return return_list
    def avoids(self,L):
        return_list = []
        for i in self.words:
            match = True
            for j in i:
                if j in L:
                    match = False
                    break
            if match==True:
                return_list.append(i)
        return return_list
words = ['apple','ball','cat','dog','owl','bat','tat','pip']
ob1 = Wordplay(words)
print(f"Chosen words are : {words}")
print(f"The words with length 3 are : {ob1.words_with_length(3)}")
print(f"The words that start with 'b' are : {ob1.starts_with('b')}")
print(f"The words that ends with 't' are : {ob1.starts_with('t')}")
print(f"The words which are palindromes are : {ob1.palindromes()}")
print(f" The words which contains only the letters in ['t','a'] are : {ob1.only(['t','a'])}")
print(f"The words which contains none of the letters in ['p','b','w'] are : {ob1.avoids(['p','b','w'])}")
            
