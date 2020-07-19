/*
按之字形顺序打印二叉树

题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

//思路1：用栈+队列（逆序访问）
*/


class Solution {
public:
	//思路1：用栈+队列（逆序访问）
	//栈实现逆序访问，同时用队列保存下一层的元素（奇数层从右后左保存，偶数层先左后右保存）
	vector<vector<int> > Print(TreeNode* pRoot) {
		if (pRoot == NULL) return {};
		vector<vector<int>> res;
		int level = 1;
		stack<TreeNode*> data;
		queue<TreeNode*> q;
		TreeNode* cur = pRoot;
		data.push(cur);
		res.push_back({ cur->val });  //先保存第一层
		while (!data.empty()) {
			int size = data.size();
			vector<int> temp;
			while (size > 0) {
				cur = data.top();
				data.pop();
				--size;
				//如果是奇数层，则先右节点入栈，再左节点入栈；入栈并保存到结果
				if (level % 2 == 0) {
					if (cur->left) {
						q.push(cur->left);
						temp.push_back(cur->left->val);
					}
					if (cur->right) {
						q.push(cur->right);
						temp.push_back(cur->right->val);
					}
				}
				else {
					if (cur->right) {
						q.push(cur->right);
						temp.push_back(cur->right->val);
					}
					if (cur->left) {
						q.push(cur->left);
						temp.push_back(cur->left->val);
					}
				}
			}
			if (temp.size() > 0) res.push_back(temp);
			//将队列中的元素移到栈
			while (!q.empty()) {
				data.push(q.front());
				q.pop();
			}
			++level;
		}
		return res;
	}

};