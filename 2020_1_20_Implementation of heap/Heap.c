#include "Heap.h"
//交换
void Swap(HpDataType *p1,HpDataType *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
//打印
void HeapPrint(Heap* hp)
{
	int i;
	for (i = 0; i < hp->_size; ++i)
	{
		printf("%d", hp->_a[i]);
	}
	printf("\n");
}
//
void AdjustUp(HpDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;
	//由于它是分数计算出来的所以永远不会小于0
	/*while (parent >= 0)*/
	while (child>0)
	{
		if (a[child]<a[parent])
		{
			Swap(&a[child], &a[parent]);
			//下标，孩子向上走
			child = parent;
			//你也继续上去，下次循环继续比较
			parent = (child - 1) / 2;
		}
		else
		{
			//说明不需要上去了
			break;
		}
	}
	

}
//向下调整算法建立小堆
void AdjustDown(HpDataType* a,int n,int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//默认两个孩子中左孩子最小
		//如果有右孩子小于左孩子，child++，变成右孩子
		//因为后面要与两个孩子中最小的一个进行交换，比最小的小，也就比另一个孩子小

		//这里child+1小于n，是因为一种情况只有左孩子，而if语句里面+1数组越界。
		if ((child+1<n) &&(a[child + 1] <a[child]))
		{
			
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child] ,& a[parent]);
			//继续迭代
			//换下标，到下一颗子树
			parent = child;
			child = parent * 2 + 1;
		}
		//如果父亲节点比孩子小，而他本身结构是小堆
		else
		{
			break;
		}
	}	
}

//堆排序
void HeapSort(int *a, int n)
{
	//要进行堆排序，先把数组变成堆
	//从最后一个非叶子节点开始，叶子节点没必要向下调整
	//外面初始化已经建好堆了
	/*for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a,n,i);
	}
*/
	//这个代码虽然也可以，但是不好看，也不巧妙
	/*int count = n;
	for (int i = count; i >0; i--)
	{
		int end = n - 1;
		Swap(&a[0],&a[end]);
		n--;
		AdjustDown(a, n, 0);
	}*/
	int end = n - 1;
	//小于等于0结束，大于0继续
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		//堆的大小每次减一，每次从堆顶开始。（因为除了根节点都是小堆可以直接使用向下调整）
		AdjustDown(a, end, 0);
		end--;
	}
}
//堆的初始化
void HeapInit(Heap* php, HpDataType *a, int n)
{
	php->_a = (HpDataType*)malloc(sizeof(HpDataType)*n);
	memcpy(php->_a, a, sizeof(HpDataType)*n);
	php->_size = n;
	php->_capacity = n;
	//构建堆
	//但是直接调用AdjustDown函数能完成吗？不能。因为它传进来数组，并没能满足左右子树都是小堆
	//从最后一个节点的父亲开始调整,最后一个节点下标为n-1,父亲的坐标(n-1-1)/2
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->_a, php->_size, i);
	}

}
//销毁
void Destory(Heap* php)
{
	assert(php);
	free(php->_a);
	php=NULL;
	php->_capacity = php->_size = 0;

}
//放在数组末，然后通过向上调整算法，保证原来堆的性质
void HeapPush(Heap* php, HpDataType x)
{
	assert(php);
	if (php->_size = php->_capacity)
	{
		php->_capacity *= 2;
		//这手滑写成（Heap*）了
		php->_a = (HpDataType*)realloc(php->_a, sizeof(HpDataType)*php->_capacity);
	}
	php->_a[php->_size] = x;
	php->_size++;
	AdjustUp(php->_a,php->_size,php->_size-1);
}
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size>0);
	Swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;
	AdjustDown(php->_a, php->_size, 0);
	
}
HpDataType HeapTop(Heap* php)
{
	assert(php);

	return php->_a[0];
}
// 堆的数据个数
int Heapsize(Heap* php)
{
	return php->_size;
}
// 堆的判空
int HeapEmpty(Heap* php)
{
	return php->_size==0?0:1;
}

//建立小堆，与堆顶的数据比较，比他大就把他换了
void PrintMaxTopK(HpDataType* a, int n, int k)
{
	Heap hp;
	//建立K个元素的小堆
	HeapInit(&hp, a, k);
	//如果外面的数比你大，我就把你覆盖掉
	for (int i = k; i < n; i++)
	{
		
		if (a[i]>hp._a[0])
		{
			
			hp._a[0] = a[i];
			AdjustDown(php->_a, k, 0);
		}

	}
	
	for (int i = 0; i < k; i++)
		printf("%d", hp._a[i]);
}
