/*
��Ŀ����
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
*/


/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
*/
class Solution {
public:
	//ָ�����
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (!pHead || !pHead->next) return pHead;
		ListNode* dummy = new ListNode(0);
		dummy->next = pHead;
		ListNode *pre = dummy, *cur = pHead;
		while (cur) {
			if (cur->next && cur->val == cur->next->val) {
				while (cur->next && cur->val == cur->next->val) {
					cur = cur->next;
				}
				//�����ͬ�Ĳ���
				cur = cur->next;
				pre->next = cur;
				// pre = pre->next;
			}
			else {
				cur = cur->next;
				pre = pre->next;
			}
		}
		return dummy->next;
	}
};