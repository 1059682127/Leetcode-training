/*
��Ŀ����
����һ����������������е�����k����㡣
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
	//�״����n��ʱ��second��β��ڵ�NULL
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode *first = pListHead, *second = pListHead;
		//���k - 1��
		for (int i = 0; i < k; ++i) {
			if (second) second = second->next;
			else return NULL;
		}
		//��ָ��ͬ����
		while (second) {
			first = first->next;
			second = second->next;
		}
		return first;
	}
};