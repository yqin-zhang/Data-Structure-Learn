#pragma once
#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>
#include<assert.h>
#include"Queue.h"

using namespace std;

typedef int BTDataType;
//二叉树节点结构的定义
typedef struct BinaryTreeNode
{
	BTDataType val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;
//先序遍历
void PreOrder(BTNode* root);
//中序遍历
void InOrder(BTNode* root);
//后序遍历
void PostOrder(BTNode* root);
// ⼆叉树结点个数
int BinaryTreeSize(BTNode* root);
// ⼆叉树叶⼦结点个数
int BinaryTreeLeafSize(BTNode* root);
// ⼆叉树第k层结点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
//⼆叉树的深度/⾼度
int BinaryTreeDepth(BTNode* root);
// ⼆叉树查找值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// ⼆叉树销毁
void BinaryTreeDestory(BTNode** root);
//层序遍历
void LevelOrder(BTNode* root);
// 判断⼆叉树是否是完全⼆叉树
bool BinaryTreeComplete(BTNode* root);