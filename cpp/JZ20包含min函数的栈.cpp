/*
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

class Solution {
public:
	//思路3：单栈：用一个变量min保存栈内极小值，当更新极小值时，先push_back之前的min
	//入栈：否则当x <= min时，先push(min),再push(x),再更新min = x
	//出栈：当data.top() == min时，先data.pop(),再min = data.top(),最后data.pop()
	//最小值:min
	stack<int> data;
	int Min = INT_MAX;
	void push(int value) {
		if (value >= Min) data.push(value);
		else {
			data.push(Min);
			data.push(value);
			Min = value;
		}
	}
	void pop() {
		if (data.top() == Min) {
			data.pop();
			Min = data.top();
			data.pop();
		}
		else {
			data.pop();
		}
	}
	int top() {
		return data.top();
	}
	int min() {
		return Min;
	}
};