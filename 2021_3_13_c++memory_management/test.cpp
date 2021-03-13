#include<iostream>
using namespace std;

class Date;
class Time
{
	friend Date;
	friend ostream& operator<<(ostream& out, const Date& d);
public:
	Time(int hour,int minute,int seconds)
		:_hour(hour)
		, _minute(minute)
		, _seconds(seconds)
	{}
private:
	int _hour;
	int _minute;
	int _seconds;
};

class Date
{
	//重载输入输出
friend istream& operator>>(istream& in, Date& d);
friend ostream& operator<<(ostream& out, const Date& d);

public:
	Date(int year=2000, int month=8, int day=1,int hour=16,int minute=0,int seconds=0)
		:_year( year)
		, _month(month)
		, _day(day)
		, _t(hour,minute,seconds)
	{
		cout << "调用默认构造函数"<< endl;
		
	}
	~Date()
	{
		cout<<"调用析构函数"<<endl;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;

};
istream& operator>>(istream& in,Date& d)
{
	cout << "请输入 年 月 日" << endl;
	in >> d._year >> d._month >> d._day;
     
	return in;
}
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "-"<<d._month <<"-"<< d._day << endl;
	out << d._t._hour << "-" << d._t._minute << "-" << d._t._seconds << endl;
	return out;
}
class A
{
private:
	static int _a;
	int _c;
public:
	class B
	{
	public:
		void fool(const A& a)
		{
			cout<<_a;
			cout << a._c;
		}
	};

};
int A::_a = 1;
int main()
{
	////c语言
	//int *p = (int*)malloc(sizeof(int));
	//int *p1 = (int*)malloc(sizeof(int)* 10);
	//free(p);
	//free(p1);
	//

	////c++
	//int *p2 = new int;
	////定义并初始化
	//int *p3 = new int(10);

	////定义数组
	//int *p4 = new int[10];

	//delete p2;
	//delete p3;
	//delete[] p4;
	Date* d1 = (Date*)malloc(sizeof(Date));
	Date* d2 = (Date*)malloc(sizeof(Date)*10);
	free(d1);
	free(d2);

	Date* d3=new Date;
	Date* d4 = new Date[10];
	delete d3;
	delete[] d4;
	
	return 0;
}

