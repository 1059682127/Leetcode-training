//lt141

/*
��������

����һ�������ж��������Ƿ��л���
Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� -1�����ڸ�������û�л���

//˼·1������+��ϣO(N)/O(N)
//˼·2������ָ��O(N)/O(1)
*/



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
	//˼·1������+��ϣ
	//�ù�ϣ���¼�Ѿ��������Ľڵ㣬���ָ��������Ľڵ㣬���ɻ�

	//֪ʶ�㣬���û�õ�cur->next�ĳ�Ա�������ж�cur->next != NULL, �Ѿ��ж���cur != NULL, ���Կ��Է���cur�ĳ�Աnext
	bool hasCycle(ListNode *head) {
		map<ListNode*, bool> isVisted;
		ListNode* cur = head;
		while (cur != NULL) {
			if (cur->next != NULL) {
				//�ж�ָ��Ľڵ��Ƿ������
				if (isVisted.count(cur->next)) return true;
				else {
					isVisted[cur->next] = true;
				}

			}
			cur = cur->next;
		}
		return false;
	}
};


//ִ����ʱ:16 ms, ������ C++ �ύ�л�����52.79%���û�
//�ڴ����� :9.8 MB, ������ C++ �ύ�л�����40.91%���û�
class Solution {
public:
	//˼·2������ָ��O(N)/O(1)
	//�ٶȲ�ͬ��ָ��ǰ���������������˶�Ա���ܵ����ܲ�������ָ��ÿ���ƶ���������ָ��ÿ���ƶ�һ��
	//������ɻ�����ָ�����ȵ���β��
	//����ɻ�����ָ���ڵڶ�Ȧ��ʱ���׷�Ͽ�ָ�룬�����һ�����ٵ���һ�ξ͸պ�׷�ϣ����������������ξ�׷�ϡ����������ɻ��Ļ���ָ�����ջ��ص�

	//֪ʶ�㣺
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) return false;

		ListNode* fast = head->next;  //Ϊ�˽���whileѭ������fastָ������һ��
		ListNode* slow = head;
		while (fast != slow) {
			if (fast == NULL || fast->next == NULL) return false; //���fastָ�����ߵ�ĩβ,���ж�fast->next�Ƿ�ΪNULL���ǵĻ�����·����
			//ǰ��
			fast = fast->next->next;
			slow = slow->next;
		}
		return true;
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
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while(pA != pB){
            pA = pA->next;
            pB = pB->next;
            //���˫˫�ߵ�ĩβ��û����
            if(pA == NULL && pB == NULL) return NULL;
            if(pA == NULL) pA = headB;
            if(pB == NULL) pB = headA;
        }
        return pA;
    }
};