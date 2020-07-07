//lt111
/*
111. ����������С���
����һ�����������ҳ�����С��ȡ�

��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������

˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ��:

���������� [3,9,20,null,null,15,7],

	3
   / \
  9  20
	/  \
   15   7

����������С���  2.

//˼·1���ݹ�
//˼·2��������BFS��
*/

class Solution {
public:
	//˼·1���ݹ�
	//���ڵ�����=min(��������С��ȣ���������С���)
	//�����������������ȣ�Ҫ������Ҷ���Ƿ�Ϊ�ս����жϣ���Ϊ�գ���ǿ�һ�ߵݹ�Ľ����������ȡmin
	//O(N)�����нڵ����һ�� 
	//O(logN)���ݹ����ĸ߶�
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		if (!root->left) return minDepth(root->right) + 1;
		if (!root->right) return minDepth(root->left) + 1;
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}

};

class Solution {
public:
	//˼·2��������BFS��
	//�������Ĳ�α���,����һ�α���������������Ϊ�յ�ʱ�򣬵ó����·��
	int minDepth(TreeNode* root) {
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
				if (!cur->left && !cur->right) return ++level;
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			++level;
		}
		return level;
	}

};