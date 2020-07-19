
/*
题目描述

二叉搜索树的第k个结点
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。

//思路1：中序遍历第k个节点 O(k)/O(logN)
//思路2:中序遍历（迭代）
*/


class Solution {
public:
	//思路1：中序遍历第k个节点 O(k)/O(logN)
	int curIndex;
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		//边界条件
		if (pRoot == NULL) return NULL;
		if (k == 0) return NULL;
		curIndex = 1;
		return helper(pRoot, k);
	}
	TreeNode* helper(TreeNode* cur, int k) {
		if (cur == NULL) return NULL;
		TreeNode* ret = helper(cur->left, k);
		if (ret) return ret;
		if (curIndex++ == k) return cur;
		ret = helper(cur->right, k);
		if (ret) return ret;
	}

};

class Solution {
public:
	//思路2:中序遍历（迭代）
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		//边界条件
		if (pRoot == NULL) return NULL;
		if (k == 0) return NULL;
		int curIndex = 1;
		stack<TreeNode*> data;
		TreeNode* cur = pRoot;
		while (!data.empty() || cur) {
			if (cur) {
				//入栈，且指向下一左节点
				data.push(cur);
				cur = cur->left;
			}
			else {
				//打印节点
				TreeNode* temp = data.top();
				data.pop();
				if (curIndex++ == k) return temp;
				cur = temp->right;
			}
		}
		return NULL;
	}
};