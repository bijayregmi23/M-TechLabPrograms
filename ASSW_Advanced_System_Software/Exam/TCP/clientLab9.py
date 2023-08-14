from socket import *
import json

serverAddress = 'localhost'
serverPort = 1111

clientSocket = socket(AF_INET,SOCK_STREAM)
clientSocket.connect((serverAddress, serverPort))

message = input("Your Message : ")
clientSocket.send(message.encode('utf-8'))

response = clientSocket.recv(1024).decode('utf-8')
data = json.loads(response) ###
print("SERVER (", serverAddress, ') : \n\n',data['os'])

clientSocket.close()