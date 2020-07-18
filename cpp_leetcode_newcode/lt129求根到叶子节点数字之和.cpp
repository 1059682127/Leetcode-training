//lt129

/*
129. 求根到叶子节点数字之和

给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

说明: 叶子节点是指没有子节点的节点。

示例 1:

输入: [1,2,3]
	1
   / \
  2   3
输出: 25
解释:
从根到叶子节点路径 1->2 代表数字 12.
从根到叶子节点路径 1->3 代表数字 13.
因此，数字总和 = 12 + 13 = 25.

//思路1：递归、回溯 O(N)/O(logN)
//思路2：递归
*/



class Solution {
public:
	//思路1：递归、回溯
	//递归的时候num = num*10 + root->val;回溯的时候num /= 10
	//维护num进行递归，在回溯的时候去掉最后一个元素
	//Trick1:因为num改变之后要回退到上一层，所以采用&
	int sumNumbers(TreeNode* root) {
		int res = 0;
		int num = 0;
		sumNumbers(root, res, num);
		return res;
	}
	void sumNumbers(TreeNode* root, int& res, int& num) {
		if (root == NULL) return;
		num = num * 10 + root->val;
		//到叶子节点
		if (root->left == NULL && root->right == NULL) {
			res += num;
			return;
		}
		if (root->left) {
			sumNumbers(root->left, res, num);
			//回溯
			num /= 10;
		}
		if (root->right) {
			sumNumbers(root->right, res, num);
			num /= 10;
		}
	}
};

class Solution {
public:
	//思路2：递归
	//递归的时候num = num*10 + root->val
	//当root是叶子节点时，res += num
	//Trick2:num不采用&,当前num改变不会影响上一层递归的num
	//
	int sumNumbers(TreeNode* root) {
		int res = 0;
		int num = 0;
		sumNumbers(root, res, num);
		return res;
	}
	void sumNumbers(TreeNode* root, int& res, int num) {
		if (root == NULL) return;
		num = num * 10 + root->val;
		//到叶子节点
		if (root->left == NULL && root->right == NULL) {
			res += num;
			return;
		}
		if (root->left) {
			sumNumbers(root->left, res, num);
		}
		if (root->right) {
			sumNumbers(root->right, res, num);
		}
	}
};