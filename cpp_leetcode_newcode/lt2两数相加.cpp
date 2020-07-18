//lt2

/*
�������

�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�
�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��
ʾ����
���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807

//˼·1���ݹ�(��ǽ�λ)
//˼·2��(�Ƽ���˼·����)������+�ƽ��
*/



class Solution {
public:
	//˼·1���ݹ�(��ǽ�λ)
	//O(MAX(M,N))/O(MAX(M,N))
	//ÿ�ζ���l1��l2����Ԫ��+��λ���ٵ��µ���Ԫ��+�µĽ�λ���ٽ���addTwo(l1->next, l2->next, int carry)���
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		return addTwo(l1, l2, 0);
	}
	ListNode* addTwo(ListNode* l1, ListNode* l2, int carry) {
		//�ݹ��������,ע���λ
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
		//������λ
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


//ִ����ʱ:12 ms, ������ C++ �ύ�л�����99.24%���û�
//�ڴ����� :10.5 MB, ������ C++ �ύ�л�����5.24%���û�
class Solution {
public:
	//˼·2��������+�ƽ��
	//һֱ���������б�ĩβ�����p==NULL����ֵΪ0����������
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