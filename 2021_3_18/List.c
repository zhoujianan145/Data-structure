#include"List.h"

SListNode* BuySListNode(SLTDataType x)
{
	SListNode *newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("内存申请失败");
	}
	//这里忘记用->
	newNode->val = x;
	newNode->next = NULL;
	//这里忘记返回值
	return newNode;
}
// 单链表打印
void SListPrint(SListNode* plist)
{
	SListNode *cur = plist;
	//1 2 3 4 NULL cur为空是结束
	while (cur)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist,SLTDataType x)
{
	SListNode* Node = BuySListNode(x);
	//1 2 3 4 NULL tail为4时结束
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
		//注意一级指针，二级指针赋值的时候，解引用
		
		*pplist = Node;
		
}
//头插
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
//尾删
void SListPopBack(SListNode** pplist)
{
   //传入空链表
	if (*pplist == NULL)
		return NULL;
	//只有一个节点
	else if ((*pplist)->next==NULL)
	{
		
		free(*pplist);
		*pplist = NULL;
	}
	//一个或者一个以上
	SListNode *prev = NULL;
	SListNode *tail = *pplist;
	while (tail->next)
	{
		prev = tail;
		tail = tail->next;
	}
	free(tail);
	tail = NULL;//无所谓，局部变量出去也没了
	prev->next = NULL;

}
//头删
void SListPopFront(SListNode** pplist)
{
	//传入空，返回空
	if (*pplist == NULL)
		return NULL;
	//只有一个节点，free掉，让*pplist指向空
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
	//寻找与x相等的val
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
	//在pos后面插入
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