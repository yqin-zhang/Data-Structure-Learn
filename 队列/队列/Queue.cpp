#include"Queue.h"
//初始化队列
void QueueInit(Queue* pq)
{
	pq->size = 0;
	pq->phead = pq->ptail = NULL;
}
//销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);
	while (pq->phead)
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
// 入队列，队尾
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//申请结点空间
	QNode* tmp = (QNode*)malloc(sizeof(QNode));
	if (tmp == NULL)
	{
		perror("malloc fail\n");
		return;
	}
	tmp->val = x; 
	tmp->next = NULL;
	if (QueueEmpty(pq))
	{
		pq->ptail = pq->phead = tmp;
	}
	else
	{
		pq->ptail->next = tmp;
		pq->ptail = tmp;
	}
	pq->size++;
}

//队列判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead ==  NULL;
}
// 出队列，队头
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QNode* del = pq->phead;
	pq->phead = pq->phead->next;
	// 如果删除后队列为空，尾指针也要置空
	if (pq->phead == NULL)
	{
		pq->ptail = NULL;
	}
	free(del);
	pq->size--;
}
//取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->phead->val;
}
//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->ptail->val;
}
//队列有效元素个数
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}