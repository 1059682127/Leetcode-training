//lt111
/*
111. 二叉树的最小深度
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

	3
   / \
  9  20
	/  \
   15   7

返回它的最小深度  2.

//思路1：递归
//思路2：迭代（BFS）
*/

class Solution {
public:
	//思路1：递归
	//父节点的深度=min(左子树最小深度，左子树最小深度)
	//区别于求树的最大深度，要对左右叶子是否为空进行判断；若为空，则非空一边递归的结果，而不是取min
	//O(N)：所有节点遍历一遍 
	//O(logN)：递归树的高度
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		if (!root->left) return minDepth(root->right) + 1;
		if (!root->right) return minDepth(root->left) + 1;
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}

};

class Solution {
public:
	//思路2：迭代（BFS）
	//类似树的层次遍历,当第一次遍历到左右子树都为空的时候，得出最短路径
	int minDepth(TreeNode* root) {
		if (root == NULL) return 0;
		queue<TreeNode*> q;
		int size = 0;  //记录队列中已有的节点数（上一层）
		TreeNode *cur = root;
		int level = 0;
		q.push(cur);
		while (!q.empty()) {
			size = q.size();
			while (size > 0) {
				cur = q.front();
				q.pop();
				--size;
				//左节点和右节点入队列
				if (!cur->left && !cur->right) return ++level;
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			++level;
		}
		return level;
	}

};