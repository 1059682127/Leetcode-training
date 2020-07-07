//lt234

/*
��������

���ж�һ�������Ƿ�Ϊ��������
ʾ�� 1:
����: 1->2
���: false
ʾ�� 2:
����: 1->2->2->1
���: true
���ף�
���ܷ��� O(n) ʱ�临�ӶȺ� O(1) �ռ临�ӶȽ�����⣿

//˼·1������+˫ָ��
//˼·2���ݹ�
*/


class Solution {
public:
	//˼·1������+˫ָ��
	//˼·2���ݹ�
	//����ʹ�õݹ����ŵķ�����ʽڵ�
	//ͬ������ʹ�õݹ鷴�������ͬʱʹ�õݹ�֮���ָ����ǰ�������ж��Ƿ�Ϊ����
	//֮���������õ�ԭ���ǵݹ鴦��ڵ��˳�����෴�ģ���ס�����ӡ���㷨�������ڵݹ飬�ӱ����ϣ�����ͬʱ����������������
	//https://leetcode-cn.com/problems/palindrome-linked-list/solution/hui-wen-lian-biao-by-leetcode/
	//��ʵ���ǰѺ���push��ջ���������ݹ鵽���pop

	//����������ʽڵ�
	void inverse(ListNode* head) {
		if (head) {
			inverse(head->next);
			cout << head->val;
		}
	}
	bool backCheck(ListNode* node) {
		if (!node) return true;
		//�ߵ�β������ʼ�������
		if (!backCheck(node->next)) return false;
		if (node->val != forward->val) return false;
		forward = forward->next;
		return true;
	}
	ListNode* forward;
	bool isPalindrome(ListNode* head) {
		forward = head;
		return backCheck(head);
	}
};