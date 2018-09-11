import sqlite3
con = sqlite3.connect('books.db')
cur = con.cursor()
string = 'select title from book order by title asc'

for row in cur.execute(string):
    print(row)

for row in cur.execute(string):
    print(row[0])

sql = """select title from book order by case when (title like "The %") then substr(title, 5) else title end"""
for row in cur.execute(sql):
    print(row[0])