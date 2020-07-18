//lt21
/*
�ϲ�������������

��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
ʾ����
���룺1->2->4, 1->3->4
�����1->1->2->3->4->4
//˼·1��˫ָ��,l1���ƽ��
//˼·2���ݹ�
*/

class Solution {
public:
	//˼·1��˫ָ��,l1���ƽ��
	//���first->next->val < second->val, first = first->next;����second�ڵ���뵽first��first->next֮��,first = first->next, second = second->next;
	//����l2�����һ�νӵ�l1��
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
				//�ȼ���second�ڵ㣬ע�����ǰ�Ƚ�secondָ��next�ڵ�
				ListNode* p = second;
				second = second->next;
				//�ڵ�������
				p->next = first->next;
				first->next = p;
				first = first->next;
			}
		}
		//first�ȵ�β��first->next == NULL
		if (first->next == NULL) first->next = second;
		//second�ȵ�β����ʲô�����ø�

		return dummy->next;
	}
};

//ִ����ʱ:8 ms, ������ C++ �ύ�л�����83.08%���û�
//�ڴ����� :9.1 MB, ������ C++ �ύ�л�����7.34%���û�
class Solution {
public:
	//˼·2���ݹ�
	//ÿ�εݹ飺��l1��l2��ͷ����С��Ԫ�ؽ���ʣ�����ϲ��Ľ��
	//if l1[0] < l2[0] :return l2[0] + merge(l1->next, l2);
	//else return l1[0] + mere(l1, l2->next);

	//O(N+M):��Ϊÿ�εݹ���û�ȥ��l1��l2��ͷԪ��
	//O(N+M):������M+N��ջ֡
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