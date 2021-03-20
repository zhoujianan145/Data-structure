//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date()
//		:_year(2000)
//	{};
//	Date modiefed(const Date d1)const
//	{
//		d1._day;
//		return d1;
//
//	}
//	Date modiefed1(Date d1)
//	{
//		const Date d2;
//		d1.modiefed(d2);
//		return d2;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//
//
//int main()
//{
//	Date d1;
//	const Date d2;
//
//	d1.modiefed(d2);
//	return 0;
//}
#include<iostream>
#include<string>
using namespace std;

//int main()
//{
//	string line;
//	while (getline(cin, line))
//	{
//		int pos = line.rfind(' ');
//		int ret = line.size() - pos;
//		cout << ret;
//	}
//	return  0;
//}
////记得传引用需要加const
//string modified(string s)
//{
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		s[i]='1';
//	}
//	return s;
//}
//int main()
//{
//	//隐式类型转换成匿名对象
//	cout << modified("1234") << endl;
//    return 0;
//}
//class Date
//{
//public:
//	Date(int year)
//		:_year(year)
//	{
//		cout << "调用构造函数" << endl;
//	}
//	~Date()
//	{
//		cout << "调用析构函数" << endl;
//	}
//	bool operator==(const Date& d)const
//	{
//		return _year == d._year;
//	}
//private:
//	int _year;
//
//};
//int main()
//{
//	Date d2(3);
//	Date& d1=Date(3);
//	d1 == d2;
//	Date d3(4);
//	d2 == d3;
//	Date& d1 = 3;
//	
//	return 0;
//}
//class solution{
//public:
//	int  stringToInt(string s)const
//	{
//		int num=0;
//		string::iterator it = s.begin();
//
//		while (it != s.end())
//		{
//			num *= 10;
//			num += *it - '0';
//			++it;
//		}
//		num = 0;
//		string::reverse_iterator rit = s.rbegin();
//		while (rit < s.rend())
//		{
//			num *= 10;
//			num += *rit - '0';
//			++rit;
//		}
//
//		return num;
//	}
//	string reverse(const string& s)
//	{
//		/*string::const_iterator first = s.begin();
//		string::const_iterator end = s.end();*/
//		auto first = s.begin();
//		auto end = s.end() - 1;
//		while (first < end)
//		{
//			swap(*first, *end);
//			first++;
//			end--;
//		}
//		return s;
//	}
//};
//void test()
//{
//	char arr[] = "abcd";
//	char* begin = arr;
//	char* end = arr + strlen(arr)-1;
//	while (begin < end)
//	{
//		swap(*begin, *end);
//		begin++;
//		end--;
//	}
//}

//int main()
//{/*
//	test();*/
//	/*cout << solution().stringToInt("1234") << endl;*/
//	/*cout << solution().reverse("1234") << endl;*/
//	string s = "abc";
//	s += '\0';
//	s += 'x';
//	cout << s << endl;
//	s.push_back('x');
//	s.append("xc");
//
//	return 0;
//}
//int main()
//{
//	string s = "asas";
//	string s1 = "sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss";
//}
//int main()
//{
//	/*string url = "http://www.baidu.com";
//	
//	string urlAdd = url;
//	urlAdd += "/guoji";
//	cout << urlAdd << endl;
//	*/
//	string s("abcd");
//	/*s.insert(1,"123");*/
//	/*s.insert(s.begin(), 'a');*/
//	s.insert(s.end(), 'x');
//	cout << s << endl;
//	return 0;
//}
//int main()
//{
//	string file1("test.cpp.tar.zip");
//
//	size_t pos = file1.rfind('.');
//	if (pos != string::npos)
//	{
//		
//		cout<<file1.substr(pos)<<endl;
//	}
//	return 0;
//}
//int main()
//{
//	string url("http://www.cplusplus.com/reference/string/string/rfind/");
//
//	size_t pos1 = url.find(':');
//	if (pos1 != string::npos)
//	{
//        cout << url.substr(0, pos1) << endl;
//	}
//	size_t pos2 = url.find('/',pos1+3);
//	if (pos1 != string::npos)
//	{
//		cout << url.substr(pos1+3,pos2-(pos1+3)) << endl;
//	}
//	cout << url.substr(pos2 + 1) << endl;
//	string eraseurl = url;
//	eraseurl.erase(0,pos1+3);
//	cout << eraseurl << endl;
//	return 0;
//}
int main()
{
	/*string s1("小明");
	string s2("小黄");

	cout << (s1==s2)<< endl;
	cout << ("杰哥" == "阿伟" )<< endl;*/
	string suff = "http://";
	string url = suff + "www.baidu.com";
	string tengxunurl = "www.tengxun.com" + suff;
	cout << url << endl;
	cout << suff << endl;
	cout << tengxunurl << endl;
	printf("大小是：%d %d", 3, x);
	return 0;
}