#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

typedef int HDataType;
typedef struct Heap
{
	HDataType* a;
	int size;
	int capacity;
}HNode;

//初始化
void HeapInit(HNode* php);
//销毁
void HeapDestroy(HNode* php);
//打印

//入堆
void HeapPush(HNode* php, HDataType x);
//删除堆顶
int HeapPop(HNode* php);
// 判空
bool HPEmpty(HNode* php);
//求size
int HPSize(HNode* php);


//向上调整算法
void AdjustUp(HDataType* arr, int child);

//向下调整算法
void AdjustDown(HDataType* arr, int size, int parent);