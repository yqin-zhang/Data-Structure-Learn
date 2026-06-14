#include"list.h"
//初始化--带头
//void LTInit(LTNode** pphead)
//{
//	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
//	if (newnode == NULL)
//	{
//		perror("newnode");
//		return;
//	}
//	//数据无效，且指向自己
//	newnode->data = -1;
//	newnode->prev = newnode->next = newnode;
//	*pphead = newnode;
//}

LTNode* LTInit()
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("newnode");
		return NULL;
	}
	//数据无效，且指向自己
	newnode->data = -1;
	newnode->prev = newnode->next = newnode;
	return newnode;
}


//申请节点
LTNode* LTBuyNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("buynode");
		return NULL;
	}
	newnode->data = x;
	newnode->prev = newnode->next = NULL;
	return newnode;
}

void LTPrint(LTNode* phead)
{
	assert(phead);
	//跳过头节点
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void LTDestroy(LTNode** pphead)
{
	LTNode* pcur = (*pphead)->next;
	while (pcur != *pphead)
	{
		LTNode* ptail = pcur->next;
		free(pcur);
		pcur = ptail;
	}
	free(*pphead);
	*pphead = NULL;
}
bool LTEmpty(LTNode* phead)
{
	assert(phead);
	return phead->next == phead;
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	if (newnode == NULL)
	{
		perror("newnode");
		return;
	}
	//遍历到结尾处
	LTNode* ptail = phead->next;
	while (ptail->next != phead)
	{
		ptail = ptail->next;
	}
	ptail->next = newnode;
	newnode->next = phead;
	newnode->prev = ptail;
	phead->prev = newnode;
}
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	if (newnode == NULL)
	{
		perror("newnode");
		return;
	}

	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next->prev = newnode;
	phead->next = newnode;
}

//头删/尾删
void LTPopFront(LTNode* phead)
{
	//有结点可删
	assert(!LTEmpty(phead));

	LTNode* del = phead->next;
	LTNode* cur = del->next;
	cur->prev = phead;
	phead->next = cur;
	free(del);
	del = NULL;
}
void LTPopBack(LTNode* phead)
{
	//至少有一个尾结点可删
	assert(!LTEmpty(phead));

	LTNode* ptail = phead->next;
	while (ptail->next != phead)
	{
		ptail = ptail->next;
	}
	phead->prev = ptail->prev;
	ptail->prev->next = phead;
	free(ptail);
	ptail = NULL;
}

//在pos位置之后插入数据
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);//pos位置有效
	LTNode* newnode = LTBuyNode(x);
	if (newnode == NULL)
	{
		perror("newnode");
		return;
	}
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}
//删除pos结点
void LTErase(LTNode* pos)
{
	assert(pos);
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}