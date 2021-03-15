#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year,int month,int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	~Date()
	{
		;
	}

private:
	int _year;
	int _month;
	int _day;

};
//template <class T,class K>
//void Swap(T& a, K& b)
//{
//	T temp = a;
//	a = b;
//	b = temp
//}

template <class T>
T Add(const T& a, const T& b)
{
	return a + b;
}
int add(int* a, int* b)
{
	return 
}
int main()
{
	/*void* p1 = malloc(0x7fffffff);
	try{
		void* p2 = operator new(0x7fffffff);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}*/
	//Date* p1 = new Date(2000, 1, 1);
	////Date* p2 = new Date[10];
	//Date* p2 = (Date*)operator new (sizeof(Date) * 10);
	////构造函数该怎么调用
	//int n = 10;
	//for (int i = 0; i < 10; i++)
	//{
 //      new(p2+i)Date(2000, 1, 2);
	//}
	////析构函数可以直接显示调用
	//for (int i = 0; i < 10; i++)
	//{
	//	(p2 + i)->~Date();
	//}
	//operator delete(p2);
	

	//1G=1024m=1024*1024kb=1024*1024*1024byte
	//假如这样写int溢出了
	//void* p1 = operator new(1024 * 1024 * 1024 * 2);
	/*void* p1 = operator new(1024u * 1024 * 1024 * 4);*/

	/*int a=0;
	int b = 1;
	double c = 1.0;
	double d = 2.0;
	Swap(a, b);
	Swap(c, d);

	Swap(a,c);
	*/
	int a = 0;
	int b = 1;
	double c = 1.0;
	double d = 2.0;
	Add(a, b);
	Add(a, (int)d);
	Add<int>(a, d);


	return 0;
}