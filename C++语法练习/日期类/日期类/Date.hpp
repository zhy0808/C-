#include<iostream>
#include<windows.h>

using namespace std;

class Date
{
public:
	Date(int year = 2021, int month = 5, int day = 20);
	Date(const Date& d);  //拷贝构造
	int getMonthDay(int year,int month);
	bool operator==(Date& d);
	bool operator!=(Date& d);
	bool operator>(Date& d);
	bool operator>=(Date& d);
	bool operator<(Date& d);
	bool operator<=(Date& d);
	Date& operator+=(int n);
	Date operator+(int n);
	Date& operator-=(int n);
	Date operator-(int n);
	Date& operator++();           //前置++
	Date operator++(int);        //后置++
	Date& operator--();           
	Date operator--(int);
	int operator-(Date& d);


	void print();
private:
	int _year;
	int _month;
	int _day;
};