#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>
#include<math.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
//class Solution {
//public:
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//        //求出两个链表各自的长度
//        ListNode* pa = headA;
//        ListNode* pb = headB;
//        int sizeA = 0;
//        int sizeB = 0;
//        int sub = 0;
//        while (pa)
//        {
//            sizeA++;
//            pa = pa->next;
//        }
//        while (pb)
//        {
//            sizeB++;
//            pb = pb->next;
//        }
//        sub = abs(sizeA - sizeB);//绝对值
//        //长链表先走sub
//        ListNode* shortList = headA;
//        ListNode* longList = headB;
//        if (sizeB < sizeA)
//        {
//            shortList = headB;
//            longList = headA;
//        }
//        while (sub--)
//        {
//            longList = longList->next;
//        }
//        //同一起跑线
//        while (shortList)
//        {
//            if (shortList== longList)
//            {
//                return shortList;
//            }
//            
//            shortList = shortList->next;
//            longList = longList->next;
//           
//        }
//        return NULL;
//    }
//};


//最优解，O（M+N）
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;

        ListNode* pA = headA;
        ListNode* pB = headB;

        // 当 pA 和 pB 相遇时结束
        while (pA != pB) {
            pA = pA ? pA->next : headB;  // 走完A，换到B
            pB = pB ? pB->next : headA;  // 走完B，换到A
        }

        return pA;  // 交点或nullptr
    }
};

int main()
{
    // 构建共享节点
    ListNode* common = new ListNode(4);
    common->next = new ListNode(5);

    // 链表A: 1 → 2 → 3 → 4 → 5
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = common;

    // 链表B: 6 → 7 → 4 → 5
    ListNode* headB = new ListNode(6);
    headB->next = new ListNode(7);
    headB->next->next = common;

    // 你的代码会正确返回 common 节点
    Solution s;
    s.getIntersectionNode(headA,headB);
}