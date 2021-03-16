#include<iostream>
using namespace std;

//在这里是什么问题呢，开始我测试的是这个函数，main函数定义了两个常量。函数参数是int 类型，我在想main里是只读，怎么到了函数里还可以变成可读可写
//我忽略了一个问题，我只是传值传参，形参列表拿到的只是拷贝的值，和原来的变量再无关系。
//所以假如你形参是main里实参的引用，形参就必须加const了
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