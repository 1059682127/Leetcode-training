//lt������24

/*
��ת����

��תһ��������
ʾ��:
����: 1->2->3->4->5->NULL
���: 5->4->3->2->1->NULL

//˼·1���ƽ��+����,ÿ�ζ���Ԫ���Ƶ���ǰ�棬����ɾ���Ͳ������
//˼·2��˫ָ�룺����ɾ�����������ֱ�ӷ�ת
//˼·3���ݹ�

������վ��https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/solution/fan-zhuan-lian-biao-yi-dong-de-shuang-zhi-zhen-jia/
*/

//ִ����ʱ:8 ms, ������ C++ �ύ�л�����71.32%���û�
//�ڴ����� :9.3 MB, ������ C++ �ύ�л�����100.00%���û�
class Solution {
public:
	//˼·1���ƽ��+����,ÿ�ζ���Ԫ���Ƶ���ǰ�棬����ɾ���Ͳ������
	ListNode* reverseList(ListNode* head) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode *p = NULL, *cur = dummy->next;
		while (cur && cur->next) {
			//ɾ��cur->next
			p = cur->next;
			cur->next = p->next;
			//���뵽ͷ���֮ǰ
			p->next = dummy->next;
			dummy->next = p;
			//     cur = cur->next; //��ס������֮�󼴿�
		}
		return dummy->next;
	}
};


class Solution {
public:
	//˼·2��˫ָ�룺����ɾ�����������ֱ�ӷ�ת
	//��������ָ�룺pre��cur,pre��ǰ,cur�ں�
	//ÿ����pre��nextָ��cur��ʵ��һ�ξֲ���ת
	//�ֲ���ת��ɺ�pre��nextͬʱ�ƶ�һ��λ��
	//��pre��������β��������
	ListNode* reverseList(ListNode* head) {
		ListNode *cur = NULL, *pre = head;
		while (pre) {
			//�ֲ���ת
			ListNode* temp = pre->next;
			pre->next = cur;
			//ǰ��һ��
			cur = pre;
			pre = temp;
		}
		return cur;
	}
};

class Solution {
public:
	//˼·3:�ݹ�
	//�ڵ�head�������ݹ���ָ��ǰ�ڵ㣬��ǰ�ڵ�ָ��NULL��

	//�൱�ڵݹ鵽���һ����㣬�ý����Ƿ�ת���ͷ��㣬����ret
	//ÿ�κ�������ʱ���õ�ǰ�ڵ����һ�ڵ��nextָ��ָ��ǰ�ڵ�
	//ͬʱ�õ�ǰ�ڵ��nextָ��ָ��NULL
	//���ݹ麯��ȫ����ջ����ת���
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head; //�ݹ��˳�������
		ListNode* ret = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return ret;
	}
};
