#pragma once

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<assert.h>
//ʵ��һ�����
typedef int HpDataType;
typedef struct Heap
{
	HpDataType* _a;
	int  _size;
	int  _capacity;
}Heap;
//������
void HeapSort(int *a, int n);
//���µ����㷨
void AdjustDown(HpDataType* a, int n, int root);
//���ϵ����㷨
void AdjustUp(HpDataType* a, int n, HpDataType x);
//��Щ������������Ҫ�������ɶѡ�
void HeapInit(Heap* php, HpDataType *a,int n);
//��ӡ
void HeapPrint(Heap* hp);
//�ݻ�
void Destory(Heap* php);
//����β����
void HeapPush(Heap* php, HpDataType x);
//ɾ���Ѷ�����,ɾ����βû����
void HeapPop(Heap* php);
//�Ѷ�
HpDataType HeapTop(Heap* php);
// �ѵ����ݸ���
int Heapsize(Heap* php);
// �ѵ��п�
int HeapEmpty(Heap* php);

//TopK����
//����ǰK��������С��
void PrintMaxTopK(HpDataType* a, int n, int k);

