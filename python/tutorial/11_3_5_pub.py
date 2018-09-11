import zmq
import string
from time import sleep

host = '127.0.0.1'
port = 6789
pub = zmq.Context().socket(zmq.PUB)
pub.bind("tcp://%s:%s" % (host, port))
sleep(1)

with open('mammoth.txt', 'rt') as poem:
    words = poem.read()
for word in words.split():
    word = word.strip(string.punctuation)
    data = word.encode('utf-8')
    if word.startswith(('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')):
        pub.send_multipart([b'vowels', data])
    if len(word) == 5:
        pub.send_multipart([b'five', data])