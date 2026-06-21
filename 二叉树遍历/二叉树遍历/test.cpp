#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	char val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}

};
//先序-根左右
TreeNode* CreateTree(vector<char>& arr,int& i)
{ 
	if (arr[i] == '#')
	{
		i++;//往后走一步
		return nullptr;
	}
	//第一个元素就是根节点
	TreeNode* root = new TreeNode(arr[i]);//根
	i++;//往后走一步

	root->left = CreateTree(arr,i);//左
	root->right = CreateTree(arr, i);//右
	return root;
}
//中序-左根右
void Print(TreeNode* root)
{
	if (root == nullptr)
	{
		return ;
	}
	Print(root->left);//左
	cout << root->val << " ";
	Print(root->right);//右
}
int main()
{
	string input;
	//cout << "请输入前序遍历字符串（用 # 表示空节点）：";
	cin >> input;

	vector<char> arr(input.begin(), input.end());
	int i = 0;
	TreeNode* root = CreateTree(arr,i);
	Print(root);
	return 0;
}