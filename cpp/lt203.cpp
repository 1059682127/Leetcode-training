//lt203
/*
�Ƴ�����Ԫ��

ɾ�������е��ڸ���ֵ val �����нڵ㡣
ʾ��:
����: 1->2->6->3->4->5->6, val = 6
���: 1->2->3->4->5

//˼·���ƽ��+����
*/

//ִ����ʱ:20 ms, ������ C++ �ύ�л�����93.07%���û�
//�ڴ����� :11.1 MB, ������ C++ �ύ�л�����32.69%���û�
class Solution {
public:
	//˼·���ƽ��+����(�ɳ�ʼ������ָ�룬һ��ָ��ǰ�ڵ㣬һ��ָ���̽ڵ�)
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* cur = dummy;
		while (cur != NULL && cur->next != NULL) {
			ListNode* temp = cur->next;
			//�ҵ���Ϊval�Ľڵ�
			while (temp && temp->val == val) {
				temp = temp->next;
			}
			cur->next = temp;
			cur = cur->next;
		}
		return dummy->next;
	}
};