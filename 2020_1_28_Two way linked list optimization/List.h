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
//��ʼ��
//void ListInit();
ListNode*  ListInit(ListNode* pHead);
// �������������ͷ���.
ListNode* BuyListNode(LTDataType x);
// ˫����������
void ListDestory(ListNode** ppHead);
//˫���������
void ListClear(ListNode* pHead);
// ˫�������ӡ
void ListPrint(ListNode* pHead);
//˫������β��
void ListPushBack(ListNode* pHead, LTDataType x);
// ˫������βɾ
void ListPopBack(ListNode* pHead);
//˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x);
//˫������ͷɾ
void ListPopFront(ListNode* pHead);


//˫���������,��Insert��erase�Ļ���
ListNode* ListFind(ListNode* pHead, LTDataType x);
//˫��������posλ��֮ǰ����ڵ�
void ListInsert(ListNode* pos, LTDataType x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode** pos);