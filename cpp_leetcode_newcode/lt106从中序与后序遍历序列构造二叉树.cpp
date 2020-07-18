//lt106
/*
从中序与后序遍历序列构造二叉树

根据一棵树的中序遍历与后序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素。
例如，给出
中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
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
	//1、在后序遍历序列中,最后一个元素为树的根节点
	//2、在中序遍历序列中,根节点的左边为左子树，根节点的右边为右子树
	//不断将数组划分为左子树、根、右子树，大小为1的子树即为叶节点
	//中序数组：根节点ri, 左子树数组in_lo~ri-1, 右子树数组，ri+1~in_hi
	//后序数组：根节点post_hi,左子树数组post_lo~post_lo-in_lo+ri-1，右子树数组post_lo-in_lo+ri~post_hi-1

	//Trick1:用哈希表来保存中序遍历序列中,元素和索引的位置关系.因为从后序序列中拿到根节点后，要在中序序列中查找对应的位置,从而将数组分为左子树和右子树
	map<int, int> hash_table;
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

		for (int i = 0; i < inorder.size(); ++i) hash_table[inorder[i]] = i;
		return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	}
	TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int in_lo, int in_hi, int post_lo, int post_hi) {
		//如果大小为0，则为空子树
		if (in_lo > in_hi || post_lo > post_hi) return NULL;
		//如果不是空子树，则确定后序遍历数组最后一个元素（根节点）在中序遍历数组中的索引
		int root = postorder[post_hi];
		int ri = hash_table[root];
		//该顶点
		TreeNode* node = new TreeNode(root);
		//连接左右子树
		node->left = helper(inorder, postorder, in_lo, ri - 1, post_lo, post_lo - in_lo + ri - 1);
		node->right = helper(inorder, postorder, ri + 1, in_hi, post_lo - in_lo + ri, post_hi - 1);
		return node;
	}
};