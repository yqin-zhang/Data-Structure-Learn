#include"Queue.h"

int main()
{
	Queue pq;

	QueueInit(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 1);
	QueuePush(&pq, 1);
	QueuePush(&pq, 1);

	QueueDestroy(&pq);
	return 0;
}