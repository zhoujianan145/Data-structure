#include"Queue.h"

void QueueInit(Queue *pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;

}
void QueueDestory(Queue *pq)
{
	assert(pq);
	QueueNode* cur = pq->_head;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_head = pq->_tail = NULL;
}
void QueuePush(Queue *pq, QDataType x)
{
	assert(pq);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	
	if (newNode == NULL)
	{
		exit(-1);
	}
	newNode->_data = x;
	newNode->_next = NULL;
	if (pq->_head == NULL)
	{
		pq->_head = pq->_tail = newNode;
	}
	else
	{
		pq->_tail->_next= newNode;
		pq->_tail = newNode;
	}

}
void QueuePop(Queue *pq)
{
	assert(pq);
	assert(pq->_head);
	QueueNode* next = pq->_head->_next;
	free(pq->_head);
	pq->_head = next;
	//假如只剩一个数据，指向同一个数据，free掉了那块空间之后，pq->tail还指向这那块空间

	if (pq->_head == NULL)
	{
	//最开始这竟然写了free(pq->tail)，哎，之前已经free过那块空间了，这里只需要让pq->tail不要在指向	
		pq->_tail = NULL;
	}

}

QDataType QueueFront(Queue *pq)
{
	assert(pq);
	return pq->_head->_data;
}
QDataType QueueBack(Queue *pq)
{
	assert(pq);
	return pq->_tail->_data;
}
int QueueSize(Queue *pq)
{
	assert(pq);
	QueueNode* cur = pq->_head;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}
int QueueEmpty(Queue *pq)
{
	assert(pq);
	return pq->_head == NULL ? 1 : 0;
}