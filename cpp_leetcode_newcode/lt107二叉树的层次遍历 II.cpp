//lt107

/*
107. 二叉树的层次遍历 II
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

	3
   / \
  9  20
	/  \
   15   7


返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]
//思路1：队列（自顶向下的层序遍历）+反转
//思路2：深度搜索（标记对应层数）+反转
//思路3：队列（自顶向下层序遍历）（但是将结果insert到res.begin()）

//知识点：逆序存储方式：vector<vector<int>>(res.rbegin(), res.rend());
*/

class Solution {
public:
	//思路1：队列（自顶向下的层序遍历）+反转
	//思路2：深度搜索（标记对应层数）+反转
	//思路3：队列（自顶向下层序遍历）（但是将结果insert到res.begin()）
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if (root == NULL) return {};
		queue<TreeNode*> q;
		int size = 0;
		TreeNode *cur = root;
		vector<vector<int>> res;
		q.push(cur);
		while (!q.empty()) {
			size = q.size();
			vector<int> temp;
			while (size > 0) {
				cur = q.front();
				q.pop();
				--size;
				if (cur != NULL) {
					temp.push_back(cur->val);
					//左节点和右节点入队列
					q.push(cur->left);
					q.push(cur->right);
				}
			}
			if (temp.size() != 0) res.insert(res.begin(), temp); //去掉空数组,插入头部
		}
		return res;
	}
};