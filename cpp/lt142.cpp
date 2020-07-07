//lt142

/*
�������� II

����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� -1�����ڸ�������û�л���
˵�����������޸ĸ���������

	//˼·1����ϣ����Ҫ����Ŀռ䣩
	//˼·2��˫ָ�룬����ָ��
*/


class Solution {
public:
	//˼·1����ϣ����Ҫ����Ŀռ䣩
	//˼·2��˫ָ�룬����ָ��
	//�ο���https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
	//�裺���ǰ������Ϊa�����β��ֳ���Ϊb��slow,fastָ�붼��head����
	//��һ��������ʱ��slow����s����fast����f����f = 2s, ��f = s + nb(������nȦ)����f = 2nb, s = nb
	//ͳ��ָ���head�ߵ���ڵĲ�����k = a + nb,����slowָ���һ������֮������a�����ǻ��������
	//��һ��������fastָ��head,fast,slow�ڶ���������Ϊ�������(��ʱ��ָ��ͬ��)
	//���û������fast�ߵ�NULL�����޻�

	//֪ʶ�㣺��do while������ָ����һ��
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) return NULL;
		ListNode *slow = head, *fast = head;
		do {
			if (fast == NULL || fast->next == NULL) return NULL;
			slow = slow->next;
			fast = fast->next->next;
		} while (fast != slow);
		//ͬ������ֱ���ڶ�������
		fast = head;
		while (fast != slow) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};