from socket import *

serverAddress = 'localhost'
serverPort = 1111
clientSock = socket(AF_INET, SOCK_DGRAM)

message = input("Your Message : ")
clientSock.sendto(message.encode('utf-8'), (serverAddress, serverPort))

response , addr = clientSock.recvfrom(1024)
print("Server", addr,":",response.decode('utf-8'))

clientSock.close()