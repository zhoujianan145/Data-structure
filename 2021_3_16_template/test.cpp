#include<iostream>
using namespace std;

//��������ʲô�����أ���ʼ�Ҳ��Ե������������main������������������������������int ���ͣ�������main����ֻ������ô���˺����ﻹ���Ա�ɿɶ���д
//�Һ�����һ�����⣬��ֻ�Ǵ�ֵ���Σ��β��б��õ���ֻ�ǿ�����ֵ����ԭ���ı������޹�ϵ��
//���Լ������β���main��ʵ�ε����ã��βξͱ����const��
//int Add1(int a, int b)
//{
//	;
//}
//int Add(const int& a,const int& b)
//{
//	return a+b;
//}
//template<class T,class K>
//
//T Add(const T& a, const K& b)
//{
//	return a + b;
//}

template<class T>
class stack
{
public:
	stack(int capacity=4);
	~stack();
	void push(const T& x);
private:
	T* _a;
	int _top;
	int _capacity;
};

template<class T>
stack<T>::stack(int capacity)
:_a(new T[4])
, _top(0)
, _capacity(capacity)
{}

template<class T>
stack<T>::~stack()
{
	delete[] _a;
	_a = nullptr;
	_capacity = _top = 0;
}

template<class T>
void stack<T>::push(const T& x)
{
	;
}
int main()
{
	/*const int a = 5;
	const double b = 1.3;
	int c = 1;
	Add(a, 1);
	Add(a, b);
	*/
	//stack<int>s1(1);
	stack<int>s1;
	stack<double>s2;
	s1.push(1);
	return 0;
}