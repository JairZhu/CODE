from datetime import datetime
import socket 

server_address = ('localhost', 6789)
max_size = 4096

print('starting the server at', datetime.now())
print('waiting for a client to call.')
server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.bind(server_address)

data, client = server.recvfrom(max_size)

print('at', datetime.now(), client, 'said', data)
server.sendto(b'are you talking to me?', client)
server.close()