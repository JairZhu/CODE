with open('today.txt', 'rt') as fin:
    today_string = fin.read()
import time
fmt = '%Y %m %d'
tmp = time.strptime(today_string, fmt)
print(tmp)