//lt341

/*
扁平化嵌套列表迭代器

给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。
列表中的每一项或者为一个整数，或者是另一个列表。

示例 1:
输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
示例 2:
输入: [1,[4,[6]]]
输出: [1,4,6]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,4,6]。

//思路1：递归

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
	//思路：递归
	//如果遍历的元素是整数isInteger() == true，直接添加到vector中，否则递归the nested list

	vector<int> data;
	vector<int>::iterator it;
	NestedIterator(vector<NestedInteger> &nestedList) {
		parse(nestedList);
		it = data.begin();
	}
	void parse(vector<NestedInteger> &nestedList) {
		for (auto &n : nestedList) {
			//判断是否为整数
			if (n.isInteger()) data.push_back(n.getInteger());
			//不是整数，为嵌套列表，递归
			else parse(n.getList());
		}
	}
	int next() {
		return *it++;  //返回修改前的一个副本
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