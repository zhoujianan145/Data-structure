#include"List.h"
//Ҳ����д��void ListInit(ListNode* pHead),�����ڲ��Ե�ʱ���Ҫ����������ָ�롣��ΪpheadҪ�����ı�
//����д��ListNode* ���Ե�ʱ����Դ���һ��ָ�룬����ӿ�һ����
ListNode* ListInit(ListNode* pHead)
{
	/*ListNode* pHead = BuyListNode(0);*/
	pHead->next = pHead;
	pHead->prev = pHead;
	return pHead;
}
//�ݻ�����
void ListDestory(ListNode** ppHead)
{
	/*assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		ListNode* next = cur->next;
		cur = next;
	}*/
	//����������������費��Ҫ��ʹ����������Ҫ��ɾ���ˣ���Ҫ�Ͳ�ɾ��
	//�����ﳵһ��
	ListClear(*ppHead);
	free(*ppHead);
	//û�ð���Ҫ��ı�phead���봫����ָ�룻
	/*pHead = NULL;*/
	//�ı亯������Ϊ����ָ��
	*ppHead = NULL;
	
	
}
//�������
void ListClear(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		ListNode* next = cur->next;
		cur = next;
	}
	//��Ҫ��֤˫����ѭ��
	pHead->next = pHead;
	pHead->prev = pHead;
}
//�����½ڵ�
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node= (ListNode*)malloc(sizeof(ListNode));
	node->next= NULL;
	node->prev = NULL;
	node->data = x;
	return node;
}
//β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	//assert(pHead);
	//ListNode* newNode = BuyListNode(x);
	//ListNode* tail = pHead->prev;
	//tail->next = newNode;
	//newNode->prev = tail;
	////���ﷸ��һ��������newNode��prevָ����ͷ
	//pHead->prev = newNode;
	//newNode->next = pHead;
	//Insert��������ѡλ��֮ǰ���룬����ListInsert(pHead->prev, x);���뵽�����ڶ���ȥ��
	ListInsert(pHead, x);
	

}
//βɾ
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
//ͷ��
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
//ͷɾ
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
//���ң������ɾ���Ļ���
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
//����
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
//ɾ��
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);

}
//��ӡ
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