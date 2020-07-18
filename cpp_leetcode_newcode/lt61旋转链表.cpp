//lt61

/*
旋转链表

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
示例 1:
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:
输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

//思路1：分割+双指针
//思路2：(推荐，思路清晰)双指针（成环纯移动）

*/


//执行用时:4 ms, 在所有 C++ 提交中击败了98.55%的用户
//内存消耗 :9.1 MB, 在所有 C++ 提交中击败了5.17%的用户
class Solution {
public:
	//思路1：分割+双指针
	//先定位到分割点4的前一节点（参考：删除链表倒数第N个节点：双指针）
	//然后1->2->3与4->5换位

	//fist指向dummy, second往前走k个位置；
	//如果length >= k, second先走k步（first与second相隔k-1个节点），然后两指针同步前进知道second->NULL==NULL，此时first走到分割点4的前一节点
	//如果length < k, second提前走到尾处,记录已经走的步数，即为length，分割点在倒数k%length个节点处，second不动，first再移动(length - (k/length))步即走到分割点的前一节点
	//至此，first在分割点的前一节点，second在尾结点，交换位置
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !head->next) return head;
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode *first = dummy, *second = dummy;
		//i统计second走的步数
		int i = 0;
		for (; i < k; ++i) {
			if (second->next) {
				second = second->next;
			}
			else {
				break;
			}
		}
		//如果second走到末尾
		if (!second->next) {
			int length = i;
			for (int j = 0; j < length - k % length; j++) {
				first = first->next;
			}
		}
		else {
			while (second->next) {
				first = first->next;
				second = second->next;
			}
		}
		//至此，first在分割点的前一节点，second在尾结点，交换位置
		second->next = head;
		dummy->next = first->next;
		first->next = NULL;
		return dummy->next;
	}
};

//执行用时:8 ms, 在所有 C++ 提交中击败了83.73%的用户
//内存消耗 :9.1 MB, 在所有 C++ 提交中击败了5.17%的用户
class Solution {
public:
	//思路2：双指针（成环纯移动）
	//设立一个头指针和尾指针，遍历一次链表得到链表的长度l。并将尾指针的next指向头指针，同时将head指针和尾指针向后移动L-k%length个元素，返回新head
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !head->next) return head;
		ListNode *first = head, *second = head;
		int length = 1;
		//如果second走到末尾
		while (second->next) {
			second = second->next;
			++length;
		}
		//将second的next指针指向head,成环
		second->next = head;
		for (int i = 0; i < length - k % length; ++i) {
			first = first->next;
			second = second->next;
		}
		//断开环
		second->next = NULL;
		return first;

	}
};