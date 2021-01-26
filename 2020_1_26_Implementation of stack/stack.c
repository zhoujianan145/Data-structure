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
//�ݻ�
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a == NULL;
	pst->_top = 0;
	pst->_capacity = 0;

}
//��ջ
void StackPush(Stack* pst,STDataType x)
{
	assert(pst);
	//�����ʼ�����capacity��0��ÿ�γ�0,�����д�ˡ�
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
//��ջ
void StackPop(Stack* pst)
{
	assert(pst);
	//�����С�ڵ���0�Ͳ�ɾ�������������Ļ���Ȼ��ɾ�˵���û����ʾ
	//ֱ�Ӷ��ԣ�����0�˳�
	/*if (pst->_top>0)*/
	assert(pst->_top > 0);
	pst->_top--;
}
//ջ�Ĵ�С
int StackSzie(Stack* pst)
{
	return pst->_top;
}
//ջ�Ƿ�Ϊ��
int StackEmpty(Stack* pst)
{
	return pst->_top == 0 ? 1 : 0;
}
//��ȡջ������
STDataType StackTop(Stack* pst)
{
	return pst->_a[pst->_top - 1];
}
