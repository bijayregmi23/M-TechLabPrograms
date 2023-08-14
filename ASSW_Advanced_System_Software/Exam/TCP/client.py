from socket import *

serverAddress = 'localhost'
serverPort = 1111

clientSocket = socket(AF_INET,SOCK_STREAM)
clientSocket.connect((serverAddress, serverPort))

message = input("Your Message : ")
clientSocket.send(message.encode('utf-8'))

response = clientSocket.recv(1024)
print("Server (", serverAddress, ') : ',response.decode('utf-8'))

clientSocket.close()