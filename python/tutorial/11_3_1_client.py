import socket

server_address = ("localhost", 6789)
max_size = 4069

client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
string = input("command: ")
client.sendto(string.encode('utf-8') , server_address)
data, server = client.recvfrom(max_size)
print(data.decode('utf-8'))
client.close()