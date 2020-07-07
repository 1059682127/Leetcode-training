//lt341

/*
��ƽ��Ƕ���б������

����һ��Ƕ�׵������б��������һ����������ʹ���ܹ�������������б��е�����������
�б��е�ÿһ�����Ϊһ����������������һ���б�

ʾ�� 1:
����: [[1,1],2,[1,1]]
���: [1,1,2,1,1]
����: ͨ���ظ����� next ֱ�� hasNext ���� false��next ���ص�Ԫ�ص�˳��Ӧ����: [1,1,2,1,1]��
ʾ�� 2:
����: [1,[4,[6]]]
���: [1,4,6]
����: ͨ���ظ����� next ֱ�� hasNext ���� false��next ���ص�Ԫ�ص�˳��Ӧ����: [1,4,6]��

//˼·1���ݹ�

*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
	//˼·���ݹ�
	//���������Ԫ��������isInteger() == true��ֱ����ӵ�vector�У�����ݹ�the nested list

	vector<int> data;
	vector<int>::iterator it;
	NestedIterator(vector<NestedInteger> &nestedList) {
		parse(nestedList);
		it = data.begin();
	}
	void parse(vector<NestedInteger> &nestedList) {
		for (auto &n : nestedList) {
			//�ж��Ƿ�Ϊ����
			if (n.isInteger()) data.push_back(n.getInteger());
			//����������ΪǶ���б��ݹ�
			else parse(n.getList());
		}
	}
	int next() {
		return *it++;  //�����޸�ǰ��һ������
	}

	bool hasNext() {
		return it != data.end();
	}
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */