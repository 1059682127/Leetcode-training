//lt100
/*
100. ��ͬ����

������������������дһ�����������������Ƿ���ͬ��

����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�

ʾ�� 1:

����:       1         1
		  / \       / \
		 2   3     2   3

		[1,2,3],   [1,2,3]

���: true

//˼·1���ݹ�
*/

class Solution {
public:
	//˼·1���ݹ�
	//��ͬ��ʽ�������������ڵ�ֵ����ͬ��true������false
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) return true;
		if (p == NULL && q != NULL) return false;
		if (p != NULL && q == NULL) return false;
		return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};