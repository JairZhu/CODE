import zmq

host = '127.0.0.1'
port = 6789
context = zmq.Context()
server = context.socket(zmq.REP)
server.bind("tcp://%s:%s" % (host, port))
while True:
    request_bytes = server.recv()
    requset_str = request_bytes.decode('utf-8')
    print("that voice in my head says: %s" % requset_str)
    reply_str = "stop saying: %s" % requset_str
    reply_bytes = bytes(reply_str, 'utf-8')
    server.send(reply_bytes)