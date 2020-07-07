//lt160


/*
 �ཻ����

��дһ�������ҵ������������ཻ����ʼ�ڵ㡣

//˼·1����ϣ��:O(m+n)/O(m)
//˼·2��˫ָ��
*/

class Solution {
public:
	//˼·1����ϣ��:O(m+n)/O(m)
	//��������A����A��ÿ���ڵ��¼�ڹ�ϣ���У�Ȼ���������B����B�еĽڵ��Ƿ��ڹ�ϣ���У��ڵĻ�Ϊ�ཻ
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL) return NULL;
		map<ListNode*, bool> isExisted;
		ListNode* cur = headA;
		while (cur != NULL) {
			isExisted[cur] = true;
			cur = cur->next;
		}
		//��������B
		cur = headB;
		while (cur != NULL) {
			if (isExisted.count(cur)) return cur;
			else cur = cur->next;
		}
		return NULL;
	}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	//˼·1��˫ָ��
	//A��B���������ȿ��ܲ�ͬ������A+B��B+A�ĳ�������ͬ�ģ����Ա���A+B�ͱ���B+Aһ����ͬʱ������ 
	//���A,B�ཻ�Ļ�A��B��һ��β������ͬ�ģ���������������ָ��һ����ͬʱ���ｻ�� 
	//���A,B���ཻ�Ļ�����ָ��ͻ�ͬʱ����A+B��B+A����β�ڵ�

	//pA��ʼ��ָ��A��ͷ��㣬pBָ��B��ͷ��㣬Ȼ�������pA�ߵ�β���֮���ض�λָ������Bͷ��㣬pB�ߵ�β���֮���ض�λָ������Aͷ���
	//����A+B= B+A,pA,pB���ջ�ͬʱ�ߵ�β��㣬����м��ཻ����pA���pB��ǰ����
	//return pA,pB���������Ľڵ�,
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL) return NULL;
		ListNode* pA = headA;
		ListNode* pB = headB;
		while (pA != pB) {
			pA = pA->next;
			pB = pB->next;
			//���˫˫�ߵ�ĩβ��û����
			if (pA == NULL && pB == NULL) return NULL;
			if (pA == NULL) pA = headB;
			if (pB == NULL) pB = headA;
		}
		return pA;
	}
};