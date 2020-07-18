//lt105
/*
��ǰ��������������й��������

����һ������ǰ�������������������������
ע��:
����Լ�������û���ظ���Ԫ�ء�
���磬����
ǰ����� preorder = [3,9,20,15,7]
������� inorder = [9,3,15,20,7]
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
	//1����ǰ�����������,��һ��Ԫ��Ϊ���ĸ��ڵ�
	//2�����������������,���ڵ�����Ϊ�����������ڵ���ұ�Ϊ������
	//���Ͻ����黮��Ϊ����������������������СΪ1��������ΪҶ�ڵ�
	//�������飺���ڵ�ri, ����������in_lo~ri-1, ���������飬ri+1~in_hi(������������ȷ��������������)
	//ǰ�����飺���ڵ�prev_lo,����������prev_lo+1~prev_lo-in_lo+ri������������prev_lo-in_lo+ri+1~prev_hi
	map<int, int> hash_table;
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		for (int i = 0; i < inorder.size(); ++i) hash_table[inorder[i]] = i;
		return helper(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
	}
	TreeNode* helper(vector<int>& inorder, vector<int>& prevorder, int in_lo, int in_hi, int prev_lo, int prev_hi) {
		//�����СΪ0����Ϊ������
		if (in_lo > in_hi || prev_lo > prev_hi) return NULL;
		//������ǿ���������ȷ����������������һ��Ԫ�أ����ڵ㣩��������������е�����
		int root = prevorder[prev_lo];
		int ri = hash_table[root];
		//�ö���
		TreeNode* node = new TreeNode(root);
		//������������
		node->left = helper(inorder, prevorder, in_lo, ri - 1, prev_lo + 1, prev_lo - in_lo + ri);
		node->right = helper(inorder, prevorder, ri + 1, in_hi, prev_lo - in_lo + ri + 1, prev_hi);
		return node;
	}
};