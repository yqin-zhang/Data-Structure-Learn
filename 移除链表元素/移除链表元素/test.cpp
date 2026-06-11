#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>
struct ListNode {
    int val;
    ListNode* next;
};
//以下算法的前提是有单独的dummy node
//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//        ListNode* cur, * prev, * q;
//        cur = head->next;
//        prev= head;
//        q = NULL;
//
//        while (cur)
//        {
//            if (cur->val != val)
//            {
//                prev = cur;
//                cur = cur->next;
//
//            }
//            else
//            {
//                q = cur;
//                prev->next = cur->next;
//                cur = cur->next;
//                free(q);
//                q = NULL;
//            }
//        }
//        ListNode* node = head;
//        return node;
//    }
//};
//实际上没有dummy node
//迭代
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //单独处理一下头结点的位置
        while (head != NULL && head->val == val)
        {
            ListNode* p = head;
            head = head->next;
            delete p;
        }
        if (head == NULL)
        {
            return NULL;
        }
        //到这里已经排除了head不是val值
        ListNode* prev = head;
        ListNode* cur = head->next;

        while (cur != NULL) {
            if (cur->val == val) {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

//递归
//适用于数量较小的，数量太大不行
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return NULL;  //返回 NULL

        if (head->val == val) {
            ListNode* p = head;
            head = head->next;
            delete p;
            return removeElements(head, val);  //返回递归结果
        }
        else {
            head->next = removeElements(head->next, val);  //连接递归结果
            return head;
        }
    }
};
//插入新链表
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newHead, * newTail;
        newHead = newTail = NULL;

        ListNode* pcur = head;
        while (pcur)
        {
            if (pcur->val != val)
            {
                //尾插
                //链表为空
                ListNode* p = pcur;

                if (newHead == NULL)
                {
                    newHead = newTail = p;
                }
                else
                {
                    newTail->next = p;
                    newTail = p;
                }
            }
            pcur = pcur->next;

        }
        //结尾制空
        if (newTail != NULL)
        {
            newTail->next = NULL;
        }
        return newHead;
    }
};
//哑巴节点--最佳实践
//ListNode dummy(0);
//dummy.next=head;
//return dummy.next;