#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>

typedef struct ListNode {
    int val;
    ListNode* next;

}LTNode;
//迭代法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode* pre, * cur, * next;
        pre = NULL;
        cur = head;
        next = cur->next;
        while (cur)
        {
            cur->next = pre;
            pre = cur;
            cur = next;
            if (cur)//判断在进行
            {
                next = cur->next;
            }
        }
        head = pre;
        return head;
    }
};
//头插法
//递归--不太推荐
int main()
{

        // 构建参数：链表
        LTNode* n1 = (LTNode*)malloc(sizeof(LTNode));
        LTNode* n2 = (LTNode*)malloc(sizeof(LTNode));
        LTNode* n3 = (LTNode*)malloc(sizeof(LTNode));
        LTNode* n4 = (LTNode*)malloc(sizeof(LTNode));


        // 设置节点值
        n1->val = 1;
        n2->val = 7;
        n3->val = 2;
        n4->val = 7;

        // 连接节点
        n1->next = n2;
        n2->next = n3;
        n3->next = n4;
        n4->next = NULL;

        Solution s;
        ListNode*p=s.reverseList(n1);
    return 0;
}