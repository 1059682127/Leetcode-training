
/*
�������´�ӡ������

��Ŀ����
�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��

//˼·1���������
//˼·2��
*/

class Solution {
public:
	//˼·1���������
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		if (root == NULL) return {};
		vector<int> res;
		queue<TreeNode*> q;
		TreeNode* cur = root;
		q.push(cur);
		while (!q.empty()) {
			cur = q.front();
			res.push_back(cur->val);  //��ӡ�ڵ�
			q.pop();
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}
		return res;
	}
};