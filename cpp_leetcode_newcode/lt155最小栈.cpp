//lt155

/*
最小栈

设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

//思路1、双栈同步（保持数量相同，不用考虑边界问题，但会存放“不必要”元素）O(1)/O(N)
//思路2、双栈不同步（保存最小元素，要考虑边界问题）O(1)/O(N)
//思路3：单栈：用一个变量min保存栈内极小值O(1)/O(N)
*/


//执行用时:28 ms, 在所有 C++ 提交中击败了92.09%的用户
//内存消耗 :16.9 MB, 在所有 C++ 提交中击败了41.98%的用户
class MinStack {
public:
	/** initialize your data structure here. */
	//思路：1、双栈同步（保持数量相同，不用考虑边界问题，但会存放“不必要”元素）
	//Trick1:进栈时，当x <= helper.top()时，helper.push_back(x);当x > helper.top()时，helper.push_back(helper.top())
	//Trick2:出栈时，双栈push_back
	//Trick3:最小值即为helper.top();

	//知识点：stack进栈操作:stack.push(x)!!!

	stack<int> data;
	stack<int> helper; //保存较小值
	MinStack() {

	}

	void push(int x) {
		data.push(x);
		//当x <= helper.top()时，helper.push_back(x);
		if (helper.empty() || x <= helper.top()) helper.push(x);
		//当x > helper.top()时，helper.push_back(helper.top())
		else helper.push(helper.top());
	}

	void pop() {
		// 同时出栈（双栈同步）
		data.pop();
		helper.pop();
	}

	int top() {
		return data.top();
	}

	int getMin() {
		return helper.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



//执行用时:12 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗 :17 MB, 在所有 C++ 提交中击败了15.59%的用户
class MinStack {
public:
	/** initialize your data structure here. */
	//思路：2、双栈不同步（保存最小元素，要考虑边界问题）
	//Trick1:进栈时，当x <= helper.top()时，helper.push(x);（要考虑=，放入相同个数的最小值）
	//Trick2:出栈时，helper.top() = data.top()时，helper.pop()
	//Trick3:最小值即为helper.top();

	//知识点：stack进栈操作:stack.push(x)!!!

	stack<int> data;
	stack<int> helper;
	MinStack() {

	}

	void push(int x) {
		data.push(x);
		//当x <= helper.top()时，helper.push(x);（要考虑=，放入相同个数的最小值）
		if (helper.empty() || x <= helper.top()) helper.push(x);
	}

	void pop() {
		//注意先后顺序
		//helper.top() = data.top()时，helper.pop()
		if (data.top() == helper.top()) helper.pop();
		data.pop();
	}

	int top() {
		return data.top();
	}

	int getMin() {
		return helper.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//执行用时:28 ms, 在所有 C++ 提交中击败了92.09%的用户
//内存消耗 :16.9 MB, 在所有 C++ 提交中击败了55.88%的用户
class MinStack {
public:
	/** initialize your data structure here. */
	//思路3：单栈：用一个变量min保存栈内极小值
	//入栈：否则当x <= min时，先push(min),再push(x),再更新min = x
	//出栈：当data.top() == min时，先data.pop(),再min = data.top(),最后data.pop()
	//最小值:min

	stack<int> data;
	int min = INT_MAX;
	MinStack() {

	}

	void push(int x) {
		//当x <= min时，先push(min),再push(x),再更新min = x
		if (x <= min) {   //要考虑=号
			data.push(min);
			min = x;
		}
		data.push(x);

	}

	void pop() {
		//注意先后顺序
		//当data.top() == min时，先data.pop(),再min = data.top(),最后data.pop()
		if (data.top() == min) {
			data.pop();
			min = data.top();
		}
		data.pop();

	}

	int top() {
		return data.top();
	}

	int getMin() {
		return min;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */