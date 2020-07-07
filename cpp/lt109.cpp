//lt109
/*
109. ��������ת������������

����һ�����������е�Ԫ�ذ��������򣬽���ת��Ϊ�߶�ƽ��Ķ�����������

�����У�һ���߶�ƽ���������ָһ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1��

ʾ��:

�������������� [-10, -3, 0, 5, 9],

һ�����ܵĴ��ǣ�[0, -3, 9, -10, null, 5], �����Ա�ʾ��������߶�ƽ�������������

	  0
	 / \
   -3   9
   /   /
 -10  5

 //˼·1������ָ���ҵ�������е�
 //˼·2���ݹ�ģ���������

*/

class Solution {
public:
	//˼·1������ָ���ҵ�������е�
	//��Ŀ��⣺�õ�����һ������������������飬���ǲ���ֱ��ʹ���±�������Ԫ�ء�������Ҫ֪�������е��м�Ԫ�ء�

	//˼·2���������
	//���ݶ������������ʣ�������������������õ�������������
	//���Խ�������������ڴ�ӡ�ڵ�ĵط������ڵ�
	//ʱ��O(N),�������нڵ����һ��
	//�ռ�O(logN),�ݹ����߶�ΪO(logN)

	//���裺
	//1��ͳ������ĳ���
	//2���ҵ��е�mid,�ݹ�������������ǰ�ڵ㣨ͬʱ��ȡ�������һ�ڵ�,�����ӡ�ڵ��ʱ��˳���ӡ��������ʱ��Ҳ��˳�򴴽������ݹ�������
	//3�����ظ��ڵ�

	//ע�⣺��ȫ�ֵ�node������
	ListNode* node;
	TreeNode* sortedListToBST(ListNode* head) {
		int len = 0;
		ListNode* cur = head;
		node = head;
		while (cur) {
			++len;
			cur = cur->next;
		}
		return inOrder(0, len - 1);

	}
	TreeNode* inOrder(int start, int end) {
		if (start > end) return NULL;
		int mid = (start + end) / 2;
		TreeNode* leftChild = inOrder(start, mid - 1);
		TreeNode* father = new TreeNode(node->val);
		node = node->next;
		TreeNode* rightChild = inOrder(mid + 1, end);
		father->left = leftChild;
		father->right = rightChild;
		return father;
	}
};