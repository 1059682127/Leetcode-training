//lt104
/*
��������������

����һ�����������ҳ��������ȡ�
�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
ʾ����
���������� [3,9,20,null,null,15,7]��
	3
   / \
  9  20
	/  \
   15   7
�������������� 3 ��
//˼·1���Զ����µ�DFS
//˼·2���Ե����ϵ�DFS
//˼·3��BFS(����)���������˺󣬱�������level��������
*/

class Solution {
public:
	//˼·1���Զ����µ�DFS
	//����ǰ�������max(depth, answer)
	int answer;
	int maxDepth(TreeNode* root) {
		answer = 0;
		helper(root, 1);
		return answer;
	}
	void helper(TreeNode* root, int depth) {
		if (root == NULL) return;
		answer = max(depth, answer);
		helper(root->left, depth + 1);
		helper(root->right, depth + 1);
	}
};

class Solution {
public:
	//˼·2���Ե����ϵ�DFS
	//���ƺ��������max(left_height, right_heigh) + 1
	int maxDepth(TreeNode* root) {
		return helper(root);
	}
	int helper(TreeNode* root) {
		if (root == NULL) return 0;
		int left_height = helper(root->left);
		int right_height = helper(root->right);
		return max(left_height, right_height) + 1;
	}
};

class Solution {
public:
	//˼·3:BFS(����)���������˺󣬱�������level��������

	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		queue<TreeNode*> q;
		int size = 0;  //��¼���������еĽڵ�������һ�㣩
		TreeNode *cur = root;
		int level = 0;
		q.push(cur);
		while (!q.empty()) {
			size = q.size();
			while (size > 0) {
				cur = q.front();
				q.pop();
				--size;
				//��ڵ���ҽڵ������
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			++level;
		}
		return level;
	}
};