/*
��Ŀ����
����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
*/



/*
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};
*/
class Solution {
public:
	//����ýڵ���������������һ�ڵ�Ϊ������������ڵ�
	//����ýڵ����������������丸�ڵ���������ϣ�����һ�ڵ����丸�ڵ�
	//����ýڵ����������������丸�ڵ���������ϣ��������ҵ�һ�ڵ����丸�ڵ���������ϣ��ýڵ�ĸ��ڵ�Ϊ��һ�ڵ�
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode->right) {
			TreeLinkNode *pNext = pNode->right;
			while (pNext->left) pNext = pNext->left;
			return pNext;
		}
		if (pNode->next && pNode->next->left == pNode) return pNode->next;
		if (pNode->next) {
			TreeLinkNode *pNext = pNode->next;
			while (pNext->next && pNext->next->right == pNext) {
				pNext = pNext->next;
			}
			return pNext->next;
		}
		return NULL;
	}
};