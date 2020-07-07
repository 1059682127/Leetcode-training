//lt124
/*
124. �������е����·����

����һ���ǿն����������������·���͡�

�����У�·��������Ϊһ������������ڵ�������ﵽ����ڵ�����С���·�����ٰ���һ���ڵ㣬�Ҳ�һ���������ڵ㡣

ʾ�� 1:

����: [1,2,3]

	   1
	  / \
	 2   3

���: 6


ʾ�� 2:

����: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
	/  \
   15   7

���: 42

//˼·1���Ե����ϵݹ�
*/


class Solution {
public:
	//˼·1���Ե����ϵݹ�
	//������һ������ͼ������������·��
	//�������ڵ����·��������root->val + �������·�� + �������·��
	//�������������·������С��0�����Ծ���һ���ڵ���·��=root-> + max(0, �������·��) + max(0, �������·��)
	//�������·���������Լ���ֵ + max(0, �������·���� �������·��)

	//�ݹ麯��helper���Ե�ǰ�ڵ�Ϊ���ڵ���·����ͬʱ���㾭����ǰ�ڵ���·��cur,���¾����ڵ���·��res 

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