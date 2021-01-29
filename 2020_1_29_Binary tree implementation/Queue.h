#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QDataType _data;
}QueueNode;
//β�ϲ��룬��βָ��ֱ�ӱ�������
typedef struct Queue
{
	 QueueNode* _head;
	 QueueNode* _tail;
}Queue;

//��ʼ��
void QueueInit(Queue *pq);
//�ݻ�
void QueueDestory(Queue *pq);
//�����
void QueuePush(Queue *pq,QDataType x);
//������
void QueuePop(Queue *pq);

QDataType QueueFront(Queue *pq);

QDataType QueueBack(Queue *pq);
//�Ƿ�Ϊ��
int QueueEmpty(Queue *pq);
//���д�С
int QueueSize(Queue *pq);