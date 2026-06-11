#define  _CRT_SECURE_NO_WARNINGS    1	
#include<stdio.h>
#include<stdlib.h>



struct ListNode {
     int val;
     ListNode *next;
  };
 //¿ìÂýÖ¸Õë
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow, *fast;
        slow = fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
