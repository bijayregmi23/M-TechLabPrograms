with open('7Input.txt') as inputFile:
    with open('7Output.txt', 'w') as outputFile:
        lines = inputFile.readlines()
        for i in range(len(lines)):
            if i!=len(lines)-1:
                lines[i] = ' '.join(lines[i].split()) + '\n'
            else:
                lines[i] = ' '.join(lines[i].split())
        outputFile.writelines(lines)