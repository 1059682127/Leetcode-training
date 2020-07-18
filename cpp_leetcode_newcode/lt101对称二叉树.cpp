//lt101

/**
�Գƶ�����

����һ����������������Ƿ��Ǿ���ԳƵġ�
���磬������ [1,2,2,3,4,4,3] �ǶԳƵġ�
	1
   / \
  2   2
 / \ / \
3  4 4  3
����������� [1,2,2,null,3,null,3] ���Ǿ���ԳƵ�:
	1
   / \
  2   2
   \   \
   3    3

 //˼·1���ݹ�
 //˼·2������

 */
class Solution {
public:
	//˼·1���ݹ�
	/*
	���һ������������������������Գƣ���ô������ǶԳƵġ�
	��������ʲô����»�Ϊ����
	���ͬʱ�����������������������Ϊ����
		(1)���ǵ���������������ͬ��ֵ��
		(2)ÿ������������������һ����������������Գơ�

	��һ����⣺�������������෴˳��ı�����
	A�ڵ������������ǰ�������DLR������ǰ���, ����, �Һ��ӡ�
	ͬʱ��A�ڵ�����������С�DRL������ǰ���, �Һ���, ���ӡ�������
	*/
	bool isSymmetric(TreeNode* root) {
		return helper(root, root);
	}
	bool helper(TreeNode* left, TreeNode* right) {
		//�߽�
		if (left == NULL && right == NULL) return true;
		if (left == NULL || right == NULL) return false;
		return left->val == right->val && helper(left->right, right->left) && helper(left->left, right->right);
	}
};

class Solution {
public:
	//˼·2������
	/*
	����BFS˼�루�ö��У������������Ľڵ�Ӧ������ͬ�ģ���������а������� root��root��
	ÿ����ȡ������㲢�Ƚ����ǵ�ֵ��Ȼ�󣬽��������������ӽ�㰴�෴��˳���������С�
	����������������Ϊ��ʱ���������Ǽ�⵽�����Գƣ����Ӷ�����ȡ����������ȵ�������㣩
	*/
	bool isSymmetric(TreeNode* root) {
		queue<TreeNode*> data;
		data.push(root);
		data.push(root);
		TreeNode *t1 = NULL, *t2 = NULL;
		while (!data.empty()) {
			t1 = data.front();
			data.pop();  //�ǵ�ȡֵ֮�����ϵ���
			t2 = data.front();
			data.pop();
			if (t1 == NULL && t2 == NULL) continue;
			if (t1 == NULL || t2 == NULL) return false;
			if (t1->val != t2->val) return false;
			data.push(t1->left);
			data.push(t2->right);
			data.push(t1->right);
			data.push(t2->left);
		}
		return true;
	}
};