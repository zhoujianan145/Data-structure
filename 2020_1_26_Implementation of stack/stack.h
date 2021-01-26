#pragma once
#include<stdio.h>
#include<assert.h>
typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;
	/*int _size;*/
	int _top;//栈顶下标相当于之前顺序表中的size，
	int _capacity;
}Stack;
//初始化
void StackInit(Stack* pst);
//摧毁
void StackDestory(Stack* pst);
//入栈
void StackPush(Stack* pst, STDataType x);
//出栈
void StackPop(Stack* pst);
//栈的大小
int StackSzie(Stack* pst);
//栈是否为空
int StackEmpty(Stack* pst);
//获取栈顶数据
STDataType StackTop(Stack* pst);
