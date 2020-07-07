//lt104
/*
二叉树的最大深度

给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点。
示例：
给定二叉树 [3,9,20,null,null,15,7]，
	3
   / \
  9  20
	/  \
   15   7
返回它的最大深度 3 。
//思路1：自顶向下的DFS
//思路2：自底向上的DFS
//思路3：BFS(队列)，遍历完了后，遍历层数level即最大深度
*/

class Solution {
public:
	//思路1：自顶向下的DFS
	//类似前序遍历，max(depth, answer)
	int answer;
	int maxDepth(TreeNode* root) {
		answer = 0;
		helper(root, 1);
		return answer;
	}
	void helper(TreeNode* root, int depth) {
		if (root == NULL) return;
		answer = max(depth, answer);
		helper(root->left, depth + 1);
		helper(root->right, depth + 1);
	}
};

class Solution {
public:
	//思路2：自底向上的DFS
	//类似后序遍历，max(left_height, right_heigh) + 1
	int maxDepth(TreeNode* root) {
		return helper(root);
	}
	int helper(TreeNode* root) {
		if (root == NULL) return 0;
		int left_height = helper(root->left);
		int right_height = helper(root->right);
		return max(left_height, right_height) + 1;
	}
};

class Solution {
public:
	//思路3:BFS(队列)，遍历完了后，遍历层数level即最大深度

	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		queue<TreeNode*> q;
		int size = 0;  //记录队列中已有的节点数（上一层）
		TreeNode *cur = root;
		int level = 0;
		q.push(cur);
		while (!q.empty()) {
			size = q.size();
			while (size > 0) {
				cur = q.front();
				q.pop();
				--size;
				//左节点和右节点入队列
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			++level;
		}
		return level;
	}
};