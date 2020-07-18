
/*
从上往下打印二叉树

题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。

//思路1：层序遍历
//思路2：
*/

class Solution {
public:
	//思路1：层序遍历
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		if (root == NULL) return {};
		vector<int> res;
		queue<TreeNode*> q;
		TreeNode* cur = root;
		q.push(cur);
		while (!q.empty()) {
			cur = q.front();
			res.push_back(cur->val);  //打印节点
			q.pop();
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}
		return res;
	}
};