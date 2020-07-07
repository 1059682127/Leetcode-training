//lt230
/*
二叉搜索树中第K小的元素

给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
示例 1:
输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1
示例 2:
输入: root = [5,3,6,2,4,null,null,1], k = 3
	   5
	  / \
	 3   6
	/ \
   2   4
  /
 1
输出: 3

//思路1：递归（中序遍历）
//思路2：迭代
*/

class Solution {
public:
	//思路1：递归（中序遍历）
	//BST 的中序遍历是升序序列
	int kthSmallest(TreeNode* root, int k) {
		int res = 0;
		helper(root, k, res);
		return res;
	}
	void helper(TreeNode* root, int& k, int& res) {
		if (root == NULL) return;
		helper(root->left, k, res);
		--k;
		if (k == 0) {
			res = root->val;
			return;
		}
		helper(root->right, k, res);
	}
};

class Solution {
public:
	//思路2：迭代
	//BST 的中序遍历是升序序列
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> data;
		data.push(root);
		while (!data.empty()) {
			//往左走
			if (root) {
				data.push(root);
				root = root->left;
			}
			else {
				//访问根节点
				TreeNode* temp = data.top();
				data.pop();
				--k;
				if (k == 0) return temp->val;
				root = temp->right;
			}
		}
		return -1;
	}
};