#define  _CRT_SECURE_NO_WARNINGS    1	
#include"SList.h"

int main()
{
	SLTNode* node = NULL;
	//Î²²å
	SLTPushBack(&node, 1);
	SLTPushBack(&node, 2);
	SLTPushBack(&node, 3);
	SLTPushBack(&node, 4);
	SLTPrint(node);
	//Í·²å
	SLTPushFront(&node, 99);
	SLTPushFront(&node, 98);
	SLTPushFront(&node, 97);
	SLTPrint(node);

	//Î²É¾
	SLTPopBack(&node);
	SLTPopBack(&node);
	SLTPopBack(&node);
	SLTPrint(node);

	//Í·É¾
	SLTPopFront(&node);
	SLTPopFront(&node);
	SLTPopFront(&node);
	SLTPrint(node);

	
	return 0;
}