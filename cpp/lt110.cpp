//lt110

/*
110. ƽ�������

����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������

�����У�һ�ø߶�ƽ�����������Ϊ��


һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������1��


ʾ�� 1:

���������� [3,9,20,null,null,15,7]

	3
   / \
  9  20
	/  \
   15   7

���� true ��

//˼·1���ݹ�

*/
lass Solution{
public:
	//˼·1���ݹ�

	//˼·�����������������ƣ�������Ҫά���ڵ���ȣ�ͬʱ��Ҫ�ж��Ƿ���ƽ������������������ȴ���0�����ʣ������-1��ʾ��ƽ������
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