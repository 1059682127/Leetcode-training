//lt19
/*
ɾ������ĵ�����N���ڵ�

����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣
ʾ����
����һ������: 1->2->3->4->5, �� n = 2.

��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.
˵����
������ n ��֤����Ч�ġ�
���ף�
���ܳ���ʹ��һ��ɨ��ʵ����

//˼·1��˫ָ��
*/


class Solution {
public:
	//˼·1��˫ָ��
	//��ָ����N���ڵ㣬Ȼ��ͬ���˶�����hiָ��ָ��β������һ�ڵ�ʱ��loָ��ָ������N���ڵ�
	//Trick1:���ǵ�����Ҫȥ��ͷ��㣬����ƽ��
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* lo = dummy;
		ListNode* hi = dummy;
		for (int i = 0; i < n; i++)
		{
			hi = hi->next;
		}
		//��ָ��ͬ���ƶ���ֱ��hiָ��β��㣬ȥ��lo->next
		while (hi->next != NULL) {
			lo = lo->next;
			hi = hi->next;
		}
		lo->next = lo->next->next;
		return dummy->next;
	}
};