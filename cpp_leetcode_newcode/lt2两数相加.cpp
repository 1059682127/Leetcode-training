//lt2

/*
两数相加

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

//思路1：递归(标记进位)
//思路2：(推荐，思路清晰)新链表+哑结点
*/



class Solution {
public:
	//思路1：递归(标记进位)
	//O(MAX(M,N))/O(MAX(M,N))
	//每次都用l1和l2链首元素+进位，再到新的首元素+新的进位，再接上addTwo(l1->next, l2->next, int carry)结果
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		return addTwo(l1, l2, 0);
	}
	ListNode* addTwo(ListNode* l1, ListNode* l2, int carry) {
		//递归结束条件,注意进位
		if (l1 == NULL && l2 == NULL) {
			if (carry > 0) {
				return new ListNode(carry);
			}
			else {
				return NULL;
			}
		}
		if (l1 == NULL && l2 != NULL) {
			if (carry == 0) return l2;
			int value = l2->val + carry;
			if (value == 10) {
				l2->val = 0;
				l2->next = addTwo(NULL, l2->next, 1);
				return l2;
			}
			else {
				l2->val = value;
				l2->next = addTwo(NULL, l2->next, 0);
				return l2;
			}
		}
		if (l1 != NULL && l2 == NULL) {
			if (carry == 0) return l1;
			int value = l1->val + carry;
			if (value == 10) {
				l1->val = 0;
				l1->next = addTwo(l1->next, NULL, 1);
				return l1;
			}
			else {
				l1->val = value;
				l1->next = addTwo(l1->next, NULL, 0);
				return l1;
			}
		}
		int value = l1->val + l2->val + carry;
		//产生进位
		if (value >= 10) {
			carry = 1;
			l1->val = value - 10;
			l1->next = addTwo(l1->next, l2->next, 1);
			return l1;
		}
		else {
			carry = 0;
			l1->val = value;
			l1->next = addTwo(l1->next, l2->next, 0);
			return l1;
		}
	}
};


//执行用时:12 ms, 在所有 C++ 提交中击败了99.24%的用户
//内存消耗 :10.5 MB, 在所有 C++ 提交中击败了5.24%的用户
class Solution {
public:
	//思路2：新链表+哑结点
	//一直遍历到两列表末尾，如果p==NULL，其值为0代替进行求和
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode *dummy = new ListNode(0), *p = l1, *q = l2;
		ListNode *cur = dummy;
		while (p != NULL || q != NULL) {
			int x = (p) ? p->val : 0;
			int y = (q) ? q->val : 0;
			int sum = x + y + carry;
			carry = sum / 10;
			cur->next = new ListNode(sum % 10);
			cur = cur->next;
			if (p) p = p->next;
			if (q) q = q->next;
		}
		if (carry == 1) {
			cur->next = new ListNode(1);
		}
		return dummy->next;
	}

};