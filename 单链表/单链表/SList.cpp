#define  _CRT_SECURE_NO_WARNINGS    1	
#include"SList.h"

SLTNode* SLTBuyNode(SLTDataType x)
{
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newNode == NULL)
	{
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void SLTDestroy(SLTNode** pphead)
{
	if (pphead == NULL)
	{
		return;
	}
	SLTNode* cur = *pphead;
	while (cur != NULL)
	{
		SLTNode* ptail = cur->next;
		free(cur);
		cur = ptail;
	}
	*pphead = NULL;

}
void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode*newNode= SLTBuyNode(x);
	newNode->next = *pphead;
	*pphead = newNode;//头指针变为newNode
}
//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newNode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;//就是头指针
		return;
	}
	SLTNode* ptail = *pphead;
	while (ptail->next != NULL)
	{
		ptail = ptail->next;
	}
	ptail->next = newNode;
}
//头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);

	SLTNode* cur = (*pphead)->next;
	free(*pphead);
	*pphead = cur;

}
//尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);//链表不能为空
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	SLTNode* prev = NULL;      // 前一个节点
	SLTNode* tail = *pphead;   // 当前节点
	while (tail->next !=  NULL)
	{
		prev = tail;
		tail = tail->next;
	}
	free(tail);
	prev->next = NULL;
}
//pos之前插入
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && *pphead);//链表不能为空
	assert(pos);
	//assert();
	SLTNode* newNode = SLTBuyNode(x);
	//pos在头节点位置
	if (*pphead == pos)
	{
		newNode->next = *pphead;
		*pphead = newNode;
		return;
	}
	//pos不在头节点
	SLTNode* ptail = *pphead;
	while (ptail->next != pos)
	{
		ptail = ptail->next;
	}

	newNode->next = pos;
	ptail->next = newNode;

}
//pos之后插入
void SLTInertAfter(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead&&*pphead);//链表不能为空
	assert(pos);
	SLTNode* newNode = SLTBuyNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

//查找pos结点
// 查找：返回节点指针，没找到返回 NULL
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;  // 返回节点指针
		}
		cur = cur->next;
	}
	return NULL;  // 没找到
}