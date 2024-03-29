from socket import *
import datetime
serverName = input('Enter server hostname or IP: ')
serverPort = int(input('Enter server port: '))
sentence = input('Enter your message: ')
#AF_INET is for IPv4 - SOCK_STREAM is for TCP
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName,serverPort))
clientSocket.send(sentence.encode('utf_8'))
print('<-- message sent to server', \
      clientSocket.getpeername()[0], \
      ":", \
      clientSocket.getpeername()[1], \
      'on', datetime.datetime.now())
numOfCharacters = clientSocket.recv(1024)
print('--> message recieved from server', \
      clientSocket.getpeername()[0], \
      ":", \
      clientSocket.getpeername()[1], \
      'on', datetime.datetime.now())
print('-----------------------------------------------------')
print('The count of characters in your message is:', len(numOfCharacters.decode('utf_8')))#receive.decode('utf_8')
print('-----------------------------------------------------')
clientSocket.close()
print('TCP connection with server is closed')
