#include <string>
using namespace std;

class Date
{
    int year, month, day;
public:
  Date(int y=0, int m=1, int d=1) {
      year = y;
      month = m;
      day = d;
  }
  static bool leapyear(int year1) {
      if (year1 % 100 == 0) return year1 % 400 == 0;
      else return year1 % 4 == 0;
  }
  int getYear() const {return year;}
  int getMonth() const {return month;}
  int getDay() const {return day;}
  bool operator==(Date p) {
      return year == p.year && month == p.month && day == p.day;  
  }
  bool operator!=(Date p) {
      return !(*this == p);
  } 
  bool operator<(Date p) {
	  if (year < p.year) return true;
	  else if (year > p.year) return false;
	  else if (month < p.month) return true;
	  else if (month > p.month) return false;
	  else if (day < p.day) return true;
	  else return false;
  }
  bool operator<=(Date p) {
	  return *this < p || *this == p;
  }
  bool operator>(Date p) {
	  return !(*this == p || *this < p);
  }
  bool operator>=(Date p) {
	  return *this > p || *this == p;
  }
  int & operator[](const string p) {
	  if (p == "year") return year;
	  else if (p == "month") return month;
	  else return day;
  }
  int month_to_day(int ye,int mon) {
	  if (!leapyear(ye)) {
		  switch (mon)
		  {
		  case 1: return 0;
		  case 2: return 31;
		  case 3: return 59;
		  case 4: return 90;
		  case 5: return 120;
		  case 6: return 151;
		  case 7: return 181;
		  case 8: return 212;
		  case 9: return 243;
		  case 10: return 273;
		  case 11: return 304;
		  case 12: return 334;
		  }

	  }
	  else {
		  switch (mon)
		  {
		  case 1: return 0;
		  case 2: return 31;
		  case 3: return 60;
		  case 4: return 91;
		  case 5: return 121;
		  case 6: return 152;
		  case 7: return 182;
		  case 8: return 213;
		  case 9: return 244;
		  case 10: return 274;
		  case 11: return 305;
		  case 12: return 335;
		  }
	  }
  }
  Date operator+(int d) {
	  if (d < 0) {
		  return *this - (-d);
	  }
	  int tmpy = year;
	  int tmpm = month;
	  int tmpd = day;
	  int day1 = month_to_day(tmpy, tmpm) + tmpd + d;
	  while (day1 >= 365) {
		  if (leapyear(tmpy)) {
			  day1 -= 366;
			  tmpy++;
		  }
		  else {
			  day1 -= 365;
			  tmpy++;
		  }
	  }
	  if (day1 == 0) day1 = 1;
	  if (!leapyear(tmpy)) {
		  if (day1 <= 31) {
			  tmpm = 1;
			  tmpd = day1;
		  }
		  else if (day1 <= 59) {
			  tmpm = 2;
			  tmpd = day1 - 31;
		  }
		  else if (day1 <= 90) {
			  tmpm = 3;
			  tmpd = day1 - 59;
		  }
		  else if (day1 <= 120) {
			  tmpm = 4;
			  tmpd = day1 - 90;
		  }
		  else if (day1 <= 151) {
			  tmpm = 5;
			  tmpd = day1 - 120;
		  }
		  else if (day1 <= 181) {
			  tmpm = 6;
			  tmpd = day1 - 151;
		  }
		  else if (day1 <= 212) {
			  tmpm = 7;
			  tmpd = day1 - 181;
		  }
		  else if (day1 <= 243) {
			  tmpm = 8;
			  tmpd = day1 - 212;
		  }
		  else if (day1 <= 273) {
			  tmpm = 9;
			  tmpd = day1 - 243;
		  }
		  else if (day1 <= 304) {
			  tmpm = 10;
			  tmpd = day1 - 273;
		  }
		  else if (day1 <= 334) {
			  tmpm = 11;
			  tmpd = day1 - 304;
		  }
		  else if (day1 <= 365) {
			  tmpm = 12;
			  tmpd = day1 - 334;
		  }
	  }
	  else {
		  if (day1 <= 31) {
			  tmpm = 1;
			  tmpd = day1;
		  }
		  else if (day1 <= 60) {
			  tmpm = 2;
			  tmpd = day1 - 31;
		  }
		  else if (day1 <= 91) {
			  tmpm = 3;
			  tmpd = day1 - 60;
		  }
		  else if (day1 <= 121) {
			  tmpm = 4;
			  tmpd = day1 - 91;
		  }
		  else if (day1 <= 152) {
			  tmpm = 5;
			  tmpd = day1 - 121;
		  }
		  else if (day1 <= 182) {
			  tmpm = 6;
			  tmpd = day1 - 152;
		  }
		  else if (day1 <= 213) {
			  tmpm = 7;
			  tmpd = day1 - 182;
		  }
		  else if (day1 <= 244) {
			  tmpm = 8;
			  tmpd = day1 - 213;
		  }
		  else if (day1 <= 274) {
			  tmpm = 9;
			  tmpd = day1 - 244;
		  }
		  else if (day1 <= 305) {
			  tmpm = 10;
			  tmpd = day1 - 274;
		  }
		  else if (day1 <= 335) {
			  tmpm = 11;
			  tmpd = day1 - 305;
		  }
		  else if (day1 <= 366) {
			  tmpm = 12;
			  tmpd = day1 - 335;
		  }
	  }
	  return Date(tmpy, tmpm, tmpd);
  }
  Date operator+=(int d) {
	  if (d < 0) return *this -= (-d);
	  int day1 = month_to_day(year, month) + day + d;
	  while (day1 >= 365) {
		  if (leapyear(year)) {
			  day1 -= 366;
			  year++;
		  }
		  else {
			  day1 -= 365;
			  year++;
		  }
	  }
	  if (day1 == 0) day1 = 1;
	  if (!leapyear(year)) {
		  if (day1 <= 31) {
			  month = 1;
			  day = day1;
		  }
		  else if (day1 <= 59) {
			  month = 2;
			  day = day1 - 31;
		  }
		  else if (day1 <= 90) {
			  month = 3;
			  day = day1 - 59;
		  }
		  else if (day1 <= 120) {
			  month = 4;
			  day = day1 - 90;
		  }
		  else if (day1 <= 151) {
			  month = 5;
			  day = day1 - 120;
		  }
		  else if (day1 <= 181) {
			  month = 6;
			  day = day1 - 151;
		  }
		  else if (day1 <= 212) {
			  month = 7;
			  day = day1 - 181;
		  }
		  else if (day1 <= 243) {
			  month = 8;
			  day = day1 - 212;
		  }
		  else if (day1 <= 273) {
			  month = 9;
			  day = day1 - 243;
		  }
		  else if (day1 <= 304) {
			  month = 10;
			  day = day1 - 273;
		  }
		  else if (day1 <= 334) {
			  month = 11;
			  day = day1 - 304;
		  }
		  else if (day1 <= 365) {
			  month = 12;
			  day = day1 - 334;
		  }
	  }
	  else {
		  if (day1 <= 31) {
			  month = 1;
			  day = day1;
		  }
		  else if (day1 <= 60) {
			  month = 2;
			  day = day1 - 31;
		  }
		  else if (day1 <= 91) {
			  month = 3;
			  day = day1 - 60;
		  }
		  else if (day1 <= 121) {
			  month = 4;
			  day = day1 - 91;
		  }
		  else if (day1 <= 152) {
			  month = 5;
			  day = day1 - 121;
		  }
		  else if (day1 <= 182) {
			  month = 6;
			  day = day1 - 152;
		  }
		  else if (day1 <= 213) {
			  month = 7;
			  day = day1 - 182;
		  }
		  else if (day1 <= 244) {
			  month = 8;
			  day = day1 - 213;
		  }
		  else if (day1 <= 274) {
			  month = 9;
			  day = day1 - 244;
		  }
		  else if (day1 <= 305) {
			  month = 10;
			  day = day1 - 274;
		  }
		  else if (day1 <= 335) {
			  month = 11;
			  day = day1 - 305;
		  }
		  else if (day1 <= 366) {
			  month = 12;
			  day = day1 - 335;
		  }
	  }
	  return *this;
  }
  Date operator-(int d) {
	  if (d < 0) return *this + (-d);
	  int tmpy = year;
	  int tmpm = month;
	  int tmpd = day;
	  if (tmpy == 0 && d == 1) {
		  return Date(-1, 12, 31);
	  }
	  int day1 = month_to_day(tmpy, tmpm) + tmpd - d;
	  if (leapyear(--tmpy)) day1 += 366;
	  else day1 += 365;
	  if (leapyear(--tmpy)) day1 += 366;
	  else day1 += 365;
	  while (day1 >= 365) {
		  if (leapyear(tmpy)) {
			  day1 -= 366;
			  tmpy++;
		  }
		  else {
			  day1 -= 365;
			  tmpy++;
		  }
	  }
	  if (day1 == 0) day1 = 1;
	  if (!leapyear(tmpy)) {
		  if (day1 <= 31) {
			  tmpm = 1;
			  tmpd = day1;
		  }
		  else if (day1 <= 59) {
			  tmpm = 2;
			  tmpd = day1 - 31;
		  }
		  else if (day1 <= 90) {
			  tmpm = 3;
			  tmpd = day1 - 59;
		  }
		  else if (day1 <= 120) {
			  tmpm = 4;
			  tmpd = day1 - 90;
		  }
		  else if (day1 <= 151) {
			  tmpm = 5;
			  tmpd = day1 - 120;
		  }
		  else if (day1 <= 181) {
			  tmpm = 6;
			  tmpd = day1 - 151;
		  }
		  else if (day1 <= 212) {
			  tmpm = 7;
			  tmpd = day1 - 181;
		  }
		  else if (day1 <= 243) {
			  tmpm = 8;
			  tmpd = day1 - 212;
		  }
		  else if (day1 <= 273) {
			  tmpm = 9;
			  tmpd = day1 - 243;
		  }
		  else if (day1 <= 304) {
			  tmpm = 10;
			  tmpd = day1 - 273;
		  }
		  else if (day1 <= 334) {
			  tmpm = 11;
			  tmpd = day1 - 304;
		  }
		  else if (day1 <= 365) {
			  tmpm = 12;
			  tmpd = day1 - 334;
		  }
	  }
	  else {
		  if (day1 <= 31) {
			  tmpm = 1;
			  tmpd = day1;
		  }
		  else if (day1 <= 60) {
			  tmpm = 2;
			  tmpd = day1 - 31;
		  }
		  else if (day1 <= 91) {
			  tmpm = 3;
			  tmpd = day1 - 60;
		  }
		  else if (day1 <= 121) {
			  tmpm = 4;
			  tmpd = day1 - 91;
		  }
		  else if (day1 <= 152) {
			  tmpm = 5;
			  tmpd = day1 - 121;
		  }
		  else if (day1 <= 182) {
			  tmpm = 6;
			  tmpd = day1 - 152;
		  }
		  else if (day1 <= 213) {
			  tmpm = 7;
			  tmpd = day1 - 182;
		  }
		  else if (day1 <= 244) {
			  tmpm = 8;
			  tmpd = day1 - 213;
		  }
		  else if (day1 <= 274) {
			  tmpm = 9;
			  tmpd = day1 - 244;
		  }
		  else if (day1 <= 305) {
			  tmpm = 10;
			  tmpd = day1 - 274;
		  }
		  else if (day1 <= 335) {
			  tmpm = 11;
			  tmpd = day1 - 305;
		  }
		  else if (day1 <= 366) {
			  tmpm = 12;
			  tmpd = day1 - 335;
		  }
	  }
	  return Date(tmpy, tmpm, tmpd);
  }
  Date operator-=(int d) {
	  if (d < 0) return *this += (-d);
	  int day1 = month_to_day(year, month) + day - d;
	  if (leapyear(--year)) day1 += 366;
	  else day1 += 365;
	  if (leapyear(--year)) day1 += 366;
	  else day1 += 365;
	  while (day1 >= 365) {
		  if (leapyear(year)) {
			  day1 -= 366;
			  year++;
		  }
		  else {
			  day1 -= 365;
			  year++;
		  }
	  }
	  if (day1 == 0) day1 = 1;
	  if (!leapyear(year)) {
		  if (day1 <= 31) {
			  month = 1;
			  day = day1;
		  }
		  else if (day1 <= 59) {
			  month = 2;
			  day = day1 - 31;
		  }
		  else if (day1 <= 90) {
			  month = 3;
			  day = day1 - 59;
		  }
		  else if (day1 <= 120) {
			  month = 4;
			  day = day1 - 90;
		  }
		  else if (day1 <= 151) {
			  month = 5;
			  day = day1 - 120;
		  }
		  else if (day1 <= 181) {
			  month = 6;
			  day = day1 - 151;
		  }
		  else if (day1 <= 212) {
			  month = 7;
			  day = day1 - 181;
		  }
		  else if (day1 <= 243) {
			  month = 8;
			  day = day1 - 212;
		  }
		  else if (day1 <= 273) {
			  month = 9;
			  day = day1 - 243;
		  }
		  else if (day1 <= 304) {
			  month = 10;
			  day = day1 - 273;
		  }
		  else if (day1 <= 334) {
			  month = 11;
			  day = day1 - 304;
		  }
		  else if (day1 <= 365) {
			  month = 12;
			  day = day1 - 334;
		  }
	  }
	  else {
		  if (day1 <= 31) {
			  month = 1;
			  day = day1;
		  }
		  else if (day1 <= 60) {
			  month = 2;
			  day = day1 - 31;
		  }
		  else if (day1 <= 91) {
			  month = 3;
			  day = day1 - 60;
		  }
		  else if (day1 <= 121) {
			  month = 4;
			  day = day1 - 91;
		  }
		  else if (day1 <= 152) {
			  month = 5;
			  day = day1 - 121;
		  }
		  else if (day1 <= 182) {
			  month = 6;
			  day = day1 - 152;
		  }
		  else if (day1 <= 213) {
			  month = 7;
			  day = day1 - 182;
		  }
		  else if (day1 <= 244) {
			  month = 8;
			  day = day1 - 213;
		  }
		  else if (day1 <= 274) {
			  month = 9;
			  day = day1 - 244;
		  }
		  else if (day1 <= 305) {
			  month = 10;
			  day = day1 - 274;
		  }
		  else if (day1 <= 335) {
			  month = 11;
			  day = day1 - 305;
		  }
		  else if (day1 <= 366) {
			  month = 12;
			  day = day1 - 335;
		  }
	  }
	  return *this;
  }

  Date & operator++()
  {
	  if (leapyear(year)) {
		  if (month == 2) {
			  if (day == 29) {
				  day = 1;
				  month = 3;
			  }
			  else {
				  day++;
			  }
		  }
		  else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) {
			  if (day == 31) {
				  day = 1;
				  ++month;
			  }
			  else {
				  ++day;
			  }
		  }
		  else if (month == 12) {
			  if (day == 31) {
				  day = 1;
				  month = 1;
				  ++year;
			  }
			  else {
				  ++day;
			  }
		  }
		  else {
			  if (day == 30) {
				  day = 1;
				  month++;
			  }
			  else {
				  ++day;
			  }
		  }
	  }
	  else {
		  if (month == 2) {
			  if (day == 28) {
				  day = 1;
				  month = 3;
			  }
			  else {
				  day++;
			  }
		  }
		  else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) {
			  if (day == 31) {
				  day = 1;
				  ++month;
			  }
			  else {
				  ++day;
			  }
		  }
		  else if (month == 12) {
			  if (day == 31) {
				  day = 1;
				  month = 1;
				  ++year;
			  }
			  else {
				  ++day;
			  }
		  }
		  else {
			  if (day == 30) {
				  day = 1;
				  month++;
			  }
			  else {
				  ++day;
			  }
		  }
	  }
	  return *this;
	  // TODO: 在此处插入 return 语句
  }

  Date & operator++(int n)
  {
	  Date * tmp = new Date(year, month, day);
	  if (leapyear(year)) {
		  if (month == 2) {
			  if (day == 29) {
				  day = 1;
				  month = 3;
			  }
			  else {
				  day++;
			  }
		  }
		  else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) {
			  if (day == 31) {
				  day = 1;
				  ++month;
			  }
			  else {
				  ++day;
			  }
		  }
		  else if (month == 12) {
			  if (day == 31) {
				  day = 1;
				  month = 1;
				  ++year;
			  }
			  else {
				  ++day;
			  }
		  }
		  else {
			  if (day == 30) {
				  day = 1;
				  month++;
			  }
			  else {
				  ++day;
			  }
		  }
	  }
	  else {
		  if (month == 2) {
			  if (day == 28) {
				  day = 1;
				  month = 3;
			  }
			  else {
				  day++;
			  }
		  }
		  else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) {
			  if (day == 31) {
				  day = 1;
				  ++month;
			  }
			  else {
				  ++day;
			  }
		  }
		  else if (month == 12) {
			  if (day == 31) {
				  day = 1;
				  month = 1;
				  ++year;
			  }
			  else {
				  ++day;
			  }
		  }
		  else {
			  if (day == 30) {
				  day = 1;
				  month++;
			  }
			  else {
				  ++day;
			  }
		  }
	  }
	  return *tmp;
	  // TODO: 在此处插入 return 语句
  }

  Date & operator--()
  {
	  if (leapyear(year)) {
		  if (month == 3) {
			  if (day == 1) {
				  day = 29;
				  month = 2;
			  }
			  else {
				  --day;
			  }
		  }
		  else if (month == 1) {
			  if (day == 1) {
				  day = 31;
				  month = 12;
				  --year;
			  }
			  else {
				  --day;
			  }
		  }
		  else if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) {
			  if (day == 1) {
				  day = 31;
				  month--;
			  }
			  else {
				  --day;
			  }
		  }
		  else {
			  if (day == 1) {
				  day = 30;
				  --month;
			  }
			  else {
				  --day;
			  }
		  }
	  }
	  else {
		  if (month == 3) {
			  if (day == 1) {
				  day = 28;
				  month = 2;
			  }
			  else {
				  --day;
			  }
		  }
		  else if (month == 1) {
			  if (day == 1) {
				  day = 31;
				  month = 12;
				  --year;
			  }
			  else {
				  --day;
			  }
		  }
		  else if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) {
			  if (day == 1) {
				  day = 31;
				  month--;
			  }
			  else {
				  --day;
			  }
		  }
		  else {
			  if (day == 1) {
				  day = 30;
				  --month;
			  }
			  else {
				  --day;
			  }
		  }
	  }
	  return *this;
	  // TODO: 在此处插入 return 语句
  }

  Date & operator--(int n)
  {
	  Date * tmp = new Date(*this);
	  if (leapyear(year)) {
		  if (month == 3) {
			  if (day == 1) {
				  day = 29;
				  month = 2;
			  }
			  else {
				  --day;
			  }
		  }
		  else if (month == 1) {
			  if (day == 1) {
				  day = 31;
				  month = 12;
				  --year;
			  }
			  else {
				  --day;
			  }
		  }
		  else if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) {
			  if (day == 1) {
				  day = 31;
				  month--;
			  }
			  else {
				  --day;
			  }
		  }
		  else {
			  if (day == 1) {
				  day = 30;
				  --month;
			  }
			  else {
				  --day;
			  }
		  }
	  }
	  else {
		  if (month == 3) {
			  if (day == 1) {
				  day = 28;
				  month = 2;
			  }
			  else {
				  --day;
			  }
		  }
		  else if (month == 1) {
			  if (day == 1) {
				  day = 31;
				  month = 12;
				  --year;
			  }
			  else {
				  --day;
			  }
		  }
		  else if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) {
			  if (day == 1) {
				  day = 31;
				  month--;
			  }
			  else {
				  --day;
			  }
		  }
		  else {
			  if (day == 1) {
				  day = 30;
				  --month;
			  }
			  else {
				  --day;
			  }
		  }
	  }
	  return *tmp;
	  // TODO: 在此处插入 return 语句
  }
  // add any member you need here  
};