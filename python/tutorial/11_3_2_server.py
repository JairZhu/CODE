import zmq
from datetime import datetime

host = '127.0.0.1'
port = 6789
server = zmq.Context().socket(zmq.REP)
server.bind("tcp://%s:%s" % (host, port))
while True:
    request_bytes = server.recv()
    request_str = request_bytes.decode('utf-8')
    if request_str == 'time':
        server.send(datetime.now().isoformat().encode('utf-8'))
    else:
        server.send(bytes("invalid command", 'utf-8'))