//lt142

/*
环形链表 II

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
说明：不允许修改给定的链表。

	//思路1：哈希表（需要额外的空间）
	//思路2：双指针，快慢指针
*/


class Solution {
public:
	//思路1：哈希表（需要额外的空间）
	//思路2：双指针，快慢指针
	//参考：https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
	//设：入口前链表长度为a，环形部分长度为b，slow,fast指针都从head出发
	//第一次相遇的时候，slow走了s步，fast走了f步，f = 2s, 且f = s + nb(多走了n圈)，得f = 2nb, s = nb
	//统计指针从head走到入口的步数：k = a + nb,所以slow指针第一次相遇之后再走a步就是环形入口了
	//第一次相遇后，fast指向head,fast,slow第二次相遇即为环形入口(此时两指针同速)
	//如果没有相遇fast走到NULL，则无环

	//知识点：用do while至少两指针走一次
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) return NULL;
		ListNode *slow = head, *fast = head;
		do {
			if (fast == NULL || fast->next == NULL) return NULL;
			slow = slow->next;
			fast = fast->next->next;
		} while (fast != slow);
		//同速运行直到第二次相遇
		fast = head;
		while (fast != slow) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};