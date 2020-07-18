//lt94

/*
 二叉树的中序遍历

给定一个二叉树，返回它的中序 遍历。
示例:
输入: [1,null,2,3]
   1
	\
	 2
	/
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
//思路1：递归
//思路2:迭代（显式栈）
//思路3：莫里斯遍历O(N)/O(1)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	//思路1：递归：


	//前序遍历:打印-左-右
	//中序遍历:左-打印-右
	//后序遍历:左-右-打印

	//题目要求的是中序遍历，那就按照 左-打印-右这种顺序遍历树就可以了，递归函数实现

	//终止条件:当前节点为空时
	//函数内: 递归的调用左节点，打印当前节点，再递归调用右节点


	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> data;
		helper(root, data);
		return data;
	}
	void helper(TreeNode* root, vector<int>& data) {
		if (root == NULL) return;
		helper(root->left, data);
		data.push_back(root->val);
		helper(root->right, data);
	}
};


//执行用时:4 ms, 在所有 C++ 提交中击败了72.28%的用户
//内存消耗 :10.9 MB, 在所有 C++ 提交中击败了8.29%的用户
class Solution {
public:
	//思路2:迭代（显式栈）

	//递归实现时，是函数自己调用自己，一层层的嵌套下去，操作系统/虚拟机自动帮我们用栈来保存了每个调用的函数，现在我们需要自己模拟这样的调用过程。

	//递归的调用过程是不断往左边走，当左边走不下去了，就打印节点，并转向右边，然后右边继续这个过程。我们在迭代实现时，就可以用栈来模拟上面的调用过程。

	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> data;
		vector<int> res;
		//当栈不空或者未走到底的时候
		while (!data.empty() || root) {
			//不断往左边走，当左边走不下去了打印当前节点
			if (root) {
				data.push(root);
				root = root->left;
			}
			else {
				TreeNode* temp = data.top();
				data.pop();
				res.push_back(temp->val);
				root = temp->right;
			}
		}
		return res;
	}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	//思路3：莫里斯遍历O(N)/O(1)

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		TreeNode *cur = root, *prev = NULL;
		while (cur != NULL) {
			if (cur->left == NULL) {
				res.push_back(cur->val);
				cur = cur->right;
			}
			else {
				//寻找前继节点
				prev = cur->left;
				while (prev->right && prev->right != cur) {
					prev = prev->right;
				}
				if (prev->right == NULL) {
					prev->right = cur;
					cur = cur->left;
				}
				else {
					prev->right = NULL;
					res.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
		return res;
	}
};