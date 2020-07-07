//lt面试题24

/*
反转链表

反转一个单链表。
示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

//思路1：哑结点+遍历,每次都把元素移到最前面，包括删除和插入操作
//思路2：双指针：不用删除插入操作，直接反转
//思路3：递归

优秀网站：https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/solution/fan-zhuan-lian-biao-yi-dong-de-shuang-zhi-zhen-jia/
*/

//执行用时:8 ms, 在所有 C++ 提交中击败了71.32%的用户
//内存消耗 :9.3 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
	//思路1：哑结点+遍历,每次都把元素移到最前面，包括删除和插入操作
	ListNode* reverseList(ListNode* head) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode *p = NULL, *cur = dummy->next;
		while (cur && cur->next) {
			//删除cur->next
			p = cur->next;
			cur->next = p->next;
			//插入到头结点之前
			p->next = dummy->next;
			dummy->next = p;
			//     cur = cur->next; //记住，交换之后即可
		}
		return dummy->next;
	}
};


class Solution {
public:
	//思路2：双指针：不用删除插入操作，直接反转
	//定义两个指针：pre和cur,pre在前,cur在后
	//每次让pre的next指向cur，实现一次局部反转
	//局部反转完成后，pre和next同时移动一个位置
	//当pre到达链表尾部，结束
	ListNode* reverseList(ListNode* head) {
		ListNode *cur = NULL, *pre = head;
		while (pre) {
			//局部反转
			ListNode* temp = pre->next;
			pre->next = cur;
			//前进一步
			cur = pre;
			pre = temp;
		}
		return cur;
	}
};

class Solution {
public:
	//思路3:递归
	//节点head操作（递归结果指向当前节点，当前节点指向NULL）

	//相当于递归到最后一个结点，该结点就是反转后的头结点，记作ret
	//每次函数返回时，让当前节点的下一节点的next指针指向当前节点
	//同时让当前节点的next指针指向NULL
	//当递归函数全部出栈，反转完成
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head; //递归退出的条件
		ListNode* ret = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return ret;
	}
};
