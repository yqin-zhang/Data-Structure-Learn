#include"Queue.h"

typedef struct {
	Queue q;
	Queue p;
} MyStack;

//初始化
MyStack* myStackCreate() {
	MyStack* pq = (MyStack*)malloc(sizeof(MyStack));
	if (pq == NULL)
	{
		return NULL;
	}
	QueueInit(&pq->p);
	QueueInit(&pq->q);
	return pq;
}

//入栈
void myStackPush(MyStack* obj, int x) {
	//入空的栈
	if (!QueueEmpty(&obj->q)) {
		// q 非空：继续放入 q
		QueuePush(&obj->q, x);
	}
	else {
		// p 非空：放入 p
		QueuePush(&obj->p, x);
	}
}
//出栈
int myStackPop(MyStack* obj) {
	//先把不为空的队列的前size-1个移到另一个为空的队列
	Queue* ret_p = &obj->p;
	Queue* ret_q = &obj->q;
	if (!QueueEmpty(ret_q))
	{
		while (QueueSize(ret_q) > 1)
		{
			QueuePush(ret_p, QueueFront(ret_q));
			QueuePop(ret_q);
		}
		//此时还剩下一个
		int a = QueueFront(ret_q);
		QueuePop(ret_q);
		return a;

	}
	else
	{
		while (QueueSize(ret_p) > 1)
		{
			QueuePush(ret_q, QueueFront(ret_p));
			QueuePop(ret_p);
		}
		//此时还剩下一个
		int a = QueueFront(ret_p);
		QueuePop(ret_p);
		return a;

	}

}
//取栈顶
int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->p))
	{
		return QueueBack(&obj->p);
	}
	else
	{
		return QueueBack(&obj->q);
	}
}
//判空
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q) && QueueEmpty(&obj->p);
}
//释放
void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->p);
	QueueDestroy(&obj->q);
	free(obj);
	obj = NULL;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/

int main()
{
	MyStack* st = myStackCreate();
	myStackPush(st, 1);
	myStackPush(st, 2);
	myStackPush(st, 3);
	myStackPush(st, 4);

	int top=myStackTop(st);

	int ret1 = myStackPop(st);
	int ret2 = myStackPop(st);
	int ret3 = myStackPop(st);

	myStackFree(st);
	return 0;
}