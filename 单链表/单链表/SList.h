#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
typedef int SLTDataType;

typedef struct SListNode
{
	int data;//数据
	struct SListNode* next;//指针

}SLTNode;

//初始化
//void SLTInit(SLTNode* phead);
//申请节点
SLTNode* SLTBuyNode(SLTDataType x);

//销毁
void SLTDestroy(SLTNode** phead);
//打印
void SLTPrint(SLTNode* phead);
//头插/尾插
void SLTPushFront(SLTNode** pphead,SLTDataType x);
void SLTPushBack(SLTNode** pphead,SLTDataType x);
//头删/尾删
void SLTPopFront(SLTNode** pphead);
void SLTPopBack(SLTNode** pphead);
//在pos之前插入
void SLTInsert(SLTNode** pphead,SLTNode* pos, SLTDataType x);
//pos之后插入
void SLTInertAfter(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//查找指定数据
SLTNode* SLTFind(SLTNode* phead,SLTDataType x);