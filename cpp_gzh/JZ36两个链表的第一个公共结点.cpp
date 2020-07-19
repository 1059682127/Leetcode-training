/*
题目描述
输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	//思路1：哈希表
	//思路2：有公共节点，尾结点相同，且统计长度，先走len2 - len1步，然后一起走，直到相遇
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (!pHead1 || !pHead2) return NULL;
		ListNode *cur1 = pHead1, *cur2 = pHead2;
		//统计长度
		int len1 = 1, len2 = 1;
		while (cur1->next) {
			++len1;
			cur1 = cur1->next;
		}
		while (cur2->next) {
			++len2;
			cur2 = cur2->next;
		}
		if (cur1 != cur2) return NULL;
		cur1 = pHead1, cur2 = pHead2;
		if (len1 < len2) {
			for (int i = 0; i < len2 - len1; ++i) {
				cur2 = cur2->next;
			}
		}
		else {
			for (int i = 0; i < len1 - len2; ++i) {
				cur1 = cur1->next;
			}
		}
		//同步走直到相遇
		while (cur1) {
			if (cur1 == cur2) return cur1;
			else {
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
		}
	}
};