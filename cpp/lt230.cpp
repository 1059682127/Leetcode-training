//lt230
/*
�����������е�KС��Ԫ��

����һ����������������дһ������ kthSmallest ���������е� k ����С��Ԫ�ء�
˵����
����Լ��� k ������Ч�ģ�1 �� k �� ����������Ԫ�ظ�����
ʾ�� 1:
����: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
���: 1
ʾ�� 2:
����: root = [5,3,6,2,4,null,null,1], k = 3
	   5
	  / \
	 3   6
	/ \
   2   4
  /
 1
���: 3

//˼·1���ݹ飨���������
//˼·2������
*/

class Solution {
public:
	//˼·1���ݹ飨���������
	//BST �������������������
	int kthSmallest(TreeNode* root, int k) {
		int res = 0;
		helper(root, k, res);
		return res;
	}
	void helper(TreeNode* root, int& k, int& res) {
		if (root == NULL) return;
		helper(root->left, k, res);
		--k;
		if (k == 0) {
			res = root->val;
			return;
		}
		helper(root->right, k, res);
	}
};

class Solution {
public:
	//˼·2������
	//BST �������������������
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> data;
		data.push(root);
		while (!data.empty()) {
			//������
			if (root) {
				data.push(root);
				root = root->left;
			}
			else {
				//���ʸ��ڵ�
				TreeNode* temp = data.top();
				data.pop();
				--k;
				if (k == 0) return temp->val;
				root = temp->right;
			}
		}
		return -1;
	}
};