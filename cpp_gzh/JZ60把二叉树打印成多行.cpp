/*
把二叉树打印成多行

题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

//思路1：层序遍历
//思路2：深度遍历（加标志）
*/

class Solution {
public:
	//思路1：层序遍历
	vector<vector<int> > Print(TreeNode* pRoot) {
		if (pRoot == NULL) return {};
		vector<vector<int>> res;
		queue<TreeNode*> q;
		TreeNode* cur = pRoot;
		q.push(cur);
		int length = 0;
		while (!q.empty()) {
			int size = q.size();
			if (size > 0) res.push_back({});
			while (size > 0) {
				cur = q.front();
				res[length].push_back(cur->val);  //打印节点
				--size;
				q.pop();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			++length;
		}
		return res;
	}

};

class Solution {
public:
	//思路2：深度遍历（加标志）
	vector<vector<int> > Print(TreeNode* pRoot) {
		if (pRoot == NULL) return {};
		vector<vector<int>> res;
		helper(pRoot, 0, res);
		return res;
	}
	void helper(TreeNode* node, int level, vector<vector<int>> &res) {
		//判断是否加入新的一层
		if (res.size() == level) res.push_back({});
		res[level].push_back(node->val);
		if (node->left) helper(node->left, level + 1, res);
		if (node->right) helper(node->right, level + 1, res);
	}

};