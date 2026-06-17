#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>
#include<assert.h>
using namespace std;

typedef struct
{
	int* arr;//根据K个空间动态申请
	int rear;//队尾
	int front;//队头
	int capacity;//空间大小
} MyCircularQueue;

//初始化
MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* pq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	//k+1个空间
	pq->arr = (int*)malloc(sizeof(int) * (k + 1));
	pq->front = pq->rear = 0;
	pq->capacity = k;
	return pq;
}

//判空
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->rear;
}
//判满
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return (obj->rear + 1) % (obj->capacity + 1) == obj->front;
}
//向循环队列插入一个元素。如果成功插入则返回真。
//满则插入失败
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	//没有满
	obj->arr[obj->rear++] = value;
	obj->rear %= obj->capacity + 1;
	return true;
}
//从循环队列中删除一个元素。如果成功删除则返回真。
//空则删除失败
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	obj->front++;
	obj->front %= obj->capacity + 1;
	return true;
}
//取队头
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->arr[obj->front];
}
//取队尾
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	int prev = obj->rear - 1;
	if (obj->rear == 0)
	{
		prev = obj->capacity;
	}
	return obj->arr[prev];
}
//销毁
void myCircularQueueFree(MyCircularQueue* obj)
{
	if (obj->arr)
		free(obj->arr);
	free(obj);
	obj = NULL;//包括obj->arr=NULL

}
int main() {
	// 创建容量为 4 的循环队列
	MyCircularQueue* q = myCircularQueueCreate(4);

	// 测试入队
	cout << "入队 1: " << myCircularQueueEnQueue(q, 1) << endl;  // 1 (true)
	cout << "入队 2: " << myCircularQueueEnQueue(q, 2) << endl;  // 1
	cout << "入队 3: " << myCircularQueueEnQueue(q, 3) << endl;  // 1
	cout << "入队 4: " << myCircularQueueEnQueue(q, 4) << endl;  // 1

	cout << "判满: " << myCircularQueueIsFull(q) << endl;  // 1 (true)

	cout << "入队 5: " << myCircularQueueEnQueue(q, 5) << endl;  // 0 (false，已满)

	// 测试取队头队尾
	cout << "队头: " << myCircularQueueFront(q) << endl;  // 1
	cout << "队尾: " << myCircularQueueRear(q) << endl;   // 4

	// 测试出队
	cout << "出队: " << myCircularQueueDeQueue(q) << endl;  // 1 (true)
	cout << "队头: " << myCircularQueueFront(q) << endl;  // 2

	// 继续入队（循环使用）
	cout << "入队 5: " << myCircularQueueEnQueue(q, 5) << endl;  // 1 (true)
	cout << "队尾: " << myCircularQueueRear(q) << endl;  // 5

	// 全部出队
	while (!myCircularQueueIsEmpty(q)) {
		cout << myCircularQueueFront(q) << " ";
		myCircularQueueDeQueue(q);
	}
	cout << endl;  // 输出: 2 3 4 5

	// 测试空队列取元素
	cout << "空队列队头: " << myCircularQueueFront(q) << endl;  // -1
	cout << "空队列队尾: " << myCircularQueueRear(q) << endl;   // -1

	myCircularQueueFree(q);
	return 0;
}