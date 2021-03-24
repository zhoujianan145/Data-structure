#include<iostream>
using namespace std;

//// 模拟实现简单的string (不包含增删查改)
//// 深浅拷贝
//namespace bit
//{
//	class string
//	{
//	public:
//		/*string()
//			:_str(new char[1])
//			{
//			_str[0] = '\0';
//			}*/
//
//		//string(char* str = "\0")
//		string(char* str = "") 
//			:_str(new char[strlen(str)+1])
//		{
//			strcpy(_str, str); 
//		}
//
//		// string s2(s1)
//		string(const string& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		// s1 = s3
//		// s1 = s1
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				delete[] _str;
//				_str = new char[strlen(s._str) + 1];
//				strcpy(_str, s._str);
//			}
//
//			return *this;
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//
//		const char* c_str()
//		{
//			return _str;
//		}
//	private:
//		char* _str;
//	};
//}
//
//
////int main()
////{
////	bit::string s1("hello");
////	//s1[0] = 'x';
////	bit::string s2 = "world";
////	bit::string s3;
////
////	cout << s2.c_str() << endl;
////	cout << s3.c_str() << endl;
////
////
////	std::string s4;
////	cout << s4.c_str() << endl;
////
////
////
////	return 0;
////}
//
//int main()
//{
//	bit::string s1("hello");
//	bit::string s2(s1);
//	s1[0] = 'x';
//
//	cout << s1.c_str() << endl;
//	cout << s2.c_str() << endl;
//
//	bit::string s3("hello bit!");
//	s1 = s3;
//
//	cout << s1.c_str() << endl;
//	cout << s3.c_str() << endl;
//
//	s1 = s1;
//	cout << s1.c_str() << endl;
//
//	return 0;
//}

#include "string.h"

void Print(const bit::string& ss)
{
	auto it = ss.begin();
	while (it != ss.end())
	{
		cout << *it << " ";
		//*it = 'x';
		++it;
	}
	cout << endl;
}

int main()
{
	bit::string s("1234");

	for (size_t i = 0; i < s.size(); ++i)
	{
		cout << s[i] << " ";
	}
	cout << endl;

	//bit::string::iterator it = s.begin();
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	Print(s);

	// 替换成迭代器
	for (auto& e : s)
	{
		e += 1;
	}

	Print(s);

	s += 'x';
	s += "hello world";
	Print(s);

	system("pause");
	return 0;
}