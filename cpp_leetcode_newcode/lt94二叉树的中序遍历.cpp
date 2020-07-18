//lt94

/*
 ���������������

����һ���������������������� ������
ʾ��:
����: [1,null,2,3]
   1
	\
	 2
	/
   3

���: [1,3,2]
����: �ݹ��㷨�ܼ򵥣������ͨ�������㷨�����
//˼·1���ݹ�
//˼·2:��������ʽջ��
//˼·3��Ī��˹����O(N)/O(1)
*/

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
	//˼·1���ݹ飺


	//ǰ�����:��ӡ-��-��
	//�������:��-��ӡ-��
	//�������:��-��-��ӡ

	//��ĿҪ���������������ǾͰ��� ��-��ӡ-������˳��������Ϳ����ˣ��ݹ麯��ʵ��

	//��ֹ����:��ǰ�ڵ�Ϊ��ʱ
	//������: �ݹ�ĵ�����ڵ㣬��ӡ��ǰ�ڵ㣬�ٵݹ�����ҽڵ�


	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> data;
		helper(root, data);
		return data;
	}
	void helper(TreeNode* root, vector<int>& data) {
		if (root == NULL) return;
		helper(root->left, data);
		data.push_back(root->val);
		helper(root->right, data);
	}
};


//ִ����ʱ:4 ms, ������ C++ �ύ�л�����72.28%���û�
//�ڴ����� :10.9 MB, ������ C++ �ύ�л�����8.29%���û�
class Solution {
public:
	//˼·2:��������ʽջ��

	//�ݹ�ʵ��ʱ���Ǻ����Լ������Լ���һ����Ƕ����ȥ������ϵͳ/������Զ���������ջ��������ÿ�����õĺ���������������Ҫ�Լ�ģ�������ĵ��ù��̡�

	//�ݹ�ĵ��ù����ǲ���������ߣ�������߲���ȥ�ˣ��ʹ�ӡ�ڵ㣬��ת���ұߣ�Ȼ���ұ߼���������̡������ڵ���ʵ��ʱ���Ϳ�����ջ��ģ������ĵ��ù��̡�

	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> data;
		vector<int> res;
		//��ջ���ջ���δ�ߵ��׵�ʱ��
		while (!data.empty() || root) {
			//����������ߣ�������߲���ȥ�˴�ӡ��ǰ�ڵ�
			if (root) {
				data.push(root);
				root = root->left;
			}
			else {
				TreeNode* temp = data.top();
				data.pop();
				res.push_back(temp->val);
				root = temp->right;
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

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		TreeNode *cur = root, *prev = NULL;
		while (cur != NULL) {
			if (cur->left == NULL) {
				res.push_back(cur->val);
				cur = cur->right;
			}
			else {
				//Ѱ��ǰ�̽ڵ�
				prev = cur->left;
				while (prev->right && prev->right != cur) {
					prev = prev->right;
				}
				if (prev->right == NULL) {
					prev->right = cur;
					cur = cur->left;
				}
				else {
					prev->right = NULL;
					res.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
		return res;
	}
};