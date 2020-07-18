//lt95

/*
不同的二叉搜索树 II

给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例:

输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
	\       /     /      / \      \
	 3     2     1      1   3      2
	/     /       \                 \
   2     1         2                 3

//思路1：递归
//思路2：动态规划
*/


class Solution {
public:
	//思路1：递归
	//选根，分治
	//从序列 1 ..n 中取出数字 i，作为当前树的树根。于是，剩余 i - 1 个元素可用于左子树，n - i 个元素用于右子树。
	//对序列 1 ... i - 1 重复上述过程，以构建所有的左子树；然后对 i + 1 ... n 重复，以构建所有的右子树。
	//有了树根 i 和可能的左子树、右子树的列表。
	//最后一步，对两个列表循环，将左子树和右子树连接在根上。

	//易错点：1、helper(int start, int end)从start到end序列构建的可能情况列表
	//2、all_trees.push_back(NULL);  //注意要添加NULL，不然返回[]

	//时间：O(4^n/n^(1/2))主要的计算开销在于构建给定根的全部可能树，也就是卡特兰数 Gn​。该过程重复了 n 次，
	//也就是 nGn​。卡特兰数以 4^n/n^(3/2)​ 增长。因此，总的时间复杂度为 4^n/n^(1/2)
	//空间：O(4^n/n^(1/2))有G(n)颗树，每棵树有n个元素

	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) return {};
		return helper(1, n);
	}
	//从start到end序列构建的可能情况列表
	vector<TreeNode*> helper(int start, int end) {
		vector<TreeNode*> all_trees;
		if (start > end) {
			//注意要添加NULL
			all_trees.push_back(NULL);  //注意要添加NULL
			return all_trees;
		}
		//选根，递归
		for (int i = start; i <= end; ++i) {
			vector<TreeNode*> left = helper(start, i - 1);
			vector<TreeNode*> right = helper(i + 1, end);
			for (auto& l : left) {
				for (auto& r : right) {
					TreeNode* root = new TreeNode(i);
					root->left = l;
					root->right = r;
					all_trees.push_back(root);
				}
			}
		}
		return all_trees;
	}
};


class Solution {
public:
	//思路2：动态规划
	//一般递归都可以用动态规划实现，从底部往上走
	//假设n = 3;个数是1的可行解，考虑[1],[2],[3]，个数是2的可行解（考虑连续数字[1,2],[2,3]）
	//个数为3的可行解：利用递归的思路，就是分别把每个数字作为根节点，然后考虑左子树和右子树的可能
	//以1为根，左子树是 [] 的所有可能，右子树是 [ 2 3 ] 的所有可能
	//以2为根，左子树是[1]的所有可能，右子树是[3]的所有可能
	//以3为根，左子树是 [ 1 2 ] 的所有可能，右子树是 [] 的所有可能

	//总体思想就是求长度为 2 的所有情况，求长度为 3 的所有情况直到 n。而求长度为 len 的所有情况，我们只需要求出一个代表 [ 1 2 ... len ] 的所有情况，其他的话加上一个偏差，加上当前根节点即可。

	//Trick1：[1,2]与[9,10]的情况是一样的，只是加上一个偏差
	//易错点：1、dp[0].push_back(NULL);

	vector<TreeNode*> generateTrees(int n) {
		vector<vector<TreeNode*>> dp(n + 1);
		if (n == 0) return {};
		dp[0].push_back(NULL);
		//从1~n进行状态转移
		for (int len = 1; len <= n; ++len) {
			//选择不同的根
			for (int root = 1; root <= len; ++root) {
				//计算左右子树的长度,组合情况依赖于长度，加上一个偏差即可
				int left = root - 1;
				int right = len - root;
				//dp[len],dp[right]的结果已经得出
				for (auto l : dp[left]) {
					for (auto r : dp[right]) {  //偏差为root
						TreeNode* curRoot = new TreeNode(root);
						curRoot->left = l;
						curRoot->right = clone(r, root);
						dp[len].push_back(curRoot);
					}
				}
			}
		}
		return dp[n];
	}
	TreeNode* clone(TreeNode* oldRoot, int bias) {
		if (oldRoot == NULL) return NULL;
		//复制根节点，再复制左右字节
		TreeNode* newRoot = new TreeNode(oldRoot->val + bias);
		newRoot->left = clone(oldRoot->left, bias);
		newRoot->right = clone(oldRoot->right, bias);
		return newRoot;
	}
};