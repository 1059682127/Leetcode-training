/*
 �㷨֪ʶ��Ƶ����
��Ŀ����
����һ�ö��������жϸö������Ƿ���ƽ���������

���������ֻ��Ҫ������ƽ���ԣ�����Ҫ�������ǲ������������
*/

class Solution {
public:
	//ƽ��������������߶Ȳ����1
	//�ݹ飬�Ե�����
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