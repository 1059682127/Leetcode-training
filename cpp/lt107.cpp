//lt107

/*
107. �������Ĳ�α��� II
����һ����������������ڵ�ֵ�Ե����ϵĲ�α����� ��������Ҷ�ӽڵ����ڲ㵽���ڵ����ڵĲ㣬���������ұ�����

���磺
���������� [3,9,20,null,null,15,7],

	3
   / \
  9  20
	/  \
   15   7


�������Ե����ϵĲ�α���Ϊ��

[
  [15,7],
  [9,20],
  [3]
]
//˼·1�����У��Զ����µĲ��������+��ת
//˼·2�������������Ƕ�Ӧ������+��ת
//˼·3�����У��Զ����²�������������ǽ����insert��res.begin()��

//֪ʶ�㣺����洢��ʽ��vector<vector<int>>(res.rbegin(), res.rend());
*/

class Solution {
public:
	//˼·1�����У��Զ����µĲ��������+��ת
	//˼·2�������������Ƕ�Ӧ������+��ת
	//˼·3�����У��Զ����²�������������ǽ����insert��res.begin()��
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if (root == NULL) return {};
		queue<TreeNode*> q;
		int size = 0;
		TreeNode *cur = root;
		vector<vector<int>> res;
		q.push(cur);
		while (!q.empty()) {
			size = q.size();
			vector<int> temp;
			while (size > 0) {
				cur = q.front();
				q.pop();
				--size;
				if (cur != NULL) {
					temp.push_back(cur->val);
					//��ڵ���ҽڵ������
					q.push(cur->left);
					q.push(cur->right);
				}
			}
			if (temp.size() != 0) res.insert(res.begin(), temp); //ȥ��������,����ͷ��
		}
		return res;
	}
};