//lt124
/*
124. 二叉树中的最大路径和

给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

	   1
	  / \
	 2   3

输出: 6


示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
	/  \
   15   7

输出: 42

//思路1：自底向上递归
*/


class Solution {
public:
	//思路1：自底向上递归
	//树看作一个无向图，找其中最大的路径
	//经过根节点最大路径，就是root->val + 左子树最长路径 + 右子树最长路径
	//考虑左右子树最长路径可能小于0，所以经过一个节点的最长路径=root-> + max(0, 左子树最长路径) + max(0, 右子树最长路径)
	//求树的最长路径，就是自己的值 + max(0, 左子树最长路径， 右子树最长路径)

	//递归函数helper，以当前节点为根节点的最长路径，同时计算经过当前节点的最长路径cur,更新经过节点的最长路径res 

	//O(N)/O(logN)
	int res;
	int maxPathSum(TreeNode* root) {
		res = INT_MIN;
		helper(root);
		return res;
	}
	int helper(TreeNode* root) {
		if (root == NULL) return 0;
		int left = helper(root->left);
		int right = helper(root->right);
		int cur = root->val + max(0, left) + max(0, right);
		if (cur > res) res = cur;
		return root->val + max(left, max(right, 0));
	}
};