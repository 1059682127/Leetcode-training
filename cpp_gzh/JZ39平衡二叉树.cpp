/*
 算法知识视频讲解
题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。

在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
*/

class Solution {
public:
	//平衡二叉树，子树高度差不大于1
	//递归，自底向上
	int TreeDepth(TreeNode* pRoot)
	{
		if (!pRoot) return 0;
		int l = TreeDepth(pRoot->left);
		int r = TreeDepth(pRoot->right);
		if (l == -1 || r == -1 || abs(l - r) > 1) return -1;
		return max(l, r) + 1;
	}
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int res = TreeDepth(pRoot);
		return res != -1;
	}
};