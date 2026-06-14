#include"list.h"


int main()
{
	LTNode* node = LTInit();
	/*LTInit(&node);*/
	LTPushBack(node, 1);
	LTPrint(node);

	LTPushBack(node, 2);
	LTPushBack(node, 3);
	LTPrint(node);
	LTPushFront(node, 99);
	LTPushFront(node, 100);
	LTPrint(node);

	LTPopFront(node);
	LTPopFront(node);
	LTPrint(node);

	LTPopBack(node);
	LTPopBack(node);
	LTPrint(node);

	LTDestroy(&node);
	return 0;
}
