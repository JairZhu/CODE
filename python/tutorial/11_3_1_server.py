from datetime import datetime
import socket

server_address = ("localhost", 6789)
max_size = 4069

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.bind(server_address)

data, client = server.recvfrom(max_size)

if data.decode('utf-8') == "time":
    server.sendto(datetime.now().isoformat().encode('utf-8'), client)
    server.close()
else:
    server.sendto(b'invalid command', client)
    server.close()