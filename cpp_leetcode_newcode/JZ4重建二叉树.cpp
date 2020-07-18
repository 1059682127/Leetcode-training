/*
��Ŀ����
����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡���������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
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
		//��vin���ҵ�pre[pre_left]��Ӧ����
		int vin_root = vin_left;
		for (; vin_root <= vin_right; ++vin_root) {
			if (vin[vin_root] == rootVal) break;
		}
		//����
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