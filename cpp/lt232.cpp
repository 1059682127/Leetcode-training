//lt232
/*
用栈实现队列

使用栈实现队列的下列操作：
push(x) -- 将一个元素放入队列的尾部。
pop() -- 从队列首部移除元素。
peek() -- 返回队列首部的元素。
empty() -- 返回队列是否为空。
示例:
MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false
//思路1：双栈，push的时候，若stack1非空，将stack1的顺序出栈到stack2，push(新进元素)，再吧元素从stack2出栈到stack1
//思路2：双栈+摊还分析

*/

class MyQueue {
public:
	//问题核心是每次新进的元素到栈底，其它顺序保持不变
	//思路1：双栈，push的时候，若stack1非空，将stack1的顺序出栈到stack2，push(新进元素)，再吧元素从stack2出栈到stack1
	/** Initialize your data structure here. */
	stack<int> stack1;
	stack<int> stack2;
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		while (!stack1.empty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}
		stack1.push(x);
		while (!stack2.empty()) {
			stack1.push(stack2.top());
			stack2.pop();
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int res = stack1.top();
		stack1.pop();
		return res;
	}

	/** Get the front element. */
	int peek() {
		return stack1.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return stack1.empty();
	}
};



class MyQueue {
public:
	//问题核心是每次新进的元素到栈底，其它顺序保持不变
	//思路2：双栈+摊还分析
	//stack1保存新进的元素到栈顶，第一次出栈的时候，将stack1的元素反转到stack2中，花费0(2N - 1)时间，后续出栈的时候只需要从stack2中出栈，花费O(1)时间直到stack2空栈，再重新从stack1中挪过来
	//所有操作的总时间复杂度为：n(所有的入队操作产生） + 2 * n(第一次出队操作产生） + n - 1(剩下的出队操作产生）， 所以实际时间复杂度为 O(2∗n)。于是我们可以得到每次操作的平均时间复杂度为 O(2n/2n)=O(1)

	/** Initialize your data structure here. */
	stack<int> stack1;
	stack<int> stack2;
	int front; //保存stack1的栈底元素
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		if (stack1.empty()) front = x;
		stack1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
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

	/** Get the front element. */
	int peek() {
		if (!stack2.empty()) return stack2.top();
		else return front;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return stack1.empty() && stack2.empty();
	}
};

