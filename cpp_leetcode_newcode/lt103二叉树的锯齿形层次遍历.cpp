//lt103
/*
�������ľ���β�α���
����һ����������������ڵ�ֵ�ľ���β�α����������ȴ������ң��ٴ������������һ��������Դ����ƣ������֮�佻����У���

���磺
���������� [3,9,20,null,null,15,7],

	3
   / \
  9  20
	/  \
   15   7


���ؾ���β�α������£�

[
  [3],
  [20,9],
  [15,7]
]

//˼·1��˫ջO(N)/O(N)

*/

class Solution {
public:
	//˼·1��˫ջ
	//������ʱ��ż�����������ң�����������������

	//Ҫʵ�����������������ȷ��ʣ�����˫ջ��һ��ջ��ջ��һ��ڵ㣬��һ��ջ��ջ����ò�ڵ㣩
	//������ӵ�ʱ��Բ���������ż���жϣ�����ʱ�������ҽڵ㣬������ڵ㣻ż������������ڵ㣬�����ҽڵ�
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		//�߽�����
		if (root == NULL) return {};
		stack<TreeNode*> data;
		vector<vector<int>> res;
		data.push(root);
		res.push_back(vector<int>(1, root->val));
		TreeNode* cur = NULL;
		int level = 1;
		while (!data.empty()) {
			int size = data.size();
			cout << size << endl;
			vector<int> temp;
			stack<TreeNode*> newStack;
			while (size > 0) {
				cur = data.top();
				data.pop();
				--size;
				//ż��
				if (level % 2 == 0) {
					if (cur->left) {
						newStack.push(cur->left);
						temp.push_back(cur->left->val);
					}
					if (cur->right) {
						newStack.push(cur->right);
						temp.push_back(cur->right->val);
					}
				}
				else {
					if (cur->right) {
						newStack.push(cur->right);
						temp.push_back(cur->right->val);
					}
					if (cur->left) {
						newStack.push(cur->left);
						temp.push_back(cur->left->val);
					}
				}
			}
			if (temp.size() != 0) res.push_back(temp);
			++level;
			data = newStack;
		}
		return res;
	}
};
