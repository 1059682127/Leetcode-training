/*
��Ŀ����
����һ�������������β��ͷ��˳�򷵻�һ��ArrayList��
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
	//�ݹ�
	vector<int> res;
	vector<int> printListFromTailToHead(ListNode* head) {
		dfs(head);
		return res;
	}
	void dfs(ListNode* head) {
		if (head == NULL) return;
		dfs(head->next);
		res.push_back(head->val);
	}
};