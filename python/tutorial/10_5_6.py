import multiprocessing
import os
import time
import random
from datetime import datetime
def emmm(sec):
    time.sleep(sec)
    print("wait %s seconds, now it's %s" % (sec, datetime.utcnow()))

if __name__ == '__main__':
    for n in range(3):
        sec = random.randrange(5)
        p = multiprocessing.Process(target=emmm(sec), args=(sec,))
        p.start()