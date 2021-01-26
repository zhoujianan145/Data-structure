#pragma once
#include<stdio.h>
#include<assert.h>
typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;
	/*int _size;*/
	int _top;//ջ���±��൱��֮ǰ˳����е�size��
	int _capacity;
}Stack;
//��ʼ��
void StackInit(Stack* pst);
//�ݻ�
void StackDestory(Stack* pst);
//��ջ
void StackPush(Stack* pst, STDataType x);
//��ջ
void StackPop(Stack* pst);
//ջ�Ĵ�С
int StackSzie(Stack* pst);
//ջ�Ƿ�Ϊ��
int StackEmpty(Stack* pst);
//��ȡջ������
STDataType StackTop(Stack* pst);
