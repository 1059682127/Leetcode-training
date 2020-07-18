//lt102

/*
二叉树的层次遍历

给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
例如:
给定二叉树: [3,9,20,null,null,15,7],
	3
   / \
  9  20
	/  \
   15   7
返回其层次遍历结果：
[
  [3],
  [9,20],
  [15,7]
]

思路1：广度优先搜索（队列）O(N)/O(N)
思路2：广度优先搜索（加层数标志）
思路3：DFS（加标记level）
*/

class Solution {
public:
	//思路1：广度优先搜索（队列）
	//每一层添加一次，记录上一层的元素个数size，size减到0，上一层遍历完毕
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL) return {};
		queue<TreeNode*> q;
		int size = 0;
		TreeNode *cur = root;
		vector<vector<int>> res;
		q.push(cur);
		while (!q.empty()) {
			size = q.size();
			vector<int> temp;
			while (size > 0) {
				cur = q.front();
				q.pop();
				--size;
				if (cur != NULL) {
					temp.push_back(cur->val);
					//左节点和右节点入队列
					q.push(cur->left);
					q.push(cur->right);
				}
			}
			if (temp.size() != 0) res.push_back(temp); //去掉空数组
		}
		return res;
	}
};

//执行用时:0 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗 :15 MB, 在所有 C++ 提交中击败了9.57%的用户
class Solution {
public:
	//思路2：广度优先搜索（加层数标志）
	//每一层添加一次，记录上一层的元素个数size，size减到0，上一层遍历完毕

	//Trick1：加标记（level）,不用临时数组
	//Trick2：只有cur->left != NULL才入队列

	//知识点1：
	//C++ 获取vector容器最后一个元素 

	//声明：vector<T>  vec;
	//方法一： return vec.at(vec.size()-1);
	//方法二： return vec.back();
	//方法三： return vec.end()-1;  注意：end指向末尾元素的下一个元素。
	//方法四： return vec.rbegin();
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL) return {};
		queue<TreeNode*> q;
		int size = 0;  //记录队列中已有的节点数（上一层）
		TreeNode *cur = root;
		vector<vector<int>> res;
		int level = 0;
		q.push(cur);
		while (!q.empty()) {
			size = q.size();
			res.push_back({});
			while (size > 0) {
				cur = q.front();
				q.pop();
				--size;
				res[level].push_back(cur->val);
				//左节点和右节点入队列
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			++level;
		}
		return res;
	}
};



class Solution {
public:
	//思路3：DFS（加标记level）
	//递归的时候，如果res.size()==level，则向res增加一个空{}；将当前节点添加到对应层
	//再递归调用非空的孩子节点
	vector<vector<int>> res;
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL) return {};
		helper(root, 0);
		return res;
	}
	void helper(TreeNode *root, int level) {
		if (res.size() == level) res.push_back({});
		res[level].push_back(root->val);
		if (root->left) helper(root->left, level + 1);
		if (root->right) helper(root->right, level + 1);
	}
};