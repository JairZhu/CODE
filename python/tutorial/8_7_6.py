import sqlite3
import csv
con = sqlite3.connect('books.db')
cur = con.cursor()
cur.execute("""create table book (title text, author text, year int)""")
con.commit()