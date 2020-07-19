
/*
��Ŀ����

�����������ĵ�k�����
����һ�ö��������������ҳ����еĵ�kС�Ľ�㡣���磬 ��5��3��7��2��4��6��8��    �У��������ֵ��С˳�����С����ֵΪ4��

//˼·1�����������k���ڵ� O(k)/O(logN)
//˼·2:���������������
*/


class Solution {
public:
	//˼·1�����������k���ڵ� O(k)/O(logN)
	int curIndex;
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		//�߽�����
		if (pRoot == NULL) return NULL;
		if (k == 0) return NULL;
		curIndex = 1;
		return helper(pRoot, k);
	}
	TreeNode* helper(TreeNode* cur, int k) {
		if (cur == NULL) return NULL;
		TreeNode* ret = helper(cur->left, k);
		if (ret) return ret;
		if (curIndex++ == k) return cur;
		ret = helper(cur->right, k);
		if (ret) return ret;
	}

};

class Solution {
public:
	//˼·2:���������������
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		//�߽�����
		if (pRoot == NULL) return NULL;
		if (k == 0) return NULL;
		int curIndex = 1;
		stack<TreeNode*> data;
		TreeNode* cur = pRoot;
		while (!data.empty() || cur) {
			if (cur) {
				//��ջ����ָ����һ��ڵ�
				data.push(cur);
				cur = cur->left;
			}
			else {
				//��ӡ�ڵ�
				TreeNode* temp = data.top();
				data.pop();
				if (curIndex++ == k) return temp;
				cur = temp->right;
			}
		}
		return NULL;
	}
};