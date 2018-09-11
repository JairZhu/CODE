from datetime import date, timedelta
birthday = date(1997, 12, 25)
print(birthday)
print(birthday.isoweekday())
print(birthday + timedelta(days=10000))