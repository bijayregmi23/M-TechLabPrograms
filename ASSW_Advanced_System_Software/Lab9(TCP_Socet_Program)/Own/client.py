import socket			
from datetime import date
s = socket.socket()		
port = 12345			
s.connect(('127.0.0.1', port))
print ("\n",s.recv(1024).decode())
print ("\n",s.recv(1025).decode())
s.close()