/*
题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	TreeNode* pRoot;
	TreeNode* pPre;
	//思路：中序遍历
	void Inorder(TreeNode* cur) {
		if (cur == NULL) return;
		Inorder(cur->left);
		//打印节点
		//若是第一个节点
		if (pRoot == NULL) {
			pRoot = cur;
			pPre = cur;
		}
		else {
			pPre->right = cur;
			cur->left = pPre;
			pPre = cur;
		}
		Inorder(cur->right);
	}
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		pRoot = NULL;
		pPre = NULL;
		Inorder(pRootOfTree);
		return pRoot;
	}
};