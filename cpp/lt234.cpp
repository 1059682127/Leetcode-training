//lt234

/*
回文链表

请判断一个链表是否为回文链表。
示例 1:
输入: 1->2
输出: false
示例 2:
输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

//思路1：数组+双指针
//思路2：递归
*/


class Solution {
public:
	//思路1：数组+双指针
	//思路2：递归
	//可以使用递归优雅的反向访问节点
	//同理，可以使用递归反向迭代，同时使用递归之外的指针向前迭代，判断是否为回文
	//之所以起作用的原因是递归处理节点的顺序是相反的（记住上面打印的算法）。由于递归，从本质上，我们同时在正向和逆向迭代。
	//https://leetcode-cn.com/problems/palindrome-linked-list/solution/hui-wen-lian-biao-by-leetcode/
	//其实就是把函数push进栈，当遇到递归到最后pop

	//单纯反向访问节点
	void inverse(ListNode* head) {
		if (head) {
			inverse(head->next);
			cout << head->val;
		}
	}
	bool backCheck(ListNode* node) {
		if (!node) return true;
		//走到尾部，开始反向迭代
		if (!backCheck(node->next)) return false;
		if (node->val != forward->val) return false;
		forward = forward->next;
		return true;
	}
	ListNode* forward;
	bool isPalindrome(ListNode* head) {
		forward = head;
		return backCheck(head);
	}
};