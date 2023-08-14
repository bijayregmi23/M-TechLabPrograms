from socket import *

serverAddress = 'localhost'
serverPort = 1111
serverSock = socket(AF_INET, SOCK_DGRAM)
serverSock.bind((serverAddress, serverPort))
print(serverAddress, "is listening at", serverPort)
print('-------------------------------------------------------------')

clientMessage , clientAddress = serverSock.recvfrom(1024)
print("Client", clientAddress, ":", clientMessage.decode('utf-8'))

message = input("Your Message : ")
serverSock.sendto(message.encode('utf-8'), clientAddress)

serverSock.close()