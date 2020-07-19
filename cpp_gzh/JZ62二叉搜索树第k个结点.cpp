/*
二叉搜索树第k个结点

题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/
class Solution {
public:
	//中序遍历第k个数
	int index;
	TreeNode* res;
	void Inorder(TreeNode* pRoot, int k) {
		if (!pRoot) return;
		Inorder(pRoot->left, k);
		++index;
		if (index == k) {
			res = pRoot;
			return;
		}
		Inorder(pRoot->right, k);
	}
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		index = 0;
		res = NULL;
		Inorder(pRoot, k);
		return res;
	}


};