/*
��Ŀ����
����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
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
	TreeNode* pRoot;
	TreeNode* pPre;
	//˼·���������
	void Inorder(TreeNode* cur) {
		if (cur == NULL) return;
		Inorder(cur->left);
		//��ӡ�ڵ�
		//���ǵ�һ���ڵ�
		if (pRoot == NULL) {
			pRoot = cur;
			pPre = cur;
		}
		else {
			pPre->right = cur;
			cur->left = pPre;
			pPre = cur;
		}
		Inorder(cur->right);
	}
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		pRoot = NULL;
		pPre = NULL;
		Inorder(pRootOfTree);
		return pRoot;
	}
};