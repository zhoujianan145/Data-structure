#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<assert.h>
#pragma once

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;
//初始化
//void ListInit();
ListNode*  ListInit(ListNode* pHead);
// 创建返回链表的头结点.
ListNode* BuyListNode(LTDataType x);
// 双向链表销毁
void ListDestory(ListNode** ppHead);
//双向链表清除
void ListClear(ListNode* pHead);
// 双向链表打印
void ListPrint(ListNode* pHead);
//双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x);
// 双向链表尾删
void ListPopBack(ListNode* pHead);
//双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x);
//双向链表头删
void ListPopFront(ListNode* pHead);


//双向链表查找,是Insert和erase的基础
ListNode* ListFind(ListNode* pHead, LTDataType x);
//双向链表在pos位置之前插入节点
void ListInsert(ListNode* pos, LTDataType x);
// 双向链表删除pos位置的节点
void ListErase(ListNode** pos);