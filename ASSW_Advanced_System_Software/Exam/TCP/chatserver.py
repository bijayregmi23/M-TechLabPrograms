from socket import *

serverAddress = 'localhost'
serverPort = 1111
serversocket = socket(AF_INET, SOCK_STREAM)
serversocket.bind((serverAddress, serverPort))
serversocket.listen(1)
print(serverAddress, "is listening at", serverPort)
print('-------------------------------------------------------------')

connectionSocket , addr = serversocket.accept()
print("Client",addr,"is connected !")

message = ''
while message != 'q':
    clientMessage = connectionSocket.recv(1024)
    print("Client", addr, ":",clientMessage.decode('utf-8'))
    message = input('Your Message : ')
    if message == 'q':
        break
    connectionSocket.send(message.encode('utf-8'))

connectionSocket.close()
serversocket.close()