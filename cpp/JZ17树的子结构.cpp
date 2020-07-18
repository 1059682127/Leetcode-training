/*
题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
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
	//递归
	//先找到相同的根节点（遍历）
	//然后判断左右子树是否是相同的结构
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (!pRoot1 || !pRoot2) return false;
		return dfs(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}
	//判断是否是相同的结构
	bool dfs(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (!pRoot2) return true;
		if (!pRoot1) return false;
		return pRoot1->val == pRoot2->val && dfs(pRoot1->left, pRoot2->left) && dfs(pRoot1->right, pRoot2->right);
	}
};