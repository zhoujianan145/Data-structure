#include<iostream>
using namespace std;
int main()
{
    char a = -1;
	int b = 1;
	if (a > b)
	{
		cout << "单目运算符char整形提升" << endl;
	}
	else if (a >= b)
	{
		cout << "双目运算符char整形提升" << endl;
	}
	cout << "啥都没有" << endl;
	return 0;

}