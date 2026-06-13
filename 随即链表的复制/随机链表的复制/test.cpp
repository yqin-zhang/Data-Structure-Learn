#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
        {
            return NULL;
        }
        Node* pcur = head;   
        //复制
        while (pcur)
        {
            Node* newnode = new Node(pcur->val);
            newnode->next = pcur->next;
            pcur->next = newnode;
            pcur = newnode->next;
        }
        //置random指针
        Node* cur = head;
        while (cur)
        {
            Node* copy = cur->next;
            if(copy->random)
            {
                copy->random = cur->random->next;//核心

            }
            cur = copy->next;
        }

        //新旧链表断开
        Node* res = head->next;
        Node* cur2 = head;
        while (cur2)
        {
            Node* copy = cur2->next;
            cur2->next = copy->next;

            if (copy->next)
            {
                copy->next = copy->next->next;
            }
            cur2 = cur2->next;
        }
        //
        return res;
    }
};

int main()
{


    return 0;
}