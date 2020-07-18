//lt99
/*
�ָ�����������

�����������е������ڵ㱻����ؽ�����

���ڲ��ı���ṹ������£��ָ��������

ʾ�� 1:

����: [1,3,null,null,2]

   1
  /
 3
  \
   2

���: [3,1,null,null,2]

   3
  /
 1
  \
   2


ʾ�� 2:

����: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

���: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3

//˼·1������������ݹ飩
//˼·2�����������������
//˼·3�����������Ī��˹������
*/

class Solution {
public:
	//˼·1������������ݹ飩
	//ʾ��2��������õ�1 3 2 4���ؼ�����ô�ҵ�3��2 �����н���
	//��һ���ڵ�,�ǵ�һ�������������ʱ��ǰһ���ڵ���ں�һ���ڵ�,����ѡȡǰһ���ڵ�
	//�ڶ����ڵ�,���ڵ�һ���ڵ��ҵ�֮��, �������ǰһ���ڵ���ں�һ���ڵ�,����ѡ���һ���ڵ�
	TreeNode* firstNode = NULL;
	TreeNode* secondNode = NULL;
	TreeNode* pre = new TreeNode(INT_MIN);
	void recoverTree(TreeNode* root) {
		helper(root);
		int temp = firstNode->val;
		firstNode->val = secondNode->val;
		secondNode->val = temp;
	}
	void helper(TreeNode* node) {
		if (node == NULL) return;
		helper(node->left);
		if (!firstNode && node->val < pre->val) firstNode = pre;
		if (firstNode && node->val < pre->val) secondNode = node;
		pre = node;
		helper(node->right);
	}
};

class Solution {
public:
	//˼·2�����������������
	//ʾ��2��������õ�1 3 2 4���ؼ�����ô�ҵ�3��2 �����н���
	//��һ���ڵ�,�ǵ�һ�������������ʱ��ǰһ���ڵ���ں�һ���ڵ�,����ѡȡǰһ���ڵ�
	//�ڶ����ڵ�,���ڵ�һ���ڵ��ҵ�֮��, �������ǰһ���ڵ���ں�һ���ڵ�,����ѡ���һ���ڵ�

	void recoverTree(TreeNode* root) {
		if (root == NULL) return;
		TreeNode* firstNode = NULL;
		TreeNode* secondNode = NULL;
		TreeNode* pre = new TreeNode(INT_MIN);
		stack<TreeNode*> data;
		TreeNode* cur = root;
		while (!data.empty() || cur != NULL) {
			if (cur) {
				data.push(cur);
				cur = cur->left;
			}
			else {
				//�ȴ�ӡ�ڵ�
				TreeNode* temp = data.top();
				data.pop();
				if (!firstNode && temp->val < pre->val) firstNode = pre;
				if (firstNode && temp->val < pre->val) secondNode = temp;
				pre = temp;
				cur = temp->right;
			}
		}
		int temp = firstNode->val;
		firstNode->val = secondNode->val;
		secondNode->val = temp;
	}

};

class Solution {
public:
	//˼·3�����������Ī��˹������
	//ʾ��2��������õ�1 3 2 4���ؼ�����ô�ҵ�3��2 �����н���
	//��һ���ڵ�,�ǵ�һ�������������ʱ��ǰһ���ڵ���ں�һ���ڵ�,����ѡȡǰһ���ڵ�
	//�ڶ����ڵ�,���ڵ�һ���ڵ��ҵ�֮��, �������ǰһ���ڵ���ں�һ���ڵ�,����ѡ���һ���ڵ�

	//˼·�������������Ī��˹�棬�����ڴ�ӡ�ڵ�ĵط�����Ѱ��firstNode, secondNode
	void recoverTree(TreeNode* root) {
		if (root == NULL) return;
		TreeNode* firstNode = NULL;
		TreeNode* secondNode = NULL;
		TreeNode* pre = new TreeNode(INT_MIN);   //���ڱ������������ǰ���ڵ�
		TreeNode *cur = root, *prev = NULL;
		while (cur != NULL) {
			//���cur�����ӣ������ǰ�ڵ�,cur�����ƶ���cur=cur.right��
			if (cur->left == NULL) {
				if (!firstNode && cur->val < pre->val) firstNode = pre;
				if (firstNode && cur->val < pre->val) secondNode = cur;
				pre = cur;
				cur = cur->right;
			}
			else {
				//���cur�����ӣ��ҵ�cur�����������ҵĽڵ㣬��Ϊmostright����ǰ�ڵ������������ǰ���ڵ㣩
				prev = cur->left;
				while (prev->right && prev->right != cur) {
					prev = prev->right;
				}
				//���mostright��rightָ��ָ��գ�����ָ��cur��cur�����ƶ���cur=cur.left��
				if (prev->right == NULL) {
					prev->right = cur;
					cur = cur->left;
				}
				//���mostright��rightָ��ָ��cur������ָ��գ������ǰ�ڵ㣬cur�����ƶ���cur=cur.right��
				else {
					prev->right = NULL;
					if (!firstNode && cur->val < pre->val) firstNode = pre;
					if (firstNode && cur->val < pre->val) secondNode = cur;
					pre = cur;
					cur = cur->right;
				}
			}
		}
		int temp = firstNode->val;
		firstNode->val = secondNode->val;
		secondNode->val = temp;
	}

};