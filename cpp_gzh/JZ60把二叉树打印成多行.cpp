/*
�Ѷ�������ӡ�ɶ���

��Ŀ����
���ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�

//˼·1���������
//˼·2����ȱ������ӱ�־��
*/

class Solution {
public:
	//˼·1���������
	vector<vector<int> > Print(TreeNode* pRoot) {
		if (pRoot == NULL) return {};
		vector<vector<int>> res;
		queue<TreeNode*> q;
		TreeNode* cur = pRoot;
		q.push(cur);
		int length = 0;
		while (!q.empty()) {
			int size = q.size();
			if (size > 0) res.push_back({});
			while (size > 0) {
				cur = q.front();
				res[length].push_back(cur->val);  //��ӡ�ڵ�
				--size;
				q.pop();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			++length;
		}
		return res;
	}

};

class Solution {
public:
	//˼·2����ȱ������ӱ�־��
	vector<vector<int> > Print(TreeNode* pRoot) {
		if (pRoot == NULL) return {};
		vector<vector<int>> res;
		helper(pRoot, 0, res);
		return res;
	}
	void helper(TreeNode* node, int level, vector<vector<int>> &res) {
		//�ж��Ƿ�����µ�һ��
		if (res.size() == level) res.push_back({});
		res[level].push_back(node->val);
		if (node->left) helper(node->left, level + 1, res);
		if (node->right) helper(node->right, level + 1, res);
	}

};