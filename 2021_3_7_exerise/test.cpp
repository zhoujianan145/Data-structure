#include<iostream>
using namespace std;
class Time
{
public:
	Time(int hour=10, int minute=10, int seconds=10)
		:_hour(hour)
		, _minute(minute)
		, _seconds(seconds)
	{}
private:
	int _hour;
	int _minute;
	int _seconds;
};

//class Date
//{
//public:
//	Date(int year, int month, int day,int hour,int minute,int seconds)
//		: _t(hour,minute,seconds)
//		,_year (year)
//	    ,_month (month)
//	    ,_day  (day)
//	{}
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//		/*Date(int year, int month, int day, int hour, int minute, int senconds)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		Time t(hour, minute, senconds);
//		_t = t;
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time _t;
//
//};
class A
{
public:
	 A(int a)
		:_a(a)
	{}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
	void print()
	{
		cout << _a<< endl;
	}
private:
	int _a;
	static int _b;
};
int A::_b = 0;
class B
{
public:
	B()
	{
		++_b;
	}
	B(const B& b)
	{
		++_b;
	}
	

private:
	static int _b;

};
int B::_b = 0;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
public:
	Date(int year=1900, int month=1, int day=1)
		:_year(year)
	, _month(month)
	, _day(day)
	{}
	//ostream& operator<<(ostream& out)
	//{
	//	//this->_year,this->_month,this->day
	//	out<<_year<< _month <<_day<<endl;
	//	return out;
	//}
private:
	int _year;
	int _month;
	int _day;

};
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year <<"-"<< d._month <<"-"<< d._day<<endl;
	return out;
}



int main()
{
	Date d1;
	Date d2(2000, 5, 6);
	operator<<(cout, d1) << (cout, d2);
	cout << d1 << d2 << endl;
	
	//A a1(3);
	///* a1 = 3;
	//a1.print();*/

	//A a2 = 3;
	//sizeof(A);
	//B b1;
	//B b2;
	//B b3;
	//B b4(b3);
	//
	

	return 0;
}
