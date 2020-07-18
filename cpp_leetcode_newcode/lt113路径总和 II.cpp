//lt113

/*
路径总和 II

给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

			  5
			 / \
			4   8
		   /   / \
		  11  13  4
		 /  \    / \
		7    2  5   1


返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

//思路1：递归
*/

class Solution {
public:
	//思路1：递归
	//需要数据结构来维护中间路径结果以及保存满足条件的所有路径。
	//在递归的过程递减sum:sum-=root->val
	//终止条件：
	//(1)root == NULL,return NULL;
	//(2)抵达叶子节点，if(sum == 0) res.push_back(item)


	//Trick1:因为递归的时候维护的是同一个vector<int> item，所以回溯的时候item.pop_back()

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> item;
		vector<vector<int>> res;
		helper(root, sum, item, res);
		return res;
	}
	void helper(TreeNode* root, int sum, vector<int>& item, vector<vector<int>>& res) {
		if (root == NULL) return;
		sum -= root->val;
		item.push_back(root->val);
		if (root->left == NULL && root->right == NULL && sum == 0) {
			res.push_back(item);
			return;
		}
		if (root->left) {
			helper(root->left, sum, item, res);
			//注意！！！回溯的时候去掉最后一个
			item.pop_back();
		}
		if (root->right) {
			helper(root->right, sum, item, res);
			item.pop_back();
		}
	}
};