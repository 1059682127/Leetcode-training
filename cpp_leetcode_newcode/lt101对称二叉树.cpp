//lt101

/**
对称二叉树

给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
	1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
	1
   / \
  2   2
   \   \
   3    3

 //思路1：递归
 //思路2：迭代

 */
class Solution {
public:
	//思路1：递归
	/*
	如果一个树的左子树与右子树镜像对称，那么这个树是对称的。
	两个树在什么情况下互为镜像？
	如果同时满足下面的条件，两个树互为镜像：
		(1)它们的两个根结点具有相同的值。
		(2)每个树的右子树都与另一个树的左子树镜像对称。

	另一层理解：对左右子树做相反顺序的遍历：
	A节点的左子树进行前序遍历【DLR，即当前结点, 左孩子, 右孩子】
	同时对A节点的右子树进行【DRL，即当前结点, 右孩子, 左孩子】遍历。
	*/
	bool isSymmetric(TreeNode* root) {
		return helper(root, root);
	}
	bool helper(TreeNode* left, TreeNode* right) {
		//边界
		if (left == NULL && right == NULL) return true;
		if (left == NULL || right == NULL) return false;
		return left->val == right->val && helper(left->right, right->left) && helper(left->left, right->right);
	}
};

class Solution {
public:
	//思路2：迭代
	/*
	类似BFS思想（用队列，队列中连续的节点应该是相同的，最初队列中包含的是 root和root）
	每次提取两个结点并比较它们的值。然后，将两个结点的左右子结点按相反的顺序插入队列中。
	结束条件：当队列为空时，或者我们检测到树不对称（即从队列中取出两个不相等的连续结点）
	*/
	bool isSymmetric(TreeNode* root) {
		queue<TreeNode*> data;
		data.push(root);
		data.push(root);
		TreeNode *t1 = NULL, *t2 = NULL;
		while (!data.empty()) {
			t1 = data.front();
			data.pop();  //记得取值之后马上弹出
			t2 = data.front();
			data.pop();
			if (t1 == NULL && t2 == NULL) continue;
			if (t1 == NULL || t2 == NULL) return false;
			if (t1->val != t2->val) return false;
			data.push(t1->left);
			data.push(t2->right);
			data.push(t1->right);
			data.push(t2->left);
		}
		return true;
	}
};