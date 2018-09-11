import csv
import sqlite3
db = sqlite3.connect('books.db')
curs = db.cursor()
ins = 'insert into book values(?,?,?)'
with open('article.csv', 'rt') as fin:
    books = csv.DictReader(fin)
    for row in books:
        curs.execute(ins, (row['title'], row['author'], row['year']))
db.commit()