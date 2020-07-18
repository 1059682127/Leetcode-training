//lt98
/*
验证二叉搜索树

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：


	节点的左子树只包含小于当前节点的数。
	节点的右子树只包含大于当前节点的数。
	所有左子树和右子树自身必须也是二叉搜索树。


示例 1:

输入:
	2
   / \
  1   3
输出: true

//思路1：递归
//思路2：中序遍历递归
//思路3：中序遍历迭代

*/

class Solution {
public:
	//思路1：递归
	//不仅要保证左节点<root，右节点>root；而是要左子树<rot,右子树>root；
	//可以通过递归实时更新节点的上界Max和下界Min，然后比较节点值是否在范围内
	//O(N),每个节点访问一次
	//O(N),

	//Trick1:应对{2147483647} 这种情况，其实可以把int改为long
	//易错点：node->val <= Min || node->val >= Max，不能等于
	bool isValidBST(TreeNode* root) {
		return helper(root, LONG_MAX, LONG_MIN);
	}
	bool helper(TreeNode* node, long Max, long Min) {
		if (node == NULL) return true;
		if (node->val <= Min || node->val >= Max) return false;  //不能等于
		return helper(node->left, node->val, Min) && helper(node->right, Max, node->val);
	}
};

class Solution {
public:
	//思路2:中序遍历递归
	//不仅要保证左节点<root，右节点>root；而是要左子树<rot,右子树>root；
	//可以通过递归实时更新节点的上界Max和下界Min，然后比较节点值是否在范围内

	//Trick1:如果递归函数pre采用传值，则改变它的值并不能影响它在函数外部的值，这样回溯时pre就不是前驱节点的值

	long pre = LONG_MIN;
	bool isValidBST(TreeNode* root) {
		return helper(root);
	}
	bool helper(TreeNode* node) {
		if (node == NULL) return true;
		if (!helper(node->left)) return false;
		if (node->val <= pre) return false;
		pre = node->val;
		if (!helper(node->right)) return false;
		return true;
	}
};


class Solution {
public:
	//思路3:中序遍历迭代
	//保存前驱节点

	//Trick1:如果递归函数pre采用传值，则改变它的值并不能影响它在函数外部的值，这样回溯时pre就不是前驱节点的值


	bool isValidBST(TreeNode* root) {
		if (root == NULL) return true;
		long pre = LONG_MIN;
		stack<TreeNode*> data;
		TreeNode* cur = root;
		while (!data.empty() || cur != NULL) {
			if (cur) {
				//中序遍历先往左走
				data.push(cur);
				cur = cur->left;
			}
			else {
				//先打印节点，跟前驱比较再往右走
				TreeNode* temp = data.top();
				data.pop();
				if (temp->val <= pre) return false;
				pre = temp->val;
				cur = temp->right;
			}
		}
		return true;
	}
};