#include"BinaryTree.h"
//先序遍历
//根左右
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->val);
	PreOrder(root->left);
	PreOrder(root->right);
}
//中序遍历
//左根右
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	PreOrder(root->left);
	printf("%d ", root->val);
	PreOrder(root->right);
}
//后序遍历
//左右根
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	PreOrder(root->left);
	PreOrder(root->right);
	printf("%d ", root->val);

}// ⼆叉树结点个数

////这里虽然size会改变，但是size会累加7-14
//int BinaryTreeSize(BTNode* root)
//{
//	static int size = 0;
//	if (root == NULL)
//	{
//		return 0;
//	}
//	size++;
//	BinaryTreeSize(root->left);
//	BinaryTreeSize(root->right);
//
//	return size;
//}

////这里size一直为1，传值返回，size一直没有改变
//int BinaryTreeSize(BTNode* root, int size)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	size++;
//	BinaryTreeSize(root->left, size);
//	BinaryTreeSize(root->right, size);
//
//	return size;
//}

//虽然又解决了size不会改变的问题，但是这里又有累加的问题
//int BinaryTreeSize(BTNode* root, int* psize)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	(*psize)++;
//	BinaryTreeSize(root->left, psize);
//	BinaryTreeSize(root->right, psize);
//
//	return *psize;
//}

//1+左子树结点+右子树结点
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1+ BinaryTreeSize(root->left)+ BinaryTreeSize(root->right);
}

// 二叉树叶子结点个数
//叶子节点的左右孩子都为空
//左子树叶子结点个数+右子树叶子结点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	
	return BinaryTreeLeafSize(root->left)+BinaryTreeLeafSize(root->right);
}
// ⼆叉树第k层结点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	k--;
	return BinaryTreeLevelKSize(root->left, k)+ BinaryTreeLevelKSize(root->right, k);
}
//⼆叉树的深度/⾼度
int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1+max(BinaryTreeDepth(root->left), BinaryTreeDepth(root->right));
}
// ⼆叉树查找值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->val == x)
	{
		
		return root;
	}
	BTNode* leftFind=BinaryTreeFind(root->left, x);
	//左子树找到了，一直返回
	if (leftFind != NULL)
	{
		return leftFind;
	}

	BTNode* rightFind=BinaryTreeFind(root->right, x);
	//右子树找到了，一直返回
	if (rightFind != NULL)
	{
		return rightFind;
	}

	return NULL;
}
// ⼆叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}
	BinaryTreeDestory(&(*root)->left);
	BinaryTreeDestory(&(*root)->right);
	if (*root)
	{
		free(*root);
		*root = NULL;
		return;
	}
}
//层序遍历
void LevelOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		//取队头并出队
		BTNode* node=QueueFront(&q);
		QueuePop(&q);
		printf("%d ", node->val);
		//将node的左右孩子入队（不为空）
		if (node->left)
		{
			QueuePush(&q, node->left);

		}
		if (node->right)
		{
			QueuePush(&q, node->right);

		}
	}
	QueueDestroy(&q);

}
// 判断⼆叉树是否是完全⼆叉树
bool BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
	{
		return false;
	}
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		//取队头并出队
		BTNode* node = QueueFront(&q);
		QueuePop(&q);
		if (node == NULL)
		{
			break;
		}
		//将node的左右孩子入队
		QueuePush(&q, node->left);
		QueuePush(&q, node->right);
	}

	//判断第二次队列结点是否都为空，有一个不为空就false
	while (!QueueEmpty(&q)) 
	{
		BTNode* top = QueueFront(&q);
		QueuePop(&q);
		if (top != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}