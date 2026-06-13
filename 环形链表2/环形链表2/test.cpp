#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head==NULL || (head->next)==NULL)
        {
            return NULL;
        }
        ListNode* slow, * fast;
        slow = fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                ListNode* cur = head;
                //相遇就是入口地址
                while (cur != slow)
                {
                    cur = cur->next;
                    slow = slow->next;
                   
                }
                //一定会有
                return slow;
            }

        }
        return NULL;
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
    s.detectCycle(head);

    return 0;
}