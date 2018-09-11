import sqlite3
cur = sqlite3.connect('books.db').cursor()
sql = "select * from book order by year"
for row in cur.execute(sql):
    print(row)

for row in cur.execute(sql):
    print(*row, sep = ', ')
