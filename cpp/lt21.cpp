//lt21
/*
合并两个有序链表

将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
//思路1：双指针,l1设哑结点
//思路2：递归
*/

class Solution {
public:
	//思路1：双指针,l1设哑结点
	//如果first->next->val < second->val, first = first->next;否则将second节点插入到first与first->next之间,first = first->next, second = second->next;
	//最后把l2多余的一段接到l1上
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode* dummy = new ListNode(0);
		dummy->next = l1;
		ListNode* first = dummy;
		ListNode* second = l2;
		while (first->next && second) {
			if (first->next->val < second->val) first = first->next;
			else {
				//先剪切second节点，注意剪切前先将second指向next节点
				ListNode* p = second;
				second = second->next;
				//节点插入操作
				p->next = first->next;
				first->next = p;
				first = first->next;
			}
		}
		//first先到尾部first->next == NULL
		if (first->next == NULL) first->next = second;
		//second先到尾部，什么都不用干

		return dummy->next;
	}
};

//执行用时:8 ms, 在所有 C++ 提交中击败了83.08%的用户
//内存消耗 :9.1 MB, 在所有 C++ 提交中击败了7.34%的用户
class Solution {
public:
	//思路2：递归
	//每次递归：用l1和l2中头部较小的元素接上剩余链合并的结果
	//if l1[0] < l2[0] :return l2[0] + merge(l1->next, l2);
	//else return l1[0] + mere(l1, l2->next);

	//O(N+M):因为每次递归调用会去掉l1或l2的头元素
	//O(N+M):会消耗M+N个栈帧
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};