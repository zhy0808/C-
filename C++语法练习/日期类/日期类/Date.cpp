#include"Date.hpp"
Date::Date(int year, int month, int day)     //ȫȱʡ�Ĺ��캯����ȱʡ��������������
{
	_year = year;
	_month = month;
	_day = day;
	if (year < 0 || month<0 || month>13 || day<0 || day>getMonthDay(year, month))
	{
		cout << year << "-" << month << "-" << day << " ���ڴ���!" << endl;
	}
}
int Date::getMonthDay(int year, int month)                          //����ĳ��ĳ�¶�Ӧ������
{
	int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))//����2��28��
	{
		return 29;
	}
	return arr[month - 1];
}
Date::Date(const Date& d)        //�������캯������������Ϊ�˷�ֹ���޵ݹ�
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
bool Date::operator==(Date& d)   //��==�����������
{
	return _year == d._year&&_month == d._month&&_day == d._day;
}

bool Date::operator!=(Date& d)  //��!=�����������
{
	return _year != d._year || _month != d._month || _day != d._day;
}

bool Date::operator>(Date& d)   //��>�����������
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

bool Date::operator>=(Date& d)   //��>=�����������
{
	return ((*this) > d || (*this) == d);      //����ֱ�Ӻ������ã����ٴ�������ࡣ
}

bool Date::operator<(Date& d)   //��<�����������
{
	return !((*this) >= d);
}

bool Date::operator<=(Date& d)   //��<=�����������
{
	return !((*this) > d);
}

Date& Date::operator+=(int n)   //��+=�����������
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

Date Date::operator+(int n)   //��+�����������,ʵ�����ڼ�����
{
	Date ret(*this);
	ret += n;
	return ret;
}

Date& Date::operator-=(int n)   //��-=�����������
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

Date Date::operator-(int n)   //��-����������أ�ʵ�����ڼ�������
{
	Date ret(*this);
	ret -= n;
	return ret;

}

Date& Date::operator++()           //ǰ��++
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)        //����++����ԭ����ֵ��һ�������ص���û���޸�ǰ��ֵ��
{
	Date ret(*this);
	++(*this);
	return ret;
}

Date& Date::operator--()         //ǰ��--
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)       //����--
{
	Date ret(*this);
	--(*this);
	return ret;
}

int Date::operator-(Date& d)     //������������������������������������
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