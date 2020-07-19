
/*
题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
*/
class Solution {
public:
	//思路：快慢指针
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (!pHead || !pHead->next) return NULL;
		ListNode *fast = pHead, *slow = pHead;
		fast = fast->next->next;
		slow = slow->next;
		while (slow != fast) {
			if (!fast || !fast->next) return NULL;
			fast = fast->next->next;
			slow = slow->next;
		}
		//快慢指针同步
		fast = pHead;
		while (fast != slow) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};