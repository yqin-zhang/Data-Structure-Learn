#pragma once
#include<iostream>
#include<assert.h>
#include"SeqList.h"
using namespace std;

typedef int SLDataType;

typedef struct SeqList {

	SLDataType* alist;
	int size;
	int capacity;
}SL;

//初始化
void SLInit(SL* ps);
//销毁
void SLDestroy(SL* ps);
//打印
void SLPrint(SL* ps);
//扩容
void SLCheckCapacity(SL* ps);

//头插/尾插
void SLPushFront(SL* ps, SLDataType x);
void SLPushBack(SL* ps, SLDataType x);
//头删尾删
void SLPopFront(SL* ps);
//指定位置之前插入/删除
void SLInsert(SL* ps, int pos, SLDataType x);
void SLDelete(SL* ps, int pos);