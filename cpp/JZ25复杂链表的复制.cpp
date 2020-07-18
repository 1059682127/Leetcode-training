/*
题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），请对此链表进行深拷贝，并返回拷贝后的头结点。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
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
	//思路：哈希表
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL) return NULL;
		RandomListNode* pHeadClone = new RandomListNode(pHead->label);  //复制首节点
		unordered_map<RandomListNode*, RandomListNode*> map;
		map[pHead] = pHeadClone;  //记录
		RandomListNode* pCurClone = pHeadClone;
		while (pHead) {
			//复制下一节点
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
			//复制随机节点
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