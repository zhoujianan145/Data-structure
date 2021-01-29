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
//尾上插入，把尾指针直接保存起来
typedef struct Queue
{
	 QueueNode* _head;
	 QueueNode* _tail;
}Queue;

//初始化
void QueueInit(Queue *pq);
//摧毁
void QueueDestory(Queue *pq);
//入队列
void QueuePush(Queue *pq,QDataType x);
//出队列
void QueuePop(Queue *pq);

QDataType QueueFront(Queue *pq);

QDataType QueueBack(Queue *pq);
//是否为空
int QueueEmpty(Queue *pq);
//队列大小
int QueueSize(Queue *pq);