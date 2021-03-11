#include<iostream>
using namespace std;
int main()
{
	int *p = (int*)malloc(sizeof(int)*4);

	int *p1 = new int;
	int *p2 = new int();
	int *p3 = new int[3];
	int a = 10;
	int &b = a;
	int c = 30;
	b = c;

	return 0;
}