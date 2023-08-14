from socket import *

serverAddress = '127.0.0.1'
serverPort = 1111

serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind((serverAddress, serverPort))
serverSocket.listen(5)

print(serverAddress, "is listening at", serverPort)
print('-------------------------------------------------------------')

connectionSocket, addr = serverSocket.accept()
clientMessage = connectionSocket.recv(1024)
print("Client ", addr," : ", clientMessage.decode('utf-8'))
message = input("Your Message : ")
connectionSocket.send(message.encode('utf-8'))

connectionSocket.close()
serverSocket.close()