
/*
��Ŀ����
��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null��
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
*/
class Solution {
public:
	//˼·������ָ��
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (!pHead || !pHead->next) return NULL;
		ListNode *fast = pHead, *slow = pHead;
		fast = fast->next->next;
		slow = slow->next;
		while (slow != fast) {
			if (!fast || !fast->next) return NULL;
			fast = fast->next->next;
			slow = slow->next;
		}
		//����ָ��ͬ��
		fast = pHead;
		while (fast != slow) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};