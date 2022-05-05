import re
text = input("Enter the text")
text = re.sub('abc','*',text)
#print(text)
def romanToInt(rom):
	value = {
		'M': 1000,
		'D': 500,
		'C': 100,
		'L': 50,
		'X': 10,
		'V': 5,
		'I': 1
	}

	# Initialize previous character and answer
	p = 0
	ans = 0

	# Traverse through all characters
	n = len(rom)
	for i in range(n-1, -1, -1):

		# If greater than or equal to previous,
		# add to answer
		if value[rom[i]] >= p:
			ans += value[rom[i]]

		# If smaller than previous
		else:
			ans -= value[rom[i]]

		# Update previous
		p = value[rom[i]]

	return ans

split_words = text.split(' ')
patt = r'[MDCLXVI]+$'
r = re.compile(patt)
roman_numeral = list(filter(r.match, split_words))
#print(roman_numeral)
for x in roman_numeral:
    text = re.sub(x,str(romanToInt(x)),text)
#print(text)

patt = "[bh][aiu]t"

print("Recognized strings are : ")
print(re.findall(patt,text))

caps = re.findall("[A-Z][a-z]",text)
for x in caps:
    replace = x.lower()
    text = re.sub(x,replace,text)    
print("Modified text is : ")
print(text)
