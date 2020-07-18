/*
 算法知识视频讲解
题目描述
输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
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
	vector<vector<int>> ans;
	void dfs(TreeNode* cur, int expectNumber, vector<int> temp) {
		//如果是叶节点，判断是否等于目标值
		temp.push_back(cur->val);
		if (cur->left == NULL && cur->right == NULL) {
			if (cur->val == expectNumber) {
				ans.push_back(temp);
			}
		}
		else {
			if (cur->left) {
				dfs(cur->left, expectNumber - cur->val, temp);
			}
			if (cur->right) {
				dfs(cur->right, expectNumber - cur->val, temp);
			}
		}
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == NULL) return {};
		dfs(root, expectNumber, {});
		return ans;
	}
};