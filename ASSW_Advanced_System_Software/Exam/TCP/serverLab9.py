from socket import *
import time
import os
import json

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
data = {
    "date" : time.ctime(),
    "os" : os.name,
    "current_directory" : os.listdir()
}
message = json.dumps(data) #######
connectionSocket.send(message.encode('utf-8'))

connectionSocket.close()
serverSocket.close()