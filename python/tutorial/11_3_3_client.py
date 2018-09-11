import xmlrpc.client
proxy = xmlrpc.client.ServerProxy("http://localhost:7777")
string = input("command: ")
if string == 'time':
    print(proxy.time())
else:
    print('invalid command')