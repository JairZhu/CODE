from datetime import date
fmt = "%Y %m %d"
now = date.today()
string = now.strftime(fmt)
with open('today.txt', 'wt') as fout:
    fout.write(string)
