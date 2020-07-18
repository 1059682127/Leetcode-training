//lt112

/*
·���ܺ�

����һ����������һ��Ŀ��ͣ��жϸ������Ƿ���ڸ��ڵ㵽Ҷ�ӽڵ��·��������·�������нڵ�ֵ��ӵ���Ŀ��͡�
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
ʾ��:
�������¶��������Լ�Ŀ��� sum = 22��
			  5
			 / \
			4   8
		   /   / \
		  11  13  4
		 /  \      \
		7    2      1
���� true, ��Ϊ����Ŀ���Ϊ 22 �ĸ��ڵ㵽Ҷ�ӽڵ��·�� 5->4->11->2��
//˼·1���ݹ飨�Զ����£�
//˼·2������

*/
class Solution {
public:
	//˼·1���ݹ飨�Զ����£�
	//�����ǰ�ڵ���Ҷ�ӣ���� sum ֵ�Ƿ�Ϊ 0��Ҳ�����Ƿ��ҵ��˸�����Ŀ���
	//�������Ҷ�ӣ�����������к��ӽڵ㣬�ݹ���� hasPathSum ���������� sum ֵ��ȥ��ǰ�ڵ��Ȩֵ��
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL) return false;
		sum -= root->val;
		if (root->left == NULL && root->right == NULL) return sum == 0;
		return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
	}

};

class Solution {
public:
	//˼·2������
	//����ǰ�ڵ��val����Ϊʣ���
	//�����Ҷ�ڵ㣬�ж�ʣ����Ƿ�Ϊ0
	//�������Ҷ�ڵ㣬����ڵ���ڣ�������ڵ��ʣ��ͣ���ջ������
	bool hasPathSum(TreeNode* root, int sum) {
		stack<TreeNode*> data;
		if (root == NULL) return false;
		root->val = sum - root->val;
		TreeNode *cur = NULL;
		data.push(root);
		while (!data.empty()) {
			cur = data.top();
			data.pop();
			//�����Ҷ�ӽڵ㣬�ж��Ƿ�Ϊ0
			if (cur->left == NULL && cur->right == NULL) {
				if (cur->val == 0) return true;
				else continue;
			}
			else {
				if (cur->left != NULL) {
					cur->left->val = cur->val - cur->left->val;
					data.push(cur->left);
				}
				if (cur->right != NULL) {
					cur->right->val = cur->val - cur->right->val;
					data.push(cur->right);
				}
			}
		}
		return false;
	}

};