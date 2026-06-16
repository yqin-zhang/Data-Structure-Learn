#pragma once
#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>
#include<assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* arr;
	int top;
	int capacity;
}ST;
//初始化
void STInit(ST* ps);
// 销毁栈
void STDestroy(ST* ps);
// 入栈
void STPush(ST* ps, STDataType x);
//出栈
void STPop(ST* ps);
//取栈顶元素
STDataType STTop(ST* ps);
//获取栈中有效元素个数
int STSize(ST* ps);
//栈是否为空
bool STEmpty(ST* ps);