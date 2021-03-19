#include<iostream>
#include<string>
using namespace std;

void test1()
{
	//调用string(const cahr* s)构造函数,
	string s1("1234");
	//"1234"隐式类型转换为匿名对象，然后拷贝构造给s
	string s2 = "1234";
	//匿名对象
	string("1234");

}
void test2()
{
	string s1("hello world");
	//从第六个开始默认拷贝10个字符
	string s2(s1, 6, 10);
	string s3(s1, 6);
	string s4(s1, 6, 2);
	string s5(5, 'x');
	cout << s5 << endl;
}
void test3()
{
	string s1("hello world");
	/*s1.size();
	s1.capacity();
	s1.empty();
	int n = 50;
	int capacity = s1.capacity();
	for (int i = 0; i < n; i++)
	{
		s1.push_back('0' + i);
		if (capacity != s1.capacity())
		{
			cout << "occur increase capacity:" <<s1.capacity()<< endl;
			capacity = s1.capacity();
		}
	}
	cout << s1<< endl;*/
	/*int n = 50;
	s1.reserve(50);*/
	int n = 100;
	int capacity = s1.capacity();
	cout << s1 << endl;
	cout << s1.capacity() << endl;
	
	/*for (int i = 0; i < n; i++)
	{
		s1.push_back('0' + i);
		if (capacity != s1.capacity())
		{
			cout << "occur increase capacity:" << s1.capacity() << endl;
			capacity = s1.capacity();
		}
	}*/
	s1.resize(n, 'x');
	cout << s1 << endl;
	cout << s1.capacity() << endl;
	
}

int main()
{

	test3();

	return 0;
}