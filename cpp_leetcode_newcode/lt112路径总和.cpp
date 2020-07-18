//lt112

/*
路径总和

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
说明: 叶子节点是指没有子节点的节点。
示例:
给定如下二叉树，以及目标和 sum = 22，
			  5
			 / \
			4   8
		   /   / \
		  11  13  4
		 /  \      \
		7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
//思路1：递归（自顶向下）
//思路2：迭代

*/
class Solution {
public:
	//思路1：递归（自顶向下）
	//如果当前节点是叶子，检查 sum 值是否为 0，也就是是否找到了给定的目标和
	//如果不是叶子，则对它的所有孩子节点，递归调用 hasPathSum 函数，其中 sum 值减去当前节点的权值；
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL) return false;
		sum -= root->val;
		if (root->left == NULL && root->right == NULL) return sum == 0;
		return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
	}

};

class Solution {
public:
	//思路2：迭代
	//将当前节点的val更改为剩余和
	//如果是叶节点，判断剩余和是否为0
	//如果不是叶节点，如左节点存在，更新左节点的剩余和，入栈。。。
	bool hasPathSum(TreeNode* root, int sum) {
		stack<TreeNode*> data;
		if (root == NULL) return false;
		root->val = sum - root->val;
		TreeNode *cur = NULL;
		data.push(root);
		while (!data.empty()) {
			cur = data.top();
			data.pop();
			//如果是叶子节点，判断是否为0
			if (cur->left == NULL && cur->right == NULL) {
				if (cur->val == 0) return true;
				else continue;
			}
			else {
				if (cur->left != NULL) {
					cur->left->val = cur->val - cur->left->val;
					data.push(cur->left);
				}
				if (cur->right != NULL) {
					cur->right->val = cur->val - cur->right->val;
					data.push(cur->right);
				}
			}
		}
		return false;
	}

};