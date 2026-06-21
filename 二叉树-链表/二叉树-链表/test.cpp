#include"BinaryTree.h"
BTNode* BuyBTNode(int val)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->val = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

BTNode* CreateTree()
{
	BTNode* n1 = BuyBTNode(1);
	BTNode* n2 = BuyBTNode(2);
	BTNode* n3 = BuyBTNode(3);
	BTNode* n4 = BuyBTNode(4);
	BTNode* n5 = BuyBTNode(5);
	BTNode* n6 = BuyBTNode(6);
	BTNode* n7 = BuyBTNode(7);
	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n4->left = n5;
	n4->right = n6;
	n5->left = n7;
	return n1;
}
int main()
{
	BTNode* node = CreateTree();
	PreOrder(node);
	int size = 0;
	int size1=BinaryTreeSize(node);
	printf("%d\n", size1);
	int size2 = BinaryTreeLeafSize(node);
	printf("%d\n", size2);
	int size3 = BinaryTreeLevelKSize(node, 2);
	printf("%d\n", size3);
	int size4 = BinaryTreeDepth(node);
	printf("%d\n", size4);
	BTNode* find = BinaryTreeFind(node,7);
	printf("%d\n", find->val);
	LevelOrder(node);
	
	printf("%d\n", BinaryTreeComplete(node));

	BinaryTreeDestory(&node);
	return 0;
}