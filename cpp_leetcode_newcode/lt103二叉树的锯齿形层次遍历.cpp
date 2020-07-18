//lt103
/*
二叉树的锯齿形层次遍历
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

	3
   / \
  9  20
	/  \
   15   7


返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

//思路1：双栈O(N)/O(N)

*/

class Solution {
public:
	//思路1：双栈
	//遍历的时候偶数层自左向右，而奇数层自右向左。

	//要实现逆序（最晚入列最先访问），用双栈（一个栈出栈上一层节点，另一个栈入栈保存该层节点）
	//这里添加的时候对层数进行奇偶数判断，奇数时，先入右节点，再入左节点；偶数树，先入左节点，再入右节点
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		//边界条件
		if (root == NULL) return {};
		stack<TreeNode*> data;
		vector<vector<int>> res;
		data.push(root);
		res.push_back(vector<int>(1, root->val));
		TreeNode* cur = NULL;
		int level = 1;
		while (!data.empty()) {
			int size = data.size();
			cout << size << endl;
			vector<int> temp;
			stack<TreeNode*> newStack;
			while (size > 0) {
				cur = data.top();
				data.pop();
				--size;
				//偶数
				if (level % 2 == 0) {
					if (cur->left) {
						newStack.push(cur->left);
						temp.push_back(cur->left->val);
					}
					if (cur->right) {
						newStack.push(cur->right);
						temp.push_back(cur->right->val);
					}
				}
				else {
					if (cur->right) {
						newStack.push(cur->right);
						temp.push_back(cur->right->val);
					}
					if (cur->left) {
						newStack.push(cur->left);
						temp.push_back(cur->left->val);
					}
				}
			}
			if (temp.size() != 0) res.push_back(temp);
			++level;
			data = newStack;
		}
		return res;
	}
};
