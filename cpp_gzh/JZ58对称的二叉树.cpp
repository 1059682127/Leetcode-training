
/*
��Ŀ����
��ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ�ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/
class Solution {
public:
	//˼·��
	//�Գƶ���������
	bool helper(TreeNode* pLeft, TreeNode* pRight) {
		if (pLeft == NULL && pRight == NULL) return true;
		if (!pLeft || !pRight) return false;
		return pLeft->val == pRight->val && helper(pLeft->left, pRight->right) && helper(pLeft->right, pRight->left);
	}
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (!pRoot) return true;
		return helper(pRoot->left, pRoot->right);
	}

};