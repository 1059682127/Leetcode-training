//lt382

/*
��ż����

����һ�������������е������ڵ��ż���ڵ�ֱ�����һ����ע�⣬����������ڵ��ż���ڵ�ָ���ǽڵ��ŵ���ż�ԣ������ǽڵ��ֵ����ż�ԡ�
�볢��ʹ��ԭ���㷨��ɡ�����㷨�Ŀռ临�Ӷ�ӦΪ O(1)��ʱ�临�Ӷ�ӦΪ O(nodes)��nodes Ϊ�ڵ�������
ʾ�� 1:
����: 1->2->3->4->5->NULL
���: 1->3->5->2->4->NULL
ʾ�� 2:
����: 2->1->3->5->6->4->7->NULL
���: 2->3->6->7->1->5->4->NULL

//˼·1��˫ָ��
*/



class Solution {
public:
	//˼·1��˫ָ��
	//���壺odd��evenָ��
	ListNode* oddEvenList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* oddHead = head;
		ListNode* evenHead = head->next;
		ListNode* odd = oddHead;
		ListNode* even = evenHead;
		while (odd && even && odd->next && even->next) {
			odd->next = odd->next->next;
			even->next = even->next->next;
			odd = odd->next;
			even = even->next;
		}
		odd->next = evenHead;
		return oddHead;
	}
};