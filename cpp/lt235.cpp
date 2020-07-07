//lt235
/*
二叉搜索树的最近公共祖先

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

//思路1：递归
//思路2：迭代
*/

class Solution {
public:
	//思路1：递归

	//从根节点开始遍历树
	//如果节点 p 和节点 q 都在右子树上，那么以右孩子为根节点继续 1 的操作
	//如果节点 p 和节点 q 都在左子树上，那么以左孩子为根节点继续 1 的操作
	//如果条件 2 和条件 3 都不成立，这就意味着我们已经找到节 p 和节点 q 的 LCA 了

	//Trick1:利用二叉搜索树的性质可以轻松判断节点在左子树还是在右子树

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) return NULL;
		if (p->val < root->val && q->val < root->val) {
			root = root->left;
		}
		else if (p->val > root->val && q->val > root->val) {
			root = root->right;
		}
		else {
			return root;
		}
		return lowestCommonAncestor(root, p, q);
	}
};

class Solution {
public:
	//思路2：迭代

	//从根节点开始遍历树
	//如果节点 p 和节点 q 都在右子树上，那么以右孩子为根节点继续 1 的操作
	//如果节点 p 和节点 q 都在左子树上，那么以左孩子为根节点继续 1 的操作
	//如果条件 2 和条件 3 都不成立，这就意味着我们已经找到节 p 和节点 q 的 LCA 了

	//Trick1:利用二叉搜索树的性质可以轻松判断节点在左子树还是在右子树

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) return NULL;
		TreeNode* cur = root;
		while (true) {
			//在左子树
			if (p->val < cur->val && q->val < cur->val) cur = cur->left;
			else if (p->val > cur->val && q->val > cur->val) cur = cur->right;
			else return cur;
		}
	}
};