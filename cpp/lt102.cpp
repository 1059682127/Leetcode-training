//lt102

/*
�������Ĳ�α���

����һ���������������䰴��α����Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��
����:
����������: [3,9,20,null,null,15,7],
	3
   / \
  9  20
	/  \
   15   7
�������α��������
[
  [3],
  [9,20],
  [15,7]
]

˼·1������������������У�O(N)/O(N)
˼·2����������������Ӳ�����־��
˼·3��DFS���ӱ��level��
*/

class Solution {
public:
	//˼·1������������������У�
	//ÿһ�����һ�Σ���¼��һ���Ԫ�ظ���size��size����0����һ��������
	vector<vector<int>> levelOrder(TreeNode* root) {
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
			if (temp.size() != 0) res.push_back(temp); //ȥ��������
		}
		return res;
	}
};

//ִ����ʱ:0 ms, ������ C++ �ύ�л�����100.00%���û�
//�ڴ����� :15 MB, ������ C++ �ύ�л�����9.57%���û�
class Solution {
public:
	//˼·2����������������Ӳ�����־��
	//ÿһ�����һ�Σ���¼��һ���Ԫ�ظ���size��size����0����һ��������

	//Trick1���ӱ�ǣ�level��,������ʱ����
	//Trick2��ֻ��cur->left != NULL�������

	//֪ʶ��1��
	//C++ ��ȡvector�������һ��Ԫ�� 

	//������vector<T>  vec;
	//����һ�� return vec.at(vec.size()-1);
	//�������� return vec.back();
	//�������� return vec.end()-1;  ע�⣺endָ��ĩβԪ�ص���һ��Ԫ�ء�
	//�����ģ� return vec.rbegin();
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL) return {};
		queue<TreeNode*> q;
		int size = 0;  //��¼���������еĽڵ�������һ�㣩
		TreeNode *cur = root;
		vector<vector<int>> res;
		int level = 0;
		q.push(cur);
		while (!q.empty()) {
			size = q.size();
			res.push_back({});
			while (size > 0) {
				cur = q.front();
				q.pop();
				--size;
				res[level].push_back(cur->val);
				//��ڵ���ҽڵ������
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			++level;
		}
		return res;
	}
};



class Solution {
public:
	//˼·3��DFS���ӱ��level��
	//�ݹ��ʱ�����res.size()==level������res����һ����{}������ǰ�ڵ���ӵ���Ӧ��
	//�ٵݹ���÷ǿյĺ��ӽڵ�
	vector<vector<int>> res;
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL) return {};
		helper(root, 0);
		return res;
	}
	void helper(TreeNode *root, int level) {
		if (res.size() == level) res.push_back({});
		res[level].push_back(root->val);
		if (root->left) helper(root->left, level + 1);
		if (root->right) helper(root->right, level + 1);
	}
};