#include"List.h"
//也可以写成void ListInit(ListNode* pHead),不过在测试的时候就要传进来二级指针。因为phead要发生改变
//这里写成ListNode* 测试的时候可以传入一级指针，满足接口一致性
ListNode* ListInit(ListNode* pHead)
{
	/*ListNode* pHead = BuyListNode(0);*/
	pHead->next = pHead;
	pHead->prev = pHead;
	return pHead;
}
//摧毁链表
void ListDestory(ListNode** ppHead)
{
	/*assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		ListNode* next = cur->next;
		cur = next;
	}*/
	//视情况而定，看还需不需要用使用链表，不需要就删除了，需要就不删除
	//就像购物车一样
	ListClear(*ppHead);
	free(*ppHead);
	//没用啊，要想改变phead必须传二级指针；
	/*pHead = NULL;*/
	//改变函数参数为二级指针
	*ppHead = NULL;
	
	
}
//清除链表
void ListClear(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		ListNode* next = cur->next;
		cur = next;
	}
	//还要保证双向且循环
	pHead->next = pHead;
	pHead->prev = pHead;
}
//创建新节点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node= (ListNode*)malloc(sizeof(ListNode));
	node->next= NULL;
	node->prev = NULL;
	node->data = x;
	return node;
}
//尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	//assert(pHead);
	//ListNode* newNode = BuyListNode(x);
	//ListNode* tail = pHead->prev;
	//tail->next = newNode;
	//newNode->prev = tail;
	////这里犯了一个错误，让newNode的prev指向了头
	//pHead->prev = newNode;
	//newNode->next = pHead;
	//Insert代表在所选位置之前插入，这样ListInsert(pHead->prev, x);插入到倒数第二个去了
	ListInsert(pHead, x);
	

}
//尾删
void ListPopBack(ListNode* pHead)
{
	//assert(pHead);
	//assert(pHead->next != pHead);
	//ListNode* tail = pHead->prev;
	//ListNode* tailPrev = tail->prev;
	///*printf("%d %d", tail->data, tailPrev->data);*/
	//tailPrev->next = pHead;
	//pHead->prev = tailPrev;
	//free(tail);
	ListErase(pHead->prev);
}
//头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	/*assert(pHead);
	ListNode* Next = pHead->next;
	ListNode* newNode = BuyListNode(x);
	pHead->next = newNode;
	newNode->prev = pHead;
	newNode->next = Next;
	Next->prev = newNode;*/
	ListInsert(pHead->next, x);
}
//头删
void ListPopFront(ListNode* pHead)
{
	/*assert(pHead);
	assert(pHead->next!=pHead);
	ListNode* next = pHead->next;
	ListNode* second =next->next;
	pHead->next = second;
	second->prev = pHead;
	free(next);*/
	ListErase(pHead->next);
}
//查找，插入和删除的基础
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* newNode = BuyListNode(x);

	posPrev->next = newNode;
	newNode->prev = posPrev;

	newNode->next = pos;
	pos->prev = newNode;
	
}
//删除
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);

}
//打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur!=pHead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");

}