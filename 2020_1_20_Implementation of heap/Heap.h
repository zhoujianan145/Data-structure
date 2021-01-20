#pragma once

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<assert.h>
//实现一个大堆
typedef int HpDataType;
typedef struct Heap
{
	HpDataType* _a;
	int  _size;
	int  _capacity;
}Heap;
//堆排序
void HeapSort(int *a, int n);
//向下调整算法
void AdjustDown(HpDataType* a, int n, int root);
//向上调整算法
void AdjustUp(HpDataType* a, int n, HpDataType x);
//有些需求，上来就需要把数组变成堆。
void HeapInit(Heap* php, HpDataType *a,int n);
//打印
void HeapPrint(Heap* hp);
//摧毁
void Destory(Heap* php);
//数组尾插入
void HeapPush(Heap* php, HpDataType x);
//删除堆顶数据,删数组尾没意义
void HeapPop(Heap* php);
//堆顶
HpDataType HeapTop(Heap* php);
// 堆的数据个数
int Heapsize(Heap* php);
// 堆的判空
int HeapEmpty(Heap* php);

//TopK问题
//最大的前K个，建立小堆
void PrintMaxTopK(HpDataType* a, int n, int k);

