//lt98
/*
��֤����������

����һ�����������ж����Ƿ���һ����Ч�Ķ�����������

����һ��������������������������


	�ڵ��������ֻ����С�ڵ�ǰ�ڵ������
	�ڵ��������ֻ�������ڵ�ǰ�ڵ������
	�������������������������Ҳ�Ƕ�����������


ʾ�� 1:

����:
	2
   / \
  1   3
���: true

//˼·1���ݹ�
//˼·2����������ݹ�
//˼·3�������������

*/

class Solution {
public:
	//˼·1���ݹ�
	//����Ҫ��֤��ڵ�<root���ҽڵ�>root������Ҫ������<rot,������>root��
	//����ͨ���ݹ�ʵʱ���½ڵ���Ͻ�Max���½�Min��Ȼ��ȽϽڵ�ֵ�Ƿ��ڷ�Χ��
	//O(N),ÿ���ڵ����һ��
	//O(N),

	//Trick1:Ӧ��{2147483647} �����������ʵ���԰�int��Ϊlong
	//�״�㣺node->val <= Min || node->val >= Max�����ܵ���
	bool isValidBST(TreeNode* root) {
		return helper(root, LONG_MAX, LONG_MIN);
	}
	bool helper(TreeNode* node, long Max, long Min) {
		if (node == NULL) return true;
		if (node->val <= Min || node->val >= Max) return false;  //���ܵ���
		return helper(node->left, node->val, Min) && helper(node->right, Max, node->val);
	}
};

class Solution {
public:
	//˼·2:��������ݹ�
	//����Ҫ��֤��ڵ�<root���ҽڵ�>root������Ҫ������<rot,������>root��
	//����ͨ���ݹ�ʵʱ���½ڵ���Ͻ�Max���½�Min��Ȼ��ȽϽڵ�ֵ�Ƿ��ڷ�Χ��

	//Trick1:����ݹ麯��pre���ô�ֵ����ı�����ֵ������Ӱ�����ں����ⲿ��ֵ����������ʱpre�Ͳ���ǰ���ڵ��ֵ

	long pre = LONG_MIN;
	bool isValidBST(TreeNode* root) {
		return helper(root);
	}
	bool helper(TreeNode* node) {
		if (node == NULL) return true;
		if (!helper(node->left)) return false;
		if (node->val <= pre) return false;
		pre = node->val;
		if (!helper(node->right)) return false;
		return true;
	}
};


class Solution {
public:
	//˼·3:�����������
	//����ǰ���ڵ�

	//Trick1:����ݹ麯��pre���ô�ֵ����ı�����ֵ������Ӱ�����ں����ⲿ��ֵ����������ʱpre�Ͳ���ǰ���ڵ��ֵ


	bool isValidBST(TreeNode* root) {
		if (root == NULL) return true;
		long pre = LONG_MIN;
		stack<TreeNode*> data;
		TreeNode* cur = root;
		while (!data.empty() || cur != NULL) {
			if (cur) {
				//���������������
				data.push(cur);
				cur = cur->left;
			}
			else {
				//�ȴ�ӡ�ڵ㣬��ǰ���Ƚ���������
				TreeNode* temp = data.top();
				data.pop();
				if (temp->val <= pre) return false;
				pre = temp->val;
				cur = temp->right;
			}
		}
		return true;
	}
};