import socket
import datetime			
from datetime import date
import os
import platform

s =socket.socket()		
print ("Socket successfully created")
port = 12345			
s.bind(('', port))		
print ("socket binded to %s" %(port))


s.listen(5)	
print ("socket is listening")		
today = date.today()
dt = datetime.datetime.now()
date_str = dt.ctime()
os_name = os.name
platfrom = platform.system()
dir_cur = os.getcwd()

while True:
    c, addr = s.accept()	
    print ('Got connection from', addr )
    c.send(today.strftime("%d/%m/%Y").encode())
    c.send(date_str.encode())
    c.send(os_name.encode())
    c.send(platfrom.encode())
    c.send(dir_cur.encode())
    c.close()
    break
