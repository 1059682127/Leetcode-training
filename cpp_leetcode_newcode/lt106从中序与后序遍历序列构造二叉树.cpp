//lt106
/*
�����������������й��������

����һ��������������������������������
ע��:
����Լ�������û���ظ���Ԫ�ء�
���磬����
������� inorder = [9,3,15,20,7]
������� postorder = [9,15,7,20,3]
�������µĶ�������
	3
   / \
  9  20
	/  \
   15   7

//˼·1�����Σ��ݹ飩
*/

class Solution {
public:
	//˼·1�����Σ��ݹ飩
	//�������ԣ�
	//1���ں������������,���һ��Ԫ��Ϊ���ĸ��ڵ�
	//2�����������������,���ڵ�����Ϊ�����������ڵ���ұ�Ϊ������
	//���Ͻ����黮��Ϊ����������������������СΪ1��������ΪҶ�ڵ�
	//�������飺���ڵ�ri, ����������in_lo~ri-1, ���������飬ri+1~in_hi
	//�������飺���ڵ�post_hi,����������post_lo~post_lo-in_lo+ri-1������������post_lo-in_lo+ri~post_hi-1

	//Trick1:�ù�ϣ���������������������,Ԫ�غ�������λ�ù�ϵ.��Ϊ�Ӻ����������õ����ڵ��Ҫ�����������в��Ҷ�Ӧ��λ��,�Ӷ��������Ϊ��������������
	map<int, int> hash_table;
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

		for (int i = 0; i < inorder.size(); ++i) hash_table[inorder[i]] = i;
		return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	}
	TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int in_lo, int in_hi, int post_lo, int post_hi) {
		//�����СΪ0����Ϊ������
		if (in_lo > in_hi || post_lo > post_hi) return NULL;
		//������ǿ���������ȷ����������������һ��Ԫ�أ����ڵ㣩��������������е�����
		int root = postorder[post_hi];
		int ri = hash_table[root];
		//�ö���
		TreeNode* node = new TreeNode(root);
		//������������
		node->left = helper(inorder, postorder, in_lo, ri - 1, post_lo, post_lo - in_lo + ri - 1);
		node->right = helper(inorder, postorder, ri + 1, in_hi, post_lo - in_lo + ri, post_hi - 1);
		return node;
	}
};