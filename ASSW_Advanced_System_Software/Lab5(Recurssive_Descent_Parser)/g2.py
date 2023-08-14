ptr = 0
ip = input("Enter Input String : ") + '$'
input_str = ip


def U():
    global ip
    global ptr
    if ip[ptr] == '(':
        ptr += 1
        S()
        if ip[ptr] == ')':
            ptr += 1
            return
        # CHECKING IF IT IS NOT ENDING WITH )
        else:
            print("\n",input_str," is NOT VALID String ", sep = '')
            exit(0)

            # if ip[ptr] == '$':
                # ip = ip[:ptr]+'@'+'$'
                
    elif ip[ptr] == 'a':
        ptr += 1
        S()
        if ip[ptr] == 'b':
            ptr += 1
        # CHECKING IF IT IS NOT ENDING WITH b
        else:
            print("\n",input_str," is NOT VALID String ", sep = '')
            exit(0)
    elif ip[ptr] == 'd':
        ptr += 1
    else:
        print("\n",input_str," is NOT VALID String ", sep = '')
        exit(0)   

def V():
    global ip
    global ptr
    if ip[ptr] == 'a':
        ptr += 1
        V()
    else:
        return

def W():
    global ip
    global ptr
    if ip[ptr] == 'c':
        ptr += 1
        W()
    else:
        return

def S():
    U()
    V()
    W()
    return

if __name__ == '__main__':
    S()
    if ip[ptr] == '$':
        print("\n",input_str," is VALID String ", sep = '')
    else:
        print("\n",input_str," is NOT VALID String ", sep = '')
