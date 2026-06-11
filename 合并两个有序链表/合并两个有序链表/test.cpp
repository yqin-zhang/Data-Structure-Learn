#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>

typedef struct ListNode 
  {
      int val;
      ListNode *next;
  }LTNode;
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)
        {
            return list2;
        }
        else if(list2==NULL)
        {
            return list1;
        }
        ListNode* p, * q;
        ListNode* newHead, * newTail;
        p = list1;
        q = list2;
        newHead = newTail = NULL;
        while (p && q)
        {
            if (newHead == NULL)
            {
                if (p->val <= q->val)
                {
                    newHead = newTail = p;
                    p = p->next;
                }
                else
                {
                    newHead = newTail = q;
                    q = q->next;
                }

            }
            else
            {
                if (p->val <= q->val)
                {
                    newTail->next = p;
                    newTail = p;
                    p = p->next;

                }
                else
                {
                    newTail->next = q;
                    newTail = q;
                    q = q->next;

                }
            }

        }
        while (q != NULL)
        {
            newTail ->next= q;
            newTail = q;
            q = q->next;
        }
        while (p != NULL)
        {
            newTail->next = p;
            newTail = p;
            p = p->next;
        }
        return newHead;
    }

};
