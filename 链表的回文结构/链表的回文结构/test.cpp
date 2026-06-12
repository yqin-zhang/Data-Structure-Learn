#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>
using namespace std;

typedef struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}LTNode;

class PalindromeList {
public:
	//找到中间节点
	ListNode* findMiddle(ListNode*head)
	{
		ListNode* slow, * fast;
		slow = fast = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
	//反转链表
	ListNode* reverseNode(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* curr = head;

		while (curr) {
			ListNode* next = curr->next;  // 保存下一个节点
			curr->next = prev;            // 反转指针
			prev = curr;                  // 移动 prev
			curr = next;                  // 移动 curr
		}
		return prev;  // prev 是新的头节点
	}
		

	bool chkPalindrome(ListNode* A) {

		//先找到中间节点
		ListNode* middle = findMiddle(A);
		//反转
		ListNode* cur = reverseNode(middle);
		//条件，与middle相等代表成功，反之失败
		ListNode* p, * q;
		p = A;
		q = cur;
		while (p != middle)
		{
			if (p->val != q->val)
			{
				return false;
			}
			q = q->next;
			p = p->next;
		}
		return true;
	}
};

int main()
{
	// 构建参数：链表
	LTNode* n1 = (LTNode*)malloc(sizeof(LTNode));
	LTNode* n2 = (LTNode*)malloc(sizeof(LTNode));
	LTNode* n3 = (LTNode*)malloc(sizeof(LTNode));
	LTNode* n4 = (LTNode*)malloc(sizeof(LTNode));
	LTNode* n5 = (LTNode*)malloc(sizeof(LTNode));
	LTNode* n6 = (LTNode*)malloc(sizeof(LTNode));

	// 设置节点值（回文结构：1→4→3→3→4→1）
	n1->val = 1;
	n2->val = 4;
	n3->val = 3;
	n4->val = 3;  // 改成3
	n5->val = 4;  // 改成4
	n6->val = 1;  // 改成1

	// 连接节点
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;

	PalindromeList s;
	s.chkPalindrome(n1);
	return 0;
}
