/*
������������k�����

��Ŀ����
����һ�ö��������������ҳ����еĵ�kС�Ľ�㡣���磬 ��5��3��7��2��4��6��8��    �У��������ֵ��С˳�����С����ֵΪ4��
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/
class Solution {
public:
	//���������k����
	int index;
	TreeNode* res;
	void Inorder(TreeNode* pRoot, int k) {
		if (!pRoot) return;
		Inorder(pRoot->left, k);
		++index;
		if (index == k) {
			res = pRoot;
			return;
		}
		Inorder(pRoot->right, k);
	}
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		index = 0;
		res = NULL;
		Inorder(pRoot, k);
		return res;
	}


};