#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

//快慢指针
class Solution {
public:
    bool hasCycle(ListNode* head) {
       
        if (head==NULL||head->next == NULL)
        {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast&&fast->next)
        {
            //先走在判断，起始位置是相同的
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};
ListNode* createSimpleCycle() {
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node2;  // 尾部指向节点2，形成环

    return head;
}
int main()
{
    ListNode* head = createSimpleCycle();
    Solution s;
    s.hasCycle(head);

    return 0;
}