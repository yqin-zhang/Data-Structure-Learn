#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetriclr(TreeNode* leftnode, TreeNode* rightnode)
    {
        if (leftnode == NULL && rightnode == NULL)
        {
            return true;
        }
        if (leftnode == NULL || rightnode == NULL)
        {
            return false;
        }
        if (leftnode->val != rightnode->val)
        {
            return false;
        }
        return isSymmetriclr(leftnode->left, rightnode->right)&&
            isSymmetriclr(leftnode->right, rightnode->left);

    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
        {
            return NULL;
        }
        return isSymmetriclr(root->left, root->right);
        
    }
};


int main()
{
    Solution s;
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);
    bool ret=s.isSymmetric(root1);
    cout << ret << endl;
    return 0;
}