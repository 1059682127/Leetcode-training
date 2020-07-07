
//lt108

/*
108. ����������ת��Ϊ����������

��һ�������������е��������飬ת��Ϊһ�ø߶�ƽ�������������

�����У�һ���߶�ƽ���������ָһ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1��

ʾ��:

������������: [-10,-3,0,5,9],

һ�����ܵĴ��ǣ�[0,-3,9,-10,null,5]�������Ա�ʾ��������߶�ƽ�������������

	  0
	 / \
   -3   9
   /   /
 -10  5

//˼·1�����η�
//ʱ��O(N)�����нڵ㶼����һ��
//�ռ�O(logN)���ݹ����ĸ߶�ΪlogN
*/

class Solution {
public:
	//˼·1�����η�
	//ȡ�м�ڵ�Ϊ���ڵ㣬����������
	//��ֹ����������Ϊ1������ֹ
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