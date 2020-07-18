/*
��Ŀ����
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��randomָ��һ������ڵ㣩����Դ������������������ؿ������ͷ��㡣��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
*/

/*
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};
*/
class Solution {
public:
	//˼·����ϣ��
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL) return NULL;
		RandomListNode* pHeadClone = new RandomListNode(pHead->label);  //�����׽ڵ�
		unordered_map<RandomListNode*, RandomListNode*> map;
		map[pHead] = pHeadClone;  //��¼
		RandomListNode* pCurClone = pHeadClone;
		while (pHead) {
			//������һ�ڵ�
			if (pHead->next) {
				if (map[pHead->next]) {
					pCurClone->next = map[pHead->next];
				}
				else {
					RandomListNode* pNextClone = new RandomListNode(pHead->next->label);
					pCurClone->next = pNextClone;
					map[pHead->next] = pNextClone;
				}
			}
			//��������ڵ�
			if (pHead->random) {
				if (map[pHead->random]) {
					pCurClone->random = map[pHead->random];
				}
				else {
					RandomListNode* pRandomClone = new RandomListNode(pHead->random->label);
					pCurClone->random = pRandomClone;
					map[pHead->random] = pRandomClone;
				}
			}
			pHead = pHead->next;
			pCurClone = pCurClone->next;
		}
		return pHeadClone;
	}
};