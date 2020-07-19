/*
��֮����˳���ӡ������

��Ŀ����
��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�

//˼·1����ջ+���У�������ʣ�
*/


class Solution {
public:
	//˼·1����ջ+���У�������ʣ�
	//ջʵ��������ʣ�ͬʱ�ö��б�����һ���Ԫ�أ���������Һ��󱣴棬ż����������ұ��棩
	vector<vector<int> > Print(TreeNode* pRoot) {
		if (pRoot == NULL) return {};
		vector<vector<int>> res;
		int level = 1;
		stack<TreeNode*> data;
		queue<TreeNode*> q;
		TreeNode* cur = pRoot;
		data.push(cur);
		res.push_back({ cur->val });  //�ȱ����һ��
		while (!data.empty()) {
			int size = data.size();
			vector<int> temp;
			while (size > 0) {
				cur = data.top();
				data.pop();
				--size;
				//����������㣬�����ҽڵ���ջ������ڵ���ջ����ջ�����浽���
				if (level % 2 == 0) {
					if (cur->left) {
						q.push(cur->left);
						temp.push_back(cur->left->val);
					}
					if (cur->right) {
						q.push(cur->right);
						temp.push_back(cur->right->val);
					}
				}
				else {
					if (cur->right) {
						q.push(cur->right);
						temp.push_back(cur->right->val);
					}
					if (cur->left) {
						q.push(cur->left);
						temp.push_back(cur->left->val);
					}
				}
			}
			if (temp.size() > 0) res.push_back(temp);
			//�������е�Ԫ���Ƶ�ջ
			while (!q.empty()) {
				data.push(q.front());
				q.pop();
			}
			++level;
		}
		return res;
	}

};