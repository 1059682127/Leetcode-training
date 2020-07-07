//lt105
/*
从前序与中序遍历序列构造二叉树

根据一棵树的前序遍历与中序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素。
例如，给出
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：
	3
   / \
  9  20
	/  \
   15   7
//思路1：分治（递归）

*/


class Solution {
public:
	//思路1：分治（递归）
	//两个特性：
	//1、在前序遍历序列中,第一个元素为树的根节点
	//2、在中序遍历序列中,根节点的左边为左子树，根节点的右边为右子树
	//不断将数组划分为左子树、根、右子树，大小为1的子树即为叶节点
	//中序数组：根节点ri, 左子树数组in_lo~ri-1, 右子树数组，ri+1~in_hi(根据中序数组确定左右子树长度)
	//前序数组：根节点prev_lo,左子树数组prev_lo+1~prev_lo-in_lo+ri，右子树数组prev_lo-in_lo+ri+1~prev_hi
	map<int, int> hash_table;
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		for (int i = 0; i < inorder.size(); ++i) hash_table[inorder[i]] = i;
		return helper(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
	}
	TreeNode* helper(vector<int>& inorder, vector<int>& prevorder, int in_lo, int in_hi, int prev_lo, int prev_hi) {
		//如果大小为0，则为空子树
		if (in_lo > in_hi || prev_lo > prev_hi) return NULL;
		//如果不是空子树，则确定后序遍历数组最后一个元素（根节点）在中序遍历数组中的索引
		int root = prevorder[prev_lo];
		int ri = hash_table[root];
		//该顶点
		TreeNode* node = new TreeNode(root);
		//连接左右子树
		node->left = helper(inorder, prevorder, in_lo, ri - 1, prev_lo + 1, prev_lo - in_lo + ri);
		node->right = helper(inorder, prevorder, ri + 1, in_hi, prev_lo - in_lo + ri + 1, prev_hi);
		return node;
	}
};