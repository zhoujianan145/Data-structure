#include"Heap.h"

void Test1(Heap* php)
{
	HeapPush(php, 13);
	HeapPop(php);
}
void Test2(Heap* php)
{
	int n = HeapEmpty(php);
	int m = Heapsize(php);
	/*printf("%d ", n);
	printf("%d ", m);*/
}
int main()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(HpDataType));
	/*HeapSort(hp._a, sizeof(a) / sizeof(HpDataType));*/
	/*Test1(&hp);
	HeapPrint(&hp);*/
	PrintMaxTopK(a, sizeof(a) / sizeof(HpDataType), 2);
	Test2(&hp);
	system("pause");
	return 0;
}