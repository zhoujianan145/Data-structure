#include"List.h"
void Test()
{
	/*ListNode* pHead = NULL;
	ListInit(&phead);*/
	ListNode* pHead = BuyListNode(0);
	pHead = ListInit(pHead);
	ListPushBack(pHead, 1);
	ListPushBack(pHead, 2);
	ListPushBack(pHead, 3);
	ListPushBack(pHead, 4);
	ListPrint(pHead);
	ListPopBack(pHead);
	ListPrint(pHead);
	ListPushFront(pHead, 0);
	ListPrint(pHead);
	ListPopFront(pHead);
	ListPrint(pHead);
	/*ListDestory(&pHead);
	ListPrint(pHead);*/
}
void Test2()
{
	ListNode* pHead = BuyListNode(0);
	pHead = ListInit(pHead);
	ListPushBack(pHead, 1);
	ListPushBack(pHead, 2);
	ListPushBack(pHead, 3);
	ListPushBack(pHead, 4);
	ListNode* pos = ListFind(pHead, 3);
	ListInsert(pos, 30);
	ListPrint(pHead);
	ListErase(&pos);
	//ListDestory(pHead);
	ListPushBack(pHead, 5);
	ListPopBack(pHead);
	ListPrint(pHead);



}
int main()
{
	/*Test();*/
	Test2();
	system("pause");
	return 0;
}