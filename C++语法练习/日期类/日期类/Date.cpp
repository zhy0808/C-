#include"Date.hpp"
Date::Date(int year, int month, int day)     //全缺省的构造函数，缺省参数在声明处。
{
	_year = year;
	_month = month;
	_day = day;
	if (year < 0 || month<0 || month>13 || day<0 || day>getMonthDay(year, month))
	{
		cout << year << "-" << month << "-" << day << " 日期错误!" << endl;
	}
}
int Date::getMonthDay(int year, int month)                          //返回某年某月对应多少天
{
	int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))//闰年2月28天
	{
		return 29;
	}
	return arr[month - 1];
}
Date::Date(const Date& d)        //拷贝构造函数，传引用是为了防止无限递归
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
bool Date::operator==(Date& d)   //“==”运算符重载
{
	return _year == d._year&&_month == d._month&&_day == d._day;
}

bool Date::operator!=(Date& d)  //“!=”运算符重载
{
	return _year != d._year || _month != d._month || _day != d._day;
}

bool Date::operator>(Date& d)   //“>”运算符重载
{
	if (_year > d._year)
		return 1;
	else if (_year == d._year)
	{
		if (_month > d._month)
			return 1;
		else if (_month == d._month)
		{
			if (_day > d._day)
				return 1;
			else
				return 0;
		}
		return 0;
	}
	else
		return 0;
}

bool Date::operator>=(Date& d)   //“>=”运算符重载
{
	return ((*this) > d || (*this) == d);      //这里直接函数复用，减少代码的冗余。
}

bool Date::operator<(Date& d)   //“<”运算符重载
{
	return !((*this) >= d);
}

bool Date::operator<=(Date& d)   //“<=”运算符重载
{
	return !((*this) > d);
}

Date& Date::operator+=(int n)   //“+=”运算符重载
{
	if (n < 0)
	{
		*this -= (-n);
		return *this;
	}
	_day += n;
	while (_day > getMonthDay(_year, _month))
	{
		_day -= getMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int n)   //“+”运算符重载,实现日期加天数
{
	Date ret(*this);
	ret += n;
	return ret;
}

Date& Date::operator-=(int n)   //“-=”运算符重载
{
	if (n < 0)
	{
		*this += (-n);
		return *this;
	}
	_day -= n;
	while (_day <= 0)
	{
		if (_month == 1)
		{
			_year--;
			_month = 12;
		}
		else
			_month--;
		_day += getMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(int n)   //“-”运算符重载，实现日期减天数。
{
	Date ret(*this);
	ret -= n;
	return ret;

}

Date& Date::operator++()           //前置++
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)        //后置++，将原对象值加一，但返回的是没有修改前的值。
{
	Date ret(*this);
	++(*this);
	return ret;
}

Date& Date::operator--()         //前置--
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)       //后置--
{
	Date ret(*this);
	--(*this);
	return ret;
}

int Date::operator-(Date& d)     //两个日期相减，返回两个日期相隔的天数。
{
	int num = 0;
	int flag = 1;
	Date Max(*this);
	Date Min(d);
	if ((*this) < d)
	{
		Max = d;
		Min = (*this);
		flag = -1;
	}
	while (Min != Max)
	{
		++Min;
		++num;
	}
	return flag*num;
}

void Date::print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}