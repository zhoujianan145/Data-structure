#include<iostream>

using namespace std;

class Date
{
public:
	Date(int year,int month,int day)
		:_year(year)
		,_month(month)
		, _day(day)
	{}
	Date* operator&()
	{
		cout << "Date* operator&()" << endl;
		return this;
		
	}
	const Date* operator&()const
	{
		cout << "const Date* operator&()const" << endl;
		return nullptr;
		
	}
	void print()const
	{
		cout << _year << "-"<< _month <<"-"<< _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;

};
int main()
{
	
	const Date d1(2000, 8, 1);
	Date d2(d1);

	cout<<&d2<<endl;
	cout<<&d1<<endl;
	
	/*d1.print();
	Date d2(d1);
	d2.print();*/
	//d1.operator&();
	
	return 0;
}
