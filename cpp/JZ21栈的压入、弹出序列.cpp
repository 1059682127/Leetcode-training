/*
 算法知识视频讲解
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/

class Solution {
public:
	//思路：新建一个栈，将A的元素依次入栈，当栈顶元素=B数组中元素时，出栈，否则入栈，最后判断栈是否为空
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() == 0 || popV.size() == 0 || pushV.size() != popV.size()) return false;
		int index = 0;
		stack<int> data;
		for (int i = 0; i < pushV.size(); ++i) {
			data.push(pushV[i]);
			while (data.size() != 0 && data.top() == popV[index] && index < popV.size()) {
				data.pop();
				++index;
			}
		}
		return data.empty();
	}
};