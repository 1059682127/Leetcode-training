//lt203
/*
移除链表元素

删除链表中等于给定值 val 的所有节点。
示例:
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5

//思路：哑结点+遍历
*/

//执行用时:20 ms, 在所有 C++ 提交中击败了93.07%的用户
//内存消耗 :11.1 MB, 在所有 C++ 提交中击败了32.69%的用户
class Solution {
public:
	//思路：哑结点+遍历(可初始化两个指针，一个指向当前节点，一个指向后继节点)
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* cur = dummy;
		while (cur != NULL && cur->next != NULL) {
			ListNode* temp = cur->next;
			//找到不为val的节点
			while (temp && temp->val == val) {
				temp = temp->next;
			}
			cur->next = temp;
			cur = cur->next;
		}
		return dummy->next;
	}
};