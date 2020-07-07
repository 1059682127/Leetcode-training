//lt145
/*
后序遍历
//思路1：递归
//思路2：迭代
//思路3：前序+反转（先根-右-左）
//思路4：插入队首
*/


class Solution {
public:
	//思路1：递归
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		postorderHelper(root, res);
		return res;
	}
	void postorderHelper(TreeNode* root, vector<int> &res) {
		if (root == NULL) return;
		else {
			//遍历左子树，再遍历右子树，最后访问根节点
			postorderHelper(root->left, res);
			postorderHelper(root->right, res);
			res.push_back(root->val);
		}
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
	//思路2：迭代
	//当遍历完某个根节点的左子树，回到根节点的时候，对于中序遍历和先序遍历可以把当前根节点从栈里弹出，然后转到右子树。
	//但是后序遍历不能把根节点直接从栈弹出，因为遍历完右子树，还要将根节点添加到vector中
	//所以要判断是从左子树回到的根节点还是从右子树回到的根节点
	//如果是从左子树回到根节点，此时应转到右子树；(如果右子树为NULL，弹出当前节点加入vector)
	//如果从右子树回到的根节点，应该将当前节点弹出加入到vector中

	//Trick1:用hash_table判断是否从右子树返回根节点，当从左子树返回根节点时，在hash_table中记录
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> data;
		map<TreeNode*, bool> hash_table;
		TreeNode *cur = root;
		while (!data.empty() || cur) {
			//一直往左边走到底，因为访问完左子树没有立即弹出根节点，因此要记录访问过的根节点，防止再次入栈
			while (cur && !hash_table[cur]) {
				data.push(cur);
				cur = cur->left;
			}
			//如果右子树不存在或者从右子树返回，弹出当前节点到vector中
			cur = data.top();
			if (!cur->right || hash_table[cur]) {
				res.push_back(cur->val);
				hash_table[cur] = true;
				data.pop();

				//再弹出上一根节点
				if (data.empty()) return res;
				cur = data.top();
				cur = cur->right;
			}
			else {
				//如果从左子树返回
				hash_table[cur] = true;
				cur = cur->right;
			}
		}
		return res;
	}
};

class Solution {
public:
	//思路3：前序(根-右-左)+反转

	//知识点：1、反转std::reverse(trianglePoints.begin(), trianglePoints.end());
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> data;
		while (!data.empty() || root != NULL) {
			if (root) {
				res.push_back(root->val);
				data.push(root);
				root = root->right;
			}
			else {
				root = data.top()->left;
				data.pop();
			}
		}
		reverse(res.begin(), res.end());
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
	//思路4：插入队首
	//前序是根-左-右
	//如果元素是插入到结果链表头部，变成右-左-根，
	//将遍历的顺序由从左到右修改为从右到左，则结果链表为左-右-根


	vector<int> postorderTraversal(TreeNode* root) {

	}
};