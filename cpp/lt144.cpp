//lt144
/*
��������ǰ�����

����һ������������������ ǰ�� ������
 ʾ��:
����: [1,null,2,3]
   1
	\
	 2
	/
   3

���: [1,2,3]

//˼·1���ݹ�O(N)/O(logN)
//˼·2������O(N)/O(logN)
//˼·3��Ī��˹����O(N)/O(1)
*/

class Solution {
public:
	//˼·1���ݹ�(N)/O(logN)
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		preorderHelper(root, res);
		return res;
	}
	void preorderHelper(TreeNode* root, vector<int> &res) {
		if (root == NULL) return;
		else {
			//�ȷ��ʸ��ڵ㣬�ٱ�����������������������
			res.push_back(root->val);
			preorderHelper(root->left, res);
			preorderHelper(root->right, res);
		}
	}
};


class Solution {
public:
	//˼·2������

	//�״�
	//1��if(root)�ȼ���if(root == NULL)
	//2��ѭ������while(!s.empty() || root)
	vector<int> preorderTraversal(TreeNode* root) {
		//�߽�����
		vector<int> res;
		stack<TreeNode*> s;
		while (!s.empty() || root) {
			//�������ߵ���
			if (root) {
				res.push_back(root->val);
				s.push(root);
				root = root->left;
			}
			else {
				//�����ҽڵ�
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
	//˼·3��Ī��˹����O(N)/O(1)

	/*
	morris������ʵ��ԭ��:
	������ǰ�ڵ�Ϊcur��
	1�����cur�����ӣ�cur�����ƶ���cur=cur.right��
	2�����cur�����ӣ��ҵ�cur�����������ҵĽڵ㣬��Ϊmostright�����������ǰ���ڵ㣩
		��a�����mostright��rightָ��ָ��գ�����ָ��cur��cur�����ƶ���cur=cur.left��
		��b�����mostright��rightָ��ָ��cur������ָ��գ�cur�����ƶ���cur=cur.right��
	ʵ�����ϵ�ԭ�򣬼�ʵ����morris������

	morris������ʵ��
	����һ�ֻ��ƣ�����û���������Ľڵ�ֻ����һ�Σ��������������Ľڵ�ᵽ������
	�ο���https://zhuanlan.zhihu.com/p/101321696?from=timeline

	ǰ�������
	������ǰ�ڵ�Ϊcur��
	1�����cur�����ӣ������ǰ�ڵ�, cur�����ƶ���cur=cur.right��
	2�����cur�����ӣ��ҵ�cur�����������ҵĽڵ㣬��Ϊmostright�����������ǰ���ڵ㣩
		��a�����mostright��rightָ��ָ��գ�����ָ��cur�������ǰ�ڵ㣬cur�����ƶ���cur=cur.left��
		��b�����mostright��rightָ��ָ��cur������ָ��գ�cur�����ƶ���cur=cur.right��
	ʵ�����ϵ�ԭ�򣬼�ʵ����morrisǰ�������

	���������
	������ǰ�ڵ�Ϊcur��
	1�����cur�����ӣ������ǰ�ڵ�,cur�����ƶ���cur=cur.right��
	2�����cur�����ӣ��ҵ�cur�����������ҵĽڵ㣬��Ϊmostright����ǰ�ڵ������������ǰ���ڵ㣩
		��a�����mostright��rightָ��ָ��գ�����ָ��cur��cur�����ƶ���cur=cur.left��
		��b�����mostright��rightָ��ָ��cur������ָ��գ������ǰ�ڵ㣬cur�����ƶ���cur=cur.right��
	ʵ�����ϵ�ԭ�򣬼�ʵ����morris������
	�ο����ӣ�https://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
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
				//Ѱ��ǰ�̽ڵ�
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
    //˼·3��Ī��˹����
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *cur = root, *prev = NULL;
        while(cur != NULL){
            if(cur->left == NULL){
                res.push_back(cur->val);
                cur = cur->right;
            }
            else{
                //Ѱ��ǰ�̽ڵ�
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