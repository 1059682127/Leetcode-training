
//lt108

/*
108. 将有序数组转换为二叉搜索树

将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

	  0
	 / \
   -3   9
   /   /
 -10  5

//思路1：分治法
//时间O(N)：所有节点都遍历一遍
//空间O(logN)：递归树的高度为logN
*/

class Solution {
public:
	//思路1：分治法
	//取中间节点为根节点，分左右子树
	//终止条件：长度为1，则终止
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}
	TreeNode* helper(vector<int>& nums, int start, int end) {
		if (start > end) return NULL;
		int mid = (start + end) / 2;
		TreeNode* node = new TreeNode(nums[mid]);
		node->left = helper(nums, start, mid - 1);
		node->right = helper(nums, mid + 1, end);
		return node;
	}
};