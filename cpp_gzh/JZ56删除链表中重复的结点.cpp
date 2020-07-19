/*
题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
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
	//指针遍历
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (!pHead || !pHead->next) return pHead;
		ListNode* dummy = new ListNode(0);
		dummy->next = pHead;
		ListNode *pre = dummy, *cur = pHead;
		while (cur) {
			if (cur->next && cur->val == cur->next->val) {
				while (cur->next && cur->val == cur->next->val) {
					cur = cur->next;
				}
				//跨过相同的部分
				cur = cur->next;
				pre->next = cur;
				// pre = pre->next;
			}
			else {
				cur = cur->next;
				pre = pre->next;
			}
		}
		return dummy->next;
	}
};