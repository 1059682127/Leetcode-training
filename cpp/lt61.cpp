//lt61

/*
��ת����

����һ��������ת����������ÿ���ڵ������ƶ� k ��λ�ã����� k �ǷǸ�����
ʾ�� 1:
����: 1->2->3->4->5->NULL, k = 2
���: 4->5->1->2->3->NULL
����:
������ת 1 ��: 5->1->2->3->4->NULL
������ת 2 ��: 4->5->1->2->3->NULL
ʾ�� 2:
����: 0->1->2->NULL, k = 4
���: 2->0->1->NULL
����:
������ת 1 ��: 2->0->1->NULL
������ת 2 ��: 1->2->0->NULL
������ת 3 ��: 0->1->2->NULL
������ת 4 ��: 2->0->1->NULL

//˼·1���ָ�+˫ָ��
//˼·2��(�Ƽ���˼·����)˫ָ�루�ɻ����ƶ���

*/


//ִ����ʱ:4 ms, ������ C++ �ύ�л�����98.55%���û�
//�ڴ����� :9.1 MB, ������ C++ �ύ�л�����5.17%���û�
class Solution {
public:
	//˼·1���ָ�+˫ָ��
	//�ȶ�λ���ָ��4��ǰһ�ڵ㣨�ο���ɾ����������N���ڵ㣺˫ָ�룩
	//Ȼ��1->2->3��4->5��λ

	//fistָ��dummy, second��ǰ��k��λ�ã�
	//���length >= k, second����k����first��second���k-1���ڵ㣩��Ȼ����ָ��ͬ��ǰ��֪��second->NULL==NULL����ʱfirst�ߵ��ָ��4��ǰһ�ڵ�
	//���length < k, second��ǰ�ߵ�β��,��¼�Ѿ��ߵĲ�������Ϊlength���ָ���ڵ���k%length���ڵ㴦��second������first���ƶ�(length - (k/length))�����ߵ��ָ���ǰһ�ڵ�
	//���ˣ�first�ڷָ���ǰһ�ڵ㣬second��β��㣬����λ��
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !head->next) return head;
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode *first = dummy, *second = dummy;
		//iͳ��second�ߵĲ���
		int i = 0;
		for (; i < k; ++i) {
			if (second->next) {
				second = second->next;
			}
			else {
				break;
			}
		}
		//���second�ߵ�ĩβ
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
		//���ˣ�first�ڷָ���ǰһ�ڵ㣬second��β��㣬����λ��
		second->next = head;
		dummy->next = first->next;
		first->next = NULL;
		return dummy->next;
	}
};

//ִ����ʱ:8 ms, ������ C++ �ύ�л�����83.73%���û�
//�ڴ����� :9.1 MB, ������ C++ �ύ�л�����5.17%���û�
class Solution {
public:
	//˼·2��˫ָ�루�ɻ����ƶ���
	//����һ��ͷָ���βָ�룬����һ������õ�����ĳ���l������βָ���nextָ��ͷָ�룬ͬʱ��headָ���βָ������ƶ�L-k%length��Ԫ�أ�������head
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !head->next) return head;
		ListNode *first = head, *second = head;
		int length = 1;
		//���second�ߵ�ĩβ
		while (second->next) {
			second = second->next;
			++length;
		}
		//��second��nextָ��ָ��head,�ɻ�
		second->next = head;
		for (int i = 0; i < length - k % length; ++i) {
			first = first->next;
			second = second->next;
		}
		//�Ͽ���
		second->next = NULL;
		return first;

	}
};