/*
��Ŀ����
�������������ҳ����ǵĵ�һ��������㡣��ע����Ϊ�����������������Դ���������ݵ���ʾ����������ʽ��ʾ�ģ���֤������������ȷ�ģ�
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
	//˼·1����ϣ��
	//˼·2���й����ڵ㣬β�����ͬ����ͳ�Ƴ��ȣ�����len2 - len1����Ȼ��һ���ߣ�ֱ������
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (!pHead1 || !pHead2) return NULL;
		ListNode *cur1 = pHead1, *cur2 = pHead2;
		//ͳ�Ƴ���
		int len1 = 1, len2 = 1;
		while (cur1->next) {
			++len1;
			cur1 = cur1->next;
		}
		while (cur2->next) {
			++len2;
			cur2 = cur2->next;
		}
		if (cur1 != cur2) return NULL;
		cur1 = pHead1, cur2 = pHead2;
		if (len1 < len2) {
			for (int i = 0; i < len2 - len1; ++i) {
				cur2 = cur2->next;
			}
		}
		else {
			for (int i = 0; i < len1 - len2; ++i) {
				cur1 = cur1->next;
			}
		}
		//ͬ����ֱ������
		while (cur1) {
			if (cur1 == cur2) return cur1;
			else {
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
		}
	}
};