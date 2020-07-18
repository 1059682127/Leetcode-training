//lt110

/*
110. 平衡二叉树

给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：


一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。


示例 1:

给定二叉树 [3,9,20,null,null,15,7]

	3
   / \
  9  20
	/  \
   15   7

返回 true 。

//思路1：递归

*/
lass Solution{
public:
	//思路1：递归

	//思路与求树的最大深度类似，但是需要维护节点深度，同时还要判断是否是平衡树，所以用利用深度大于0的性质，用深度-1表示非平衡子树
	bool isBalanced(TreeNode* root) {
		return maxDepth(root) != -1;
	}
	int maxDepth(TreeNode* root) {
		if (root == NULL) return NULL;
		int left_height = maxDepth(root->left);
		int right_height = maxDepth(root->right);
		if (left_height == -1 || right_height == -1) return -1;
		if (abs(left_height - right_height) > 1) return -1;
		return max(left_height, right_height) + 1;
	}

};