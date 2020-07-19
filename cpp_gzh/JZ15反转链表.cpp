/*
题目描述
输入一个链表，反转链表后，输出新链表的表头。
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	//双指针
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL) return NULL;
		ListNode *first = pHead, *second = pHead->next, *temp = first;
		first->next = NULL;
		while (second) {
			temp = second;
			second = second->next;
			temp->next = first;
			first = temp;
		}
		return temp;
	}
};