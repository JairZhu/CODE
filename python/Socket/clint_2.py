from socket import *
servername = '172.18.35.96'
serverport = 12000
clientsocket = socket(AF_INET, SOCK_STREAM)
clientsocket.connect((servername, serverport))
sentence = input("Input lowercase sentence:")
clientsocket.send(sentence.encode('utf-8'))
modifiedsentence = clientsocket.recv(1024)
print("From server:", modifiedsentence.decode('utf-8'))
clientsocket.close()