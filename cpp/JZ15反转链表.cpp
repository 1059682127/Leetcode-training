/*
��Ŀ����
����һ��������ת��������������ı�ͷ��
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	//˫ָ��
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL) return NULL;
		ListNode *first = pHead, *second = pHead->next, *temp = first;
		first->next = NULL;
		while (second) {
			temp = second;
			second = second->next;
			temp->next = first;
			first = temp;
		}
		return temp;
	}
};