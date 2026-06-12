#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>
using namespace std;

typedef struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}LTNode;
//创建哑巴节点——最佳实践
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		ListNode* dummy1 = new ListNode(0);
		ListNode* dummy2 = new ListNode(0);
		ListNode* cur = pHead;
		ListNode* minTail, * maxTail;
		minTail = maxTail = NULL;
		 minTail= dummy1;
		 maxTail=dummy2 ;

		 //到这里新链表就创建好了
		 while (cur)
		 {
			 if (cur->val < x)
			 {
				 minTail->next = cur;
				 minTail = cur;
			 }
			 else
			 {
				 maxTail->next = cur;
				 maxTail = cur;

			 }
			 cur = cur->next;

		 }
		 //到这里，注意置空
		 //if (minTail)
		 //{
			// minTail->next = NULL;
		 //}
		 //因为maxTail结尾，只需要它置空就行
		 if (maxTail)
		 {
			 maxTail->next = NULL;
		 }
		 //合并两个链表
		 //minTail maxTail
		 if (minTail && maxTail)
		 {
			 //第二个头结点的下一个位置开始
			 minTail->next = dummy2->next;
			 //这里minTail还是在原来的位置，不影响
		 }
		 //去掉头节点
		 return dummy1->next;
	}
};

int main()
{

	// 构建参数：链表
	LTNode* n1 = (LTNode*)malloc(sizeof(LTNode));
	LTNode* n2 = (LTNode*)malloc(sizeof(LTNode));
	LTNode* n3 = (LTNode*)malloc(sizeof(LTNode));
	LTNode* n4 = (LTNode*)malloc(sizeof(LTNode));
	LTNode* n5 = (LTNode*)malloc(sizeof(LTNode));  // 新增
	LTNode* n6 = (LTNode*)malloc(sizeof(LTNode));  // 新增

	// 设置节点值
	n1->val = 1;
	n2->val = 4;  // 7 → 4
	n3->val = 3;  // 2 → 3
	n4->val = 2;  // 7 → 2
	n5->val = 5;  // 新增
	n6->val = 2;  // 新增

	// 连接节点
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;  // 指向n5
	n5->next = n6;  // 指向n6
	n6->next = NULL;

	Partition s;
	int val = 3;
	s.partition(n1, 3);
	return 0;
}
