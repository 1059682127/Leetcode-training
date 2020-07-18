//lt100
/*
100. 相同的树

给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1:

输入:       1         1
		  / \       / \
		 2   3     2   3

		[1,2,3],   [1,2,3]

输出: true

//思路1：递归
*/

class Solution {
public:
	//思路1：递归
	//相同方式遍历两个树，节点值都相同返true，否则返false
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) return true;
		if (p == NULL && q != NULL) return false;
		if (p != NULL && q == NULL) return false;
		return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};