//lt99
/*
恢复二叉搜索树

二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。

示例 1:

输入: [1,3,null,null,2]

   1
  /
 3
  \
   2

输出: [3,1,null,null,2]

   3
  /
 1
  \
   2


示例 2:

输入: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

输出: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3

//思路1：中序遍历（递归）
//思路2：中序遍历（迭代）
//思路3：中序遍历（莫里斯遍历）
*/

class Solution {
public:
	//思路1：中序遍历（递归）
	//示例2中序遍历得到1 3 2 4，关键是怎么找到3，2 并进行交换
	//第一个节点,是第一个按照中序遍历时候前一个节点大于后一个节点,我们选取前一个节点
	//第二个节点,是在第一个节点找到之后, 后面出现前一个节点大于后一个节点,我们选择后一个节点
	TreeNode* firstNode = NULL;
	TreeNode* secondNode = NULL;
	TreeNode* pre = new TreeNode(INT_MIN);
	void recoverTree(TreeNode* root) {
		helper(root);
		int temp = firstNode->val;
		firstNode->val = secondNode->val;
		secondNode->val = temp;
	}
	void helper(TreeNode* node) {
		if (node == NULL) return;
		helper(node->left);
		if (!firstNode && node->val < pre->val) firstNode = pre;
		if (firstNode && node->val < pre->val) secondNode = node;
		pre = node;
		helper(node->right);
	}
};

class Solution {
public:
	//思路2：中序遍历（迭代）
	//示例2中序遍历得到1 3 2 4，关键是怎么找到3，2 并进行交换
	//第一个节点,是第一个按照中序遍历时候前一个节点大于后一个节点,我们选取前一个节点
	//第二个节点,是在第一个节点找到之后, 后面出现前一个节点大于后一个节点,我们选择后一个节点

	void recoverTree(TreeNode* root) {
		if (root == NULL) return;
		TreeNode* firstNode = NULL;
		TreeNode* secondNode = NULL;
		TreeNode* pre = new TreeNode(INT_MIN);
		stack<TreeNode*> data;
		TreeNode* cur = root;
		while (!data.empty() || cur != NULL) {
			if (cur) {
				data.push(cur);
				cur = cur->left;
			}
			else {
				//先打印节点
				TreeNode* temp = data.top();
				data.pop();
				if (!firstNode && temp->val < pre->val) firstNode = pre;
				if (firstNode && temp->val < pre->val) secondNode = temp;
				pre = temp;
				cur = temp->right;
			}
		}
		int temp = firstNode->val;
		firstNode->val = secondNode->val;
		secondNode->val = temp;
	}

};

class Solution {
public:
	//思路3：中序遍历（莫里斯遍历）
	//示例2中序遍历得到1 3 2 4，关键是怎么找到3，2 并进行交换
	//第一个节点,是第一个按照中序遍历时候前一个节点大于后一个节点,我们选取前一个节点
	//第二个节点,是在第一个节点找到之后, 后面出现前一个节点大于后一个节点,我们选择后一个节点

	//思路就是中序遍历的莫里斯版，就是在打印节点的地方换成寻找firstNode, secondNode
	void recoverTree(TreeNode* root) {
		if (root == NULL) return;
		TreeNode* firstNode = NULL;
		TreeNode* secondNode = NULL;
		TreeNode* pre = new TreeNode(INT_MIN);   //用于保存中序遍历的前驱节点
		TreeNode *cur = root, *prev = NULL;
		while (cur != NULL) {
			//如果cur无左孩子，输出当前节点,cur向右移动（cur=cur.right）
			if (cur->left == NULL) {
				if (!firstNode && cur->val < pre->val) firstNode = pre;
				if (firstNode && cur->val < pre->val) secondNode = cur;
				pre = cur;
				cur = cur->right;
			}
			else {
				//如果cur有左孩子，找到cur左子树上最右的节点，记为mostright（当前节点在中序遍历的前驱节点）
				prev = cur->left;
				while (prev->right && prev->right != cur) {
					prev = prev->right;
				}
				//如果mostright的right指针指向空，让其指向cur，cur向左移动（cur=cur.left）
				if (prev->right == NULL) {
					prev->right = cur;
					cur = cur->left;
				}
				//如果mostright的right指针指向cur，让其指向空，输出当前节点，cur向右移动（cur=cur.right）
				else {
					prev->right = NULL;
					if (!firstNode && cur->val < pre->val) firstNode = pre;
					if (firstNode && cur->val < pre->val) secondNode = cur;
					pre = cur;
					cur = cur->right;
				}
			}
		}
		int temp = firstNode->val;
		firstNode->val = secondNode->val;
		secondNode->val = temp;
	}

};