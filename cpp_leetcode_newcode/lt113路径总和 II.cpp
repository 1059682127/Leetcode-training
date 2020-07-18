//lt113

/*
·���ܺ� II

����һ����������һ��Ŀ��ͣ��ҵ����дӸ��ڵ㵽Ҷ�ӽڵ�·���ܺ͵��ڸ���Ŀ��͵�·����

˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ��:
�������¶��������Լ�Ŀ��� sum = 22��

			  5
			 / \
			4   8
		   /   / \
		  11  13  4
		 /  \    / \
		7    2  5   1


����:

[
   [5,4,11,2],
   [5,8,4,5]
]

//˼·1���ݹ�
*/

class Solution {
public:
	//˼·1���ݹ�
	//��Ҫ���ݽṹ��ά���м�·������Լ�������������������·����
	//�ڵݹ�Ĺ��̵ݼ�sum:sum-=root->val
	//��ֹ������
	//(1)root == NULL,return NULL;
	//(2)�ִ�Ҷ�ӽڵ㣬if(sum == 0) res.push_back(item)


	//Trick1:��Ϊ�ݹ��ʱ��ά������ͬһ��vector<int> item�����Ի��ݵ�ʱ��item.pop_back()

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> item;
		vector<vector<int>> res;
		helper(root, sum, item, res);
		return res;
	}
	void helper(TreeNode* root, int sum, vector<int>& item, vector<vector<int>>& res) {
		if (root == NULL) return;
		sum -= root->val;
		item.push_back(root->val);
		if (root->left == NULL && root->right == NULL && sum == 0) {
			res.push_back(item);
			return;
		}
		if (root->left) {
			helper(root->left, sum, item, res);
			//ע�⣡�������ݵ�ʱ��ȥ�����һ��
			item.pop_back();
		}
		if (root->right) {
			helper(root->right, sum, item, res);
			item.pop_back();
		}
	}
};