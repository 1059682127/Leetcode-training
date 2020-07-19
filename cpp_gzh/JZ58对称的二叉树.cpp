
/*
题目描述
请实现一个函数，用来判断一棵二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
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
	//思路：
	//对称二叉树：左
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