#include"Date.h"
bool Date::CheckDate()
{
	if (_month < 1 || _month > 12
		|| _day < 1 || _day > GetMonthDay(_year, _month))
	{
		return false;
	}
	else
	{
		return true;
	}
}
Date::Date(int year , int month , int day )
{
	_year = year;
	_month = month;
	_day = day;
	if (!CheckDate())
	{
		cout << "日期非法：" << *this << endl;
	}
}
bool Date::operator<(const Date& d) const
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year&&_month < d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day < d._day)
	{
		return true;
	}
	return false;
}
bool Date::operator<=(const Date& d) const
{
	return *this < d || *this == d;
}
bool Date::operator>(const Date& d) const
{
	return  !(*this <= d);
}
bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}
bool Date::operator==(const Date& d) const
{
	return _year == d._year &&
			_month == d._month &&
			_day == d._day;
}
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

//特殊：天数为负数
// d1 += 天数
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= -day;
	}
	_day += day;
	while (_day > GetMonthDay(_year,_month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
Date Date::operator+(int day) const
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}
// d1 -= 天数
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day < 0)
	{
		_day += GetMonthDay(_year, _month);
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
	}
	return *this;
}
Date Date::operator-(int day) const
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}
// d1 - d2
int Date::operator-(const Date& d) const
{
	Date mind = *this;
	Date maxd = d;
	int count = 0;
	if (mind > maxd)
	{
		mind = d;
		maxd = *this;
	}
	while (mind != maxd)
	{
		mind += 1;
		count++;
	}
	return count;
}
// ++d1 -> d1.operator++()
Date& Date::operator++()
{
	return *this+=1;
}
// d1++ -> d1.operator++(0)
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}
Date& Date::operator--()
{
	return *this -= 1;
}
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
//cout<<d1;
//友元函数
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << " " << d._month << " " << d._day << endl;
	return out;
}
//cin>>d;
istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}