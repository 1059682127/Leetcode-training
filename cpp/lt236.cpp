//lt236
/*
二叉树的最近公共祖先

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]


示例 1:
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。

//思路1：中序遍历+迭代
//思路2:递归
*/

class Solution {
public:
	//思路1：中序遍历+迭代
	//从根节点开始遍历树
	//如果节点 p 和节点 q 都在右子树上，那么以右孩子为根节点继续 1 的操作
	//如果节点 p 和节点 q 都在左子树上，那么以左孩子为根节点继续 1 的操作
	//如果条件 2 和条件 3 都不成立，这就意味着我们已经找到节 p 和节点 q 的 LCA 了

	//中序遍历可以确定左子树、根节点、右子树
	map<TreeNode*, int> hash_table;
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		int k = 0;
		TreeNode* cur = root;
		helper(cur, k);
		//获得中序遍历数组所在的索引
		cur = root;
		while (true) {
			//在左子树
			if (hash_table[p] < hash_table[cur] && hash_table[q] < hash_table[cur]) cur = cur->left;
			else if (hash_table[p] > hash_table[cur] && hash_table[q] > hash_table[cur]) cur = cur->right;
			else return cur;
		}
	}
	void helper(TreeNode* root, int &k) {
		if (root == NULL) return;
		helper(root->left, k);
		hash_table[root] = k;
		++k;
		helper(root->right, k);
	}
};

class Solution {
public:
	//思路2:递归
	//过程如下：
	//如果当前结点root等于NULL，则直接返回NULL
	//如果root等于p或者q，那这棵树一定返回p或者q
	//然后看递归左右子树（因为是递归，使用函数后可以认为左右子树已经算出了结果，用left和right表示
	//此时若left为空，那最终结果只要看right；若right为空，那最终结果只要看left
	//如果left和right都非空，因为只给了p和q两个结点，都非空，说明一边一个，因此root是他们的最近公共祖先
	//如果left和right都为空，则返回空（其实已经包含在前面的情况中了）

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		return helper(root, p, q);
	}
	TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) return NULL;
		if (root == p) return p;
		if (root == q) return q;
		TreeNode* left = helper(root->left, p, q);
		TreeNode* right = helper(root->right, p, q);
		if (left && right) return root;
		if (left == NULL) return right;
		if (right == NULL) return left;
		return NULL;
	}

};