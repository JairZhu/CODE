import redis
con = redis.Redis()
con.delete('test')
con.hmset('test',{'count': '1', 'name': 'Fester Bestertester'})
con.hgetall('song')