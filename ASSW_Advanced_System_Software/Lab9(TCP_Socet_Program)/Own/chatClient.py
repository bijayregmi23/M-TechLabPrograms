from socket import *
server_name = 'localhost'
server_port = 9999
client_socket = socket(AF_INET, SOCK_STREAM)
client_socket.connect((server_name,server_port))

while True:
    sentence = input(">> Your Message : ")
    client_socket.send(sentence.encode())
    message = client_socket.recv(2048)
    print (">> Server : ", message.decode())
    if(sentence == 'q'):
        client_socket.close()
