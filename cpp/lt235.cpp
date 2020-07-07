//lt235
/*
�����������������������

����һ������������, �ҵ�����������ָ���ڵ������������ȡ�

�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����

���磬�������¶���������:  root = [6,2,8,0,4,7,9,null,null,3,5]

//˼·1���ݹ�
//˼·2������
*/

class Solution {
public:
	//˼·1���ݹ�

	//�Ӹ��ڵ㿪ʼ������
	//����ڵ� p �ͽڵ� q �����������ϣ���ô���Һ���Ϊ���ڵ���� 1 �Ĳ���
	//����ڵ� p �ͽڵ� q �����������ϣ���ô������Ϊ���ڵ���� 1 �Ĳ���
	//������� 2 ������ 3 ���������������ζ�������Ѿ��ҵ��� p �ͽڵ� q �� LCA ��

	//Trick1:���ö��������������ʿ��������жϽڵ���������������������

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) return NULL;
		if (p->val < root->val && q->val < root->val) {
			root = root->left;
		}
		else if (p->val > root->val && q->val > root->val) {
			root = root->right;
		}
		else {
			return root;
		}
		return lowestCommonAncestor(root, p, q);
	}
};

class Solution {
public:
	//˼·2������

	//�Ӹ��ڵ㿪ʼ������
	//����ڵ� p �ͽڵ� q �����������ϣ���ô���Һ���Ϊ���ڵ���� 1 �Ĳ���
	//����ڵ� p �ͽڵ� q �����������ϣ���ô������Ϊ���ڵ���� 1 �Ĳ���
	//������� 2 ������ 3 ���������������ζ�������Ѿ��ҵ��� p �ͽڵ� q �� LCA ��

	//Trick1:���ö��������������ʿ��������жϽڵ���������������������

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) return NULL;
		TreeNode* cur = root;
		while (true) {
			//��������
			if (p->val < cur->val && q->val < cur->val) cur = cur->left;
			else if (p->val > cur->val && q->val > cur->val) cur = cur->right;
			else return cur;
		}
	}
};