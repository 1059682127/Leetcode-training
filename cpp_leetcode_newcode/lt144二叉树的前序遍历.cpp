//lt144
/*
二叉树的前序遍历

给定一个二叉树，返回它的 前序 遍历。
 示例:
输入: [1,null,2,3]
   1
	\
	 2
	/
   3

输出: [1,2,3]

//思路1：递归O(N)/O(logN)
//思路2：迭代O(N)/O(logN)
//思路3：莫里斯遍历O(N)/O(1)
*/

class Solution {
public:
	//思路1：递归(N)/O(logN)
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		preorderHelper(root, res);
		return res;
	}
	void preorderHelper(TreeNode* root, vector<int> &res) {
		if (root == NULL) return;
		else {
			//先访问根节点，再遍历左子树，最后遍历右子树
			res.push_back(root->val);
			preorderHelper(root->left, res);
			preorderHelper(root->right, res);
		}
	}
};


class Solution {
public:
	//思路2：迭代

	//易错：
	//1、if(root)等价于if(root == NULL)
	//2、循环条件while(!s.empty() || root)
	vector<int> preorderTraversal(TreeNode* root) {
		//边界条件
		vector<int> res;
		stack<TreeNode*> s;
		while (!s.empty() || root) {
			//先往左走到底
			if (root) {
				res.push_back(root->val);
				s.push(root);
				root = root->left;
			}
			else {
				//访问右节点
				root = s.top()->right;
				s.pop();
			}
		}
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
	//思路3：莫里斯遍历O(N)/O(1)

	/*
	morris遍历的实现原则:
	记作当前节点为cur。
	1、如果cur无左孩子，cur向右移动（cur=cur.right）
	2、如果cur有左孩子，找到cur左子树上最右的节点，记为mostright（中序遍历的前驱节点）
		（a）如果mostright的right指针指向空，让其指向cur，cur向左移动（cur=cur.left）
		（b）如果mostright的right指针指向cur，让其指向空，cur向右移动（cur=cur.right）
	实现以上的原则，即实现了morris遍历。

	morris遍历的实质
	建立一种机制，对于没有左子树的节点只到达一次，对于有左子树的节点会到达两次
	参考：https://zhuanlan.zhihu.com/p/101321696?from=timeline

	前序遍历：
	记作当前节点为cur。
	1、如果cur无左孩子，输出当前节点, cur向右移动（cur=cur.right）
	2、如果cur有左孩子，找到cur左子树上最右的节点，记为mostright（中序遍历的前驱节点）
		（a）如果mostright的right指针指向空，让其指向cur，输出当前节点，cur向左移动（cur=cur.left）
		（b）如果mostright的right指针指向cur，让其指向空，cur向右移动（cur=cur.right）
	实现以上的原则，即实现了morris前序遍历。

	中序遍历：
	记作当前节点为cur。
	1、如果cur无左孩子，输出当前节点,cur向右移动（cur=cur.right）
	2、如果cur有左孩子，找到cur左子树上最右的节点，记为mostright（当前节点在中序遍历的前驱节点）
		（a）如果mostright的right指针指向空，让其指向cur，cur向左移动（cur=cur.left）
		（b）如果mostright的right指针指向cur，让其指向空，输出当前节点，cur向右移动（cur=cur.right）
	实现以上的原则，即实现了morris遍历。
	参考链接：https://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
	*/
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		TreeNode *cur = root, *prev = NULL;
		while (cur) {
			if (cur->left == NULL) {
				res.push_back(cur->val);
				cur = cur->right;
			}
			else {
				//寻找前继节点
				prev = cur->left;
				while (prev->right != NULL && prev->right != cur) {
					prev = prev->right;
				}
				if (prev->right == NULL) {
					prev->right = cur;
					res.push_back(cur->val);
					cur = cur->left;
				}
				else {
					prev->right = NULL;
					cur = cur->right;
				}
			}
		}
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
    //思路3：莫里斯遍历
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *cur = root, *prev = NULL;
        while(cur != NULL){
            if(cur->left == NULL){
                res.push_back(cur->val);
                cur = cur->right;
            }
            else{
                //寻找前继节点
                prev = cur->left;
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = cur;
                    cur = cur->left;
                }
                else{
                    prev->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};