/*
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

class Solution
{
	//入队列，存到stack1，出队列，从stack2栈顶弹出，没有的话从stack1转移元素到stack2
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack1.empty() && stack2.empty()) return -1;
		if (stack2.empty()) {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int res = stack2.top();
		stack2.pop();
		return res;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};