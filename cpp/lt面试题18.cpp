//lt������18

/*
ɾ������Ľڵ�

�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣

����ɾ����������ͷ�ڵ㡣

ע�⣺����Ա�ԭ���иĶ�

ʾ�� 1:

����: head = [4,5,1,9], val = 5
���: [4,1,9]
����: ������������ֵΪ 5 �ĵڶ����ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 1 -> 9.


ʾ�� 2:

����: head = [4,5,1,9], val = 1
���: [4,5,9]
����: ������������ֵΪ 1 �ĵ������ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 5 -> 9.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

�汾1��val: int �ⷨO(N)/O(1)
�汾2��val: ListNode �ⷨ����Ϣ������O(1)/O(1)

//���ɣ�ͷ����ʹ��
*/

class Solution {
public:
	//ʹ��ͷ��㣬��һҪɾ����һ���n

	ListNode* deleteNode(ListNode* head, int val) {
		ListNode* dummyNode = new ListNode(0);
		dummyNode->next = head;
		ListNode* cur = dummyNode;
		while (cur != NULL && cur->next != NULL) {  //ע�����ж�cur != NULL,���ж�cur->next != NULL
			//������ɾ���ý��
			if (cur->next->val == val) {
				cur->next = cur->next->next;
			}
			cur = cur->next;
		}
		return dummyNode->next;
	}
	//val: ListNode �ⷨ����Ϣ������
	//���������Ϊɾ���Ľ��ʱ�����Բ�����Ϣ��������deleteNode->val = deleteNode->next->val; deleteNode->next = deleteNode->next->next;
	//��ɾ����㲻��β���ʱ������ʵ�ֳ���ʱ��ɾ��
	//��ɾ�������β��㣬�޷��ҵ�β���ĺ�һԪ�أ�������Ҫ��ͷ����
	//ʱ�临�Ӷ�:(O(1)*(N - 1) + 0(N))/N = O(1)

	ListNode* deleteNode2(ListNode* head, ListNode* deleteNode) {
		if (head == NULL || deleteNode == NULL) return NULL;
		if (deleteNode->next != NULL) {
			deleteNode->val = deleteNode->next->val;
			deleteNode->next = deleteNode->next->next;
		}
		//ͷβ�����ͬ
		else if (head == deleteNode) return NULL;
		else {
			ListNode* cur = head;
			//�ҵ������ڶ����
			while (cur->next != NULL && cur->next->next != NULL) {
				cur = cur->next;
			}
			cur->next = NULL;
		}
		return head;
	}
};