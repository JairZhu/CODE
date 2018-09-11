from socket import *
serverport = 12000
serversocket = socket(AF_INET, SOCK_STREAM)
serversocket.bind(('172.18.35.96',serverport))
serversocket.listen(1)
print("The server is ready to receive")
while True:
    connectionsocket, addr = serversocket.accept()
    sentence = connectionsocket.recv(1024).decode('utf-8')
    capitalizedsentence = sentence.upper()
    connectionsocket.send(capitalizedsentence.encode('utf-8'))
    connectionsocket.close()