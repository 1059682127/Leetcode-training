/*
题目描述
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
	//递归
	vector<int> res;
	vector<int> printListFromTailToHead(ListNode* head) {
		dfs(head);
		return res;
	}
	void dfs(ListNode* head) {
		if (head == NULL) return;
		dfs(head->next);
		res.push_back(head->val);
	}
};