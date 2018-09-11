import zmq

host = '127.0.0.1'
port = 6789
client = zmq.Context().socket(zmq.REQ)
client.connect("tcp://%s:%s" % (host, port))
string = input("command: ")
client.send(string.encode('utf-8'))
print(client.recv().decode('utf-8'))