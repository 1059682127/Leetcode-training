/*
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* helper(vector<int> &pre, vector<int> &vin, int pre_left, int pre_right, int vin_left, int vin_right) {
		if (pre_left > pre_right) return NULL;
		int rootVal = pre[pre_left];
		//在vin中找到pre[pre_left]对应的数
		int vin_root = vin_left;
		for (; vin_root <= vin_right; ++vin_root) {
			if (vin[vin_root] == rootVal) break;
		}
		//建跟
		TreeNode *root = new TreeNode(rootVal);
		root->left = helper(pre, vin, pre_left + 1, pre_left + vin_root - vin_left, vin_left, vin_root - 1);
		root->right = helper(pre, vin, pre_left + vin_root - vin_left + 1, pre_right, vin_root + 1, vin_right);
		return root;
	}

	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int len = pre.size();
		if (len == 0) return NULL;
		return helper(pre, vin, 0, len - 1, 0, len - 1);
	}
};