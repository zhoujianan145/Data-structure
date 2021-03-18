#include"List.h"
void test()
{
	SListNode* plist = NULL;
	/*plist=BuySListNode(2);*/
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushFront(&plist, 4);
	SListPopBack(&plist);
	SListPopFront(&plist);
	SListNode* pos = SListFind(plist, 2);
	//2后面插入一个4
	SListInsertAfter(pos, 4);
	SListEraseAfter(pos);
	SListPrint(plist);
}
int main()
{
	test();
	system("pause");
	return 0;
}