from datetime import datetime
import socket 

address = ('localhost', 6789)
max_size = 1000

print('starting the server at', datetime.now())
print('waiting for a client to call.')
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(address)
server.listen(5)

client, addr = server.accept()
data = client.recv(max_size)

print('at', datetime.now(), client, 'said', data)
client.sendall(b'are you talking to me?')
client.close()
server.close()