//lt109
/*
109. 有序链表转换二叉搜索树

给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

	  0
	 / \
   -3   9
   /   /
 -10  5

 //思路1：快慢指针找到链表的中点
 //思路2：递归模拟中序遍历

*/

class Solution {
public:
	//思路1：快慢指针找到链表的中点
	//题目理解：得到的是一个有序链表而不是数组，我们不能直接使用下标来访问元素。我们需要知道链表中的中间元素。

	//思路2：中序遍历
	//根据二叉搜索树性质，二叉搜索树中序遍历得到的是有序数组
	//可以进行中序遍历，在打印节点的地方创建节点
	//时间O(N),链表所有节点遍历一遍
	//空间O(logN),递归树高度为O(logN)

	//步骤：
	//1、统计链表的长度
	//2、找到中点mid,递归左链表，建立当前节点（同时获取链表的下一节点,就算打印节点的时候顺序打印，创建的时候也是顺序创建），递归右链表
	//3、返回根节点

	//注意：用全局的node？？？
	ListNode* node;
	TreeNode* sortedListToBST(ListNode* head) {
		int len = 0;
		ListNode* cur = head;
		node = head;
		while (cur) {
			++len;
			cur = cur->next;
		}
		return inOrder(0, len - 1);

	}
	TreeNode* inOrder(int start, int end) {
		if (start > end) return NULL;
		int mid = (start + end) / 2;
		TreeNode* leftChild = inOrder(start, mid - 1);
		TreeNode* father = new TreeNode(node->val);
		node = node->next;
		TreeNode* rightChild = inOrder(mid + 1, end);
		father->left = leftChild;
		father->right = rightChild;
		return father;
	}
};