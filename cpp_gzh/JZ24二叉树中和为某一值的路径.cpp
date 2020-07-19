/*
 �㷨֪ʶ��Ƶ����
��Ŀ����
����һ�Ŷ������ĸ��ڵ��һ�����������ֵ����ӡ���������н��ֵ�ĺ�Ϊ��������������·����·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	vector<vector<int>> ans;
	void dfs(TreeNode* cur, int expectNumber, vector<int> temp) {
		//�����Ҷ�ڵ㣬�ж��Ƿ����Ŀ��ֵ
		temp.push_back(cur->val);
		if (cur->left == NULL && cur->right == NULL) {
			if (cur->val == expectNumber) {
				ans.push_back(temp);
			}
		}
		else {
			if (cur->left) {
				dfs(cur->left, expectNumber - cur->val, temp);
			}
			if (cur->right) {
				dfs(cur->right, expectNumber - cur->val, temp);
			}
		}
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == NULL) return {};
		dfs(root, expectNumber, {});
		return ans;
	}
};