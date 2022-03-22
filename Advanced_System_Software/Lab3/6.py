with open('6Input.txt') as inputFile:
    with open('6Output.txt', 'w') as outputFile:
        inputLine = inputFile.read()
        while 1:
            begin = inputLine.find('/*')
            end = inputLine.find('*/')
            if begin == -1 or end == -1:
                break
            end = end + 2
            inputLine = inputLine[:begin] + inputLine[end:]

        while 1:
            begin = inputLine.find('//')
            end = inputLine[begin:].find('\n')
            print(begin,end)
            if begin == -1 or end == -1:
                break
            end = begin + end + 2
            inputLine = inputLine[:begin] + inputLine[end:]
        
        outputFile.write(inputLine)

        
