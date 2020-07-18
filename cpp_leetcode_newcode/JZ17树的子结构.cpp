/*
��Ŀ����
�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	//�ݹ�
	//���ҵ���ͬ�ĸ��ڵ㣨������
	//Ȼ���ж����������Ƿ�����ͬ�Ľṹ
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (!pRoot1 || !pRoot2) return false;
		return dfs(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}
	//�ж��Ƿ�����ͬ�Ľṹ
	bool dfs(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (!pRoot2) return true;
		if (!pRoot1) return false;
		return pRoot1->val == pRoot2->val && dfs(pRoot1->left, pRoot2->left) && dfs(pRoot1->right, pRoot2->right);
	}
};