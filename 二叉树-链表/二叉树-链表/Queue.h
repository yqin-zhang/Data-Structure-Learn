#pragma once
#include<iostream>
#include<assert.h>

//修改 
//如果BTNode*必须包含头文件在前面
//struct XXX是原生的，编译器知道这是结构体，前置声明
//而且这样写可以不用包含头文件，减少耦合
typedef struct BinaryTreeNode* QDataType;
//链表实现，双指针

//队列结点结构
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	int size;
	QNode* phead;
	QNode* ptail;
}Queue;


//初始化队列
void QueueInit(Queue* pq);
//销毁队列
void QueueDestroy(Queue* pq);
// 入队列，队尾
void QueuePush(Queue* pq, QDataType x);
//队列判空
bool QueueEmpty(Queue* pq);
// 出队列，队头
void QueuePop(Queue* pq);
//取队头数据
QDataType QueueFront(Queue* pq);
//取队尾数据
QDataType QueueBack(Queue* pq);

//队列有效元素个数
int QueueSize(Queue* pq);