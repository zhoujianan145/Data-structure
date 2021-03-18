#include"List.h"

SListNode* BuySListNode(SLTDataType x)
{
	SListNode *newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("�ڴ�����ʧ��");
	}
	//����������->
	newNode->val = x;
	newNode->next = NULL;
	//�������Ƿ���ֵ
	return newNode;
}
// �������ӡ
void SListPrint(SListNode* plist)
{
	SListNode *cur = plist;
	//1 2 3 4 NULL curΪ���ǽ���
	while (cur)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}
// ������β��
void SListPushBack(SListNode** pplist,SLTDataType x)
{
	SListNode* Node = BuySListNode(x);
	//1 2 3 4 NULL tailΪ4ʱ����
	if (*pplist != NULL)
	{
		SListNode *tail = *pplist;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = Node;
	}
	else
		//ע��һ��ָ�룬����ָ�븳ֵ��ʱ�򣬽�����
		
		*pplist = Node;
		
}
//ͷ��
void SListPushFront(SListNode** pplist, SLTDataType x)
{
	SListNode* Node = BuySListNode(x);
	if (*pplist != NULL)
	{
		Node->next = *pplist;
		*pplist = Node;
	}
	else
		*pplist = Node;
}
//βɾ
void SListPopBack(SListNode** pplist)
{
   //���������
	if (*pplist == NULL)
		return NULL;
	//ֻ��һ���ڵ�
	else if ((*pplist)->next==NULL)
	{
		
		free(*pplist);
		*pplist = NULL;
	}
	//һ������һ������
	SListNode *prev = NULL;
	SListNode *tail = *pplist;
	while (tail->next)
	{
		prev = tail;
		tail = tail->next;
	}
	free(tail);
	tail = NULL;//����ν���ֲ�������ȥҲû��
	prev->next = NULL;

}
//ͷɾ
void SListPopFront(SListNode** pplist)
{
	//����գ����ؿ�
	if (*pplist == NULL)
		return NULL;
	//ֻ��һ���ڵ㣬free������*pplistָ���
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode*	head = *pplist;
		*pplist = (*pplist)->next;
		free(head);
	}

}
SListNode* SListFind(SListNode* plist, SLTDataType x)
{
	//Ѱ����x��ȵ�val
	 SListNode* cur = plist;
	 while (cur)
	 {
		 if (cur->val == x)
			 return cur;
		 cur = cur->next;
	 }

	 return NULL;

}
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	//��pos�������
	assert(pos);
	SListNode *newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
	
}
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* next = pos->next;
	if(next != NULL)
	{
		pos->next = next->next;
		free(next);
	}
	
}