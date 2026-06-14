#pragma once
#define  _CRT_SECURE_NO_WARNINGS    1	

#include<iostream>
#include<assert.h>
using namespace std;

typedef int LTDataType;
//带头双向循环链表
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev;//前驱指针
	struct ListNode* next;//后继指针

}LTNode;

//初始化
//void LTInit(LTNode** pphead);
LTNode* LTInit();//更推荐
//申请节点
LTNode* LTBuyNode(LTDataType x);
//打印
void LTPrint(LTNode* phead);
//判空
bool LTEmpty(LTNode* phead);
//销毁
void LTDestroy(LTNode** pphead);
//头插/尾插
//注意头插指的是在哨兵位之后插入 
void LTPushBack(LTNode* phead, LTDataType x);
void LTPushFront(LTNode* phead, LTDataType x);

//头删/尾删
void LTPopFront(LTNode* phead);
void LTPopBack(LTNode* phead);

//在pos位置之后插入数据
void LTInsert(LTNode* pos, LTDataType x);
void LTErase(LTNode* pos);
LTNode* LTFind(LTNode* phead, LTDataType x);