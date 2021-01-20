#include "Heap.h"
//����
void Swap(HpDataType *p1,HpDataType *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
//��ӡ
void HeapPrint(Heap* hp)
{
	int i;
	for (i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
//
void AdjustUp(HpDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;
	//�������Ƿ������������������Զ����С��0
	/*while (parent >= 0)*/
	while (child>0)
	{
		if (a[child]<a[parent])
		{
			Swap(&a[child], &a[parent]);
			//�±꣬����������
			child = parent;
			//��Ҳ������ȥ���´�ѭ�������Ƚ�
			parent = (child - 1) / 2;
		}
		else
		{
			//˵������Ҫ��ȥ��
			break;
		}
	}
	

}
//���µ����㷨����С��
void AdjustDown(HpDataType* a,int n,int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//Ĭ������������������С
		//������Һ���С�����ӣ�child++������Һ���
		//��Ϊ����Ҫ��������������С��һ�����н���������С��С��Ҳ�ͱ���һ������С

		//����child+1С��n������Ϊһ�����ֻ�����ӣ���if�������+1����Խ�硣
		if ((child+1<n) &&(a[child + 1] <a[child]))
		{
			
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child] ,& a[parent]);
			//��������
			//���±꣬����һ������
			parent = child;
			child = parent * 2 + 1;
		}
		//������׽ڵ�Ⱥ���С����������ṹ��С��
		else
		{
			break;
		}
	}	
}

//������
void HeapSort(int *a, int n)
{
	//Ҫ���ж������Ȱ������ɶ�
	//�����һ����Ҷ�ӽڵ㿪ʼ��Ҷ�ӽڵ�û��Ҫ���µ���
	//�����ʼ���Ѿ����ö���
	/*for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a,n,i);
	}
*/
	//���������ȻҲ���ԣ����ǲ��ÿ���Ҳ������
	/*int count = n;
	for (int i = count; i >0; i--)
	{
		int end = n - 1;
		Swap(&a[0],&a[end]);
		n--;
		AdjustDown(a, n, 0);
	}*/
	int end = n - 1;
	//С�ڵ���0����������0����
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		//�ѵĴ�Сÿ�μ�һ��ÿ�δӶѶ���ʼ������Ϊ���˸��ڵ㶼��С�ѿ���ֱ��ʹ�����µ�����
		AdjustDown(a, end, 0);
		end--;
	}
}
//�ѵĳ�ʼ��
void HeapInit(Heap* php, HpDataType *a, int n)
{
	php->_a = (HpDataType*)malloc(sizeof(HpDataType)*n);
	memcpy(php->_a, a, sizeof(HpDataType)*n);
	php->_size = n;
	php->_capacity = n;
	//������
	//����ֱ�ӵ���AdjustDown����������𣿲��ܡ���Ϊ�����������飬��û������������������С��
	//�����һ���ڵ�ĸ��׿�ʼ����,���һ���ڵ��±�Ϊn-1,���׵�����(n-1-1)/2
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->_a, php->_size, i);
	}

}
//����
void Destory(Heap* php)
{
	assert(php);
	free(php->_a);
	php=NULL;
	php->_capacity = php->_size = 0;

}
//��������ĩ��Ȼ��ͨ�����ϵ����㷨����֤ԭ���ѵ�����
void HeapPush(Heap* php, HpDataType x)
{
	assert(php);
	if (php->_size = php->_capacity)
	{
		php->_capacity *= 2;
		//���ֻ�д�ɣ�Heap*����
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
// �ѵ����ݸ���
int Heapsize(Heap* php)
{
	return php->_size;
}
// �ѵ��п�
int HeapEmpty(Heap* php)
{
	return php->_size==0?0:1;
}

//����С�ѣ���Ѷ������ݱȽϣ�������Ͱ�������
void PrintMaxTopK(HpDataType* a, int n, int k)
{
	Heap hp;
	//����K��Ԫ�ص�С��
	HeapInit(&hp, a, k);
	//����������������ҾͰ��㸲�ǵ�
	HpDataType ret = HeapTop(&hp);
	for (int i = k; i < n; i++)
	{
		
		if (a[i]>ret)
		{
			//�ʼ��HpDataType ret = HeapTop(&hp);������������˰��죬ʵ��ԭ��ܼ򵥣�ÿ�α����ret��������ʵ�ʶѶ�������
			//��������ÿ�ζ���ʼ��һ�Σ���Ȼ�ͳ�����
			ret = a[i];
			AdjustDown(a, k, 0);
		}

	}
	
	for (int i = 0; i < k; i++)
		printf("%d", a[i]);
}