//lt19
/*
删除链表的倒数第N个节点

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
示例：
给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：
给定的 n 保证是有效的。
进阶：
你能尝试使用一趟扫描实现吗？

//思路1：双指针
*/


class Solution {
public:
	//思路1：双指针
	//两指针间隔N个节点，然后同步运动，当hi指针指向尾结点的下一节点时，lo指针指向倒数第N个节点
	//Trick1:考虑到可能要去掉头结点，设计哑结点
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* lo = dummy;
		ListNode* hi = dummy;
		for (int i = 0; i < n; i++)
		{
			hi = hi->next;
		}
		//两指针同步移动，直到hi指向尾结点，去掉lo->next
		while (hi->next != NULL) {
			lo = lo->next;
			hi = hi->next;
		}
		lo->next = lo->next->next;
		return dummy->next;
	}
};