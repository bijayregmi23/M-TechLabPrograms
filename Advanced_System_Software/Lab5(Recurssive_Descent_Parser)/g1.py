ptr = 0
ip = input("Enter Input String : ") + '$'
input_str = ip

def U():
    global ip
    global ptr
    if ip[ptr] == ',':
        ptr += 1
        S()
        U()
    else:
        return

def T():
    S()
    U()

def S():
    global ip
    global ptr
    if ip[ptr] == 'a':
        ptr += 1
    elif ip[ptr] == '>':
        ptr += 1
    elif ip[ptr] == '(':
        ptr += 1
        T()
        if ip[ptr] == ')':
            ptr += 1
        # CHECKING IF IT IS NOT ENDING WITH ) AND ENDING WITH $
        else:
            if ip[ptr] == '$':
                ip = ip[:ptr]+'@'+'$'

if __name__ == '__main__':
    S()
    if ip[ptr] == '$':
        print("\n",input_str," is VALID String ", sep = '')
    else:
        print("\n",input_str," is NOT VALID String ", sep = '')