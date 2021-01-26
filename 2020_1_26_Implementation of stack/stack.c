#include"stack.h"
void StackInit(Stack* pst)
{
	assert(pst);
	/*pst->_a == NULL;
	pst->_top = 0;
	pst->_capacity = 0;*/
	pst->_a = (STDataType*)malloc(sizeof(STDataType)*4);
	pst->_top = 0;
	pst->_capacity = 4;
}
//摧毁
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a == NULL;
	pst->_top = 0;
	pst->_capacity = 0;

}
//入栈
void StackPush(Stack* pst,STDataType x)
{
	assert(pst);
	//假如初始化里的capacity是0，每次乘0,代码白写了。
	if (pst->_top == pst->_capacity)
	{
		pst->_capacity *= 2;
		STDataType* tmp = (STDataType*)realloc(pst->_a,sizeof(STDataType)*pst->_capacity);
		pst->_a = tmp;
		if (pst->_a == NULL)
		{
			exit(-1);
		}
	}
	pst->_a[pst->_top] = x;
	pst->_top++;


}
//出栈
void StackPop(Stack* pst)
{
	assert(pst);
	//如果过小于等于0就不删除，但是这样的话虽然不删了但又没有提示
	//直接断言，减到0退出
	/*if (pst->_top>0)*/
	assert(pst->_top > 0);
	pst->_top--;
}
//栈的大小
int StackSzie(Stack* pst)
{
	return pst->_top;
}
//栈是否为空
int StackEmpty(Stack* pst)
{
	return pst->_top == 0 ? 1 : 0;
}
//获取栈顶数据
STDataType StackTop(Stack* pst)
{
	return pst->_a[pst->_top - 1];
}
