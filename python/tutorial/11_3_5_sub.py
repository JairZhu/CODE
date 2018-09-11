import string
import zmq

host = '127.0.0.1'
port = 6789
sub = zmq.Context().socket(zmq.SUB)
sub.connect("tcp://%s:%s" % (host, port))
sub.setsockopt(zmq.SUBSCRIBE, b'vowels')
sub.setsockopt(zmq.SUBSCRIBE, b'five')
while True:
    topic, word = sub.recv_multipart()
    print(topic, word)