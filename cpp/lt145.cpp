//lt145
/*
�������
//˼·1���ݹ�
//˼·2������
//˼·3��ǰ��+��ת���ȸ�-��-��
//˼·4���������
*/


class Solution {
public:
	//˼·1���ݹ�
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		postorderHelper(root, res);
		return res;
	}
	void postorderHelper(TreeNode* root, vector<int> &res) {
		if (root == NULL) return;
		else {
			//�������������ٱ����������������ʸ��ڵ�
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
	//˼·2������
	//��������ĳ�����ڵ�����������ص����ڵ��ʱ�򣬶����������������������԰ѵ�ǰ���ڵ��ջ�ﵯ����Ȼ��ת����������
	//���Ǻ���������ܰѸ��ڵ�ֱ�Ӵ�ջ��������Ϊ����������������Ҫ�����ڵ���ӵ�vector��
	//����Ҫ�ж��Ǵ��������ص��ĸ��ڵ㻹�Ǵ��������ص��ĸ��ڵ�
	//����Ǵ��������ص����ڵ㣬��ʱӦת����������(���������ΪNULL��������ǰ�ڵ����vector)
	//������������ص��ĸ��ڵ㣬Ӧ�ý���ǰ�ڵ㵯�����뵽vector��

	//Trick1:��hash_table�ж��Ƿ�����������ظ��ڵ㣬�������������ظ��ڵ�ʱ����hash_table�м�¼
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> data;
		map<TreeNode*, bool> hash_table;
		TreeNode *cur = root;
		while (!data.empty() || cur) {
			//һֱ������ߵ��ף���Ϊ������������û�������������ڵ㣬���Ҫ��¼���ʹ��ĸ��ڵ㣬��ֹ�ٴ���ջ
			while (cur && !hash_table[cur]) {
				data.push(cur);
				cur = cur->left;
			}
			//��������������ڻ��ߴ����������أ�������ǰ�ڵ㵽vector��
			cur = data.top();
			if (!cur->right || hash_table[cur]) {
				res.push_back(cur->val);
				hash_table[cur] = true;
				data.pop();

				//�ٵ�����һ���ڵ�
				if (data.empty()) return res;
				cur = data.top();
				cur = cur->right;
			}
			else {
				//���������������
				hash_table[cur] = true;
				cur = cur->right;
			}
		}
		return res;
	}
};

class Solution {
public:
	//˼·3��ǰ��(��-��-��)+��ת

	//֪ʶ�㣺1����תstd::reverse(trianglePoints.begin(), trianglePoints.end());
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
	//˼·4���������
	//ǰ���Ǹ�-��-��
	//���Ԫ���ǲ��뵽�������ͷ���������-��-����
	//��������˳���ɴ������޸�Ϊ���ҵ�����������Ϊ��-��-��


	vector<int> postorderTraversal(TreeNode* root) {

	}
};