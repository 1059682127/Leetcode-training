/*
题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
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
	//如果该节点有右子树，则下一节点为右子树的最左节点
	//如果该节点无右子树，且在其父节点的左子树上，则下一节点是其父节点
	//如果该节点无右子树，且在其父节点的右子树上，则向上找到一节点在其父节点的左子树上，该节点的父节点为下一节点
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