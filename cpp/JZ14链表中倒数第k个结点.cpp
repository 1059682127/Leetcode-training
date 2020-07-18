/*
题目描述
输入一个链表，输出该链表中倒数第k个结点。
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
	//易错：间隔n步时，second到尾后节点NULL
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode *first = pListHead, *second = pListHead;
		//间隔k - 1步
		for (int i = 0; i < k; ++i) {
			if (second) second = second->next;
			else return NULL;
		}
		//两指针同步走
		while (second) {
			first = first->next;
			second = second->next;
		}
		return first;
	}
};