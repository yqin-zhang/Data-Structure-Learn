#include"Stack.h"
//为什么不用结构体指针
//如果用指针，STInit(ST* ps)初始化传的就不是取地址
// 而是用二级指针来接收，因为传值不会改变形参实参
typedef struct
{
	ST PushStack;//入栈
	ST PopStack;//出栈
} MyQueue;

//初始化
MyQueue* myQueueCreate()
{
	MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));

	STInit(&pq->PopStack);
	STInit(&pq->PushStack);
	return pq;
}
//入栈
void myQueuePush(MyQueue* obj, int x)
{
	STPush(&obj->PushStack, x);
}
//出栈--取栈顶
int myQueuePop(MyQueue* obj)
{
	//为空，将数据全部导入Pop
	if (STEmpty(&obj->PopStack))
	{
		while (!STEmpty(&obj->PushStack))
		{
			STPush(&obj->PopStack, STTop(&obj->PushStack));
			STPop(&obj->PushStack);
		}
	}
	int top = STTop(&obj->PopStack);
	STPop(&obj->PopStack);
	return top;
}
//取队列的队头元素--栈的栈顶元素
int myQueuePeek(MyQueue* obj)
{
	if (STEmpty(&obj->PopStack))
	{
		while (!STEmpty(&obj->PushStack))
		{
			STPush(&obj->PopStack, STTop(&obj->PushStack));
			STPop(&obj->PushStack);
		}
	}
	int top = STTop(&obj->PopStack);
	return top;
}

bool myQueueEmpty(MyQueue* obj)
{
	return STEmpty(&obj->PopStack) && STEmpty(&obj->PushStack);
}
//释放内存
void myQueueFree(MyQueue* obj)
{
	STDestroy(&obj->PopStack);
	STDestroy(&obj->PushStack);
	free(obj);
	obj = NULL;
}

int main()
{
	MyQueue* q = myQueueCreate();
	myQueuePush(q, 1);
	myQueuePush(q, 1);
	myQueuePush(q, 1);
	myQueuePush(q, 1);

	int peek=myQueuePeek(q);

	int ret1 = myQueuePop(q);
	int ret2 = myQueuePop(q);
	int ret3 = myQueuePop(q);

	myQueueFree(q);
	return 0;
}