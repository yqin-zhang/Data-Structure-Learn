#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int TreeSize(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return 1 + TreeSize(root->left) + TreeSize(root->right);
    }

    // 前序遍历：根 → 左 → 右
    void PreOrder(TreeNode* root, vector<int>& arr)  //  传引用，避免拷贝
    {
        if (root == NULL)
        {
            return;
        }
        arr.push_back(root->val);           // 先访问根
        PreOrder(root->left, arr);          // 再访问左子树
        PreOrder(root->right, arr);         // 最后访问右子树
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        // 预先分配空间（优化）
        arr.reserve(TreeSize(root));

        // 前序遍历填充数组
        PreOrder(root, arr);

        return arr;
    }
};

// 测试代码
int main()
{
    // 创建一棵树：    1
    //               / \
    //              2   3
    //             / \
    //            4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    vector<int> result = s.preorderTraversal(root);

    // 输出前序遍历结果
    cout << "前序遍历结果：";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
    // 预期输出：1 2 4 5 3

    // 清理内存（防止内存泄漏）
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}