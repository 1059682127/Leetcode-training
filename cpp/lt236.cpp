//lt236
/*
�������������������

����һ��������, �ҵ�����������ָ���ڵ������������ȡ�
�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����
���磬�������¶�����:  root = [3,5,1,6,2,0,8,null,null,7,4]


ʾ�� 1:
����: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
���: 3
����: �ڵ� 5 �ͽڵ� 1 ��������������ǽڵ� 3��

//˼·1���������+����
//˼·2:�ݹ�
*/

class Solution {
public:
	//˼·1���������+����
	//�Ӹ��ڵ㿪ʼ������
	//����ڵ� p �ͽڵ� q �����������ϣ���ô���Һ���Ϊ���ڵ���� 1 �Ĳ���
	//����ڵ� p �ͽڵ� q �����������ϣ���ô������Ϊ���ڵ���� 1 �Ĳ���
	//������� 2 ������ 3 ���������������ζ�������Ѿ��ҵ��� p �ͽڵ� q �� LCA ��

	//�����������ȷ�������������ڵ㡢������
	map<TreeNode*, int> hash_table;
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		int k = 0;
		TreeNode* cur = root;
		helper(cur, k);
		//�����������������ڵ�����
		cur = root;
		while (true) {
			//��������
			if (hash_table[p] < hash_table[cur] && hash_table[q] < hash_table[cur]) cur = cur->left;
			else if (hash_table[p] > hash_table[cur] && hash_table[q] > hash_table[cur]) cur = cur->right;
			else return cur;
		}
	}
	void helper(TreeNode* root, int &k) {
		if (root == NULL) return;
		helper(root->left, k);
		hash_table[root] = k;
		++k;
		helper(root->right, k);
	}
};

class Solution {
public:
	//˼·2:�ݹ�
	//�������£�
	//�����ǰ���root����NULL����ֱ�ӷ���NULL
	//���root����p����q���������һ������p����q
	//Ȼ�󿴵ݹ�������������Ϊ�ǵݹ飬ʹ�ú����������Ϊ���������Ѿ�����˽������left��right��ʾ
	//��ʱ��leftΪ�գ������ս��ֻҪ��right����rightΪ�գ������ս��ֻҪ��left
	//���left��right���ǿգ���Ϊֻ����p��q������㣬���ǿգ�˵��һ��һ�������root�����ǵ������������
	//���left��right��Ϊ�գ��򷵻ؿգ���ʵ�Ѿ�������ǰ���������ˣ�

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		return helper(root, p, q);
	}
	TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) return NULL;
		if (root == p) return p;
		if (root == q) return q;
		TreeNode* left = helper(root->left, p, q);
		TreeNode* right = helper(root->right, p, q);
		if (left && right) return root;
		if (left == NULL) return right;
		if (right == NULL) return left;
		return NULL;
	}

};