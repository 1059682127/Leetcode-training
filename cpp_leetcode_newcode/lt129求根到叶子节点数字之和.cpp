//lt129

/*
129. �����Ҷ�ӽڵ�����֮��

����һ��������������ÿ����㶼���һ�� 0-9 �����֣�ÿ���Ӹ���Ҷ�ӽڵ��·��������һ�����֡�

���磬�Ӹ���Ҷ�ӽڵ�·�� 1->2->3 �������� 123��

����Ӹ���Ҷ�ӽڵ����ɵ���������֮�͡�

˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ�� 1:

����: [1,2,3]
	1
   / \
  2   3
���: 25
����:
�Ӹ���Ҷ�ӽڵ�·�� 1->2 �������� 12.
�Ӹ���Ҷ�ӽڵ�·�� 1->3 �������� 13.
��ˣ������ܺ� = 12 + 13 = 25.

//˼·1���ݹ顢���� O(N)/O(logN)
//˼·2���ݹ�
*/



class Solution {
public:
	//˼·1���ݹ顢����
	//�ݹ��ʱ��num = num*10 + root->val;���ݵ�ʱ��num /= 10
	//ά��num���еݹ飬�ڻ��ݵ�ʱ��ȥ�����һ��Ԫ��
	//Trick1:��Ϊnum�ı�֮��Ҫ���˵���һ�㣬���Բ���&
	int sumNumbers(TreeNode* root) {
		int res = 0;
		int num = 0;
		sumNumbers(root, res, num);
		return res;
	}
	void sumNumbers(TreeNode* root, int& res, int& num) {
		if (root == NULL) return;
		num = num * 10 + root->val;
		//��Ҷ�ӽڵ�
		if (root->left == NULL && root->right == NULL) {
			res += num;
			return;
		}
		if (root->left) {
			sumNumbers(root->left, res, num);
			//����
			num /= 10;
		}
		if (root->right) {
			sumNumbers(root->right, res, num);
			num /= 10;
		}
	}
};

class Solution {
public:
	//˼·2���ݹ�
	//�ݹ��ʱ��num = num*10 + root->val
	//��root��Ҷ�ӽڵ�ʱ��res += num
	//Trick2:num������&,��ǰnum�ı䲻��Ӱ����һ��ݹ��num
	//
	int sumNumbers(TreeNode* root) {
		int res = 0;
		int num = 0;
		sumNumbers(root, res, num);
		return res;
	}
	void sumNumbers(TreeNode* root, int& res, int num) {
		if (root == NULL) return;
		num = num * 10 + root->val;
		//��Ҷ�ӽڵ�
		if (root->left == NULL && root->right == NULL) {
			res += num;
			return;
		}
		if (root->left) {
			sumNumbers(root->left, res, num);
		}
		if (root->right) {
			sumNumbers(root->right, res, num);
		}
	}
};