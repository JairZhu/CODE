import requests

resp = requests.get('http://localhost:9999/echo/Mothra')
if resp.status_code == 200 and resp.text == 'Say hello to my little friend: Mothra!':
    print('It worked!')
else:
    print('Argh, got this:', resp.text)