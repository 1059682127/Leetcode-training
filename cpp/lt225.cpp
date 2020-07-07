//lt225

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
说明:
你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。

//思路1：双队列(push O(1), pop O(N))(新进元素从q1入队列，出栈时，q1出队列直到只有新进的元素)
//思路2：双队列(push O(N), pop O(1))(push：新进元素从q2入队列，当q1非空，q1出队列到q2中，保证新进元素在q2的队首，q1,q2交换)
//思路3：（思路清晰，推荐）一个队列的实现，只需要在插入时重新调整元素顺序即可(将之前的元素出队列，重进进队列，使得新进元素在队首)
*/
class MyStack {
public:
	/** Initialize your data structure here. */
	//问题核心怎么让新进队列的元素出现在队首
	//思路1：双队列，q1保存push（O(1)）的元素，然后进行pop()操作时，将队尾元素之外的元素，pop()到q2中，此时最后一个元素为栈顶元素，该元素直接出队列；然后q1,q2交换，queue<int> temp;  temp = q2; q1 = q2; q2 = temp;
	//push:O(1)
	//pop:O(N),N次出队列q1,N-1次入队列q2，
	queue<int> q1;
	queue<int> q2;
	int Top;  //保存栈顶元素
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		q1.push(x);
		Top = x;
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		while (q1.size() > 1) {
			//注意top值的更新
			Top = q1.front();
			q1.pop();
			q2.push(Top);
		}
		int res = q1.front();
		q1.pop();
		queue<int> temp;
		temp = q1;
		q1 = q2;
		q2 = temp;
		return res;
	}

	/** Get the top element. */
	int top() {
		return Top;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

class MyStack {
public:
	/** Initialize your data structure here. */
	//问题核心怎么让新进队列的元素出现在队首
	//思路2：双队列(push O(N), pop O(1))(push：新进元素从q2入队列，当q1非空，q1出队列到q2中，保证新进元素在q2的队首，q1,q2交换)
	queue<int> q1;
	queue<int> q2;
	int Top;  //保存栈顶元素
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		q2.push(x);
		Top = x;
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}
		queue<int> temp;
		temp = q1;
		q1 = q2;
		q2 = temp;
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int res = q1.front();
		q1.pop();
		Top = q1.front();
		return res;
	}

	/** Get the top element. */
	int top() {
		return Top;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

class MyStack {
public:
	/** Initialize your data structure here. */
	//问题核心怎么让新进队列的元素出现在队首
	//思路3：一个队列的实现，只需要在插入时重新调整元素顺序即可(将之前的元素出队列，重进进队列，使得新进元素在队首)
	queue<int> q;
	int Top;  //保存栈顶元素
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		int lenght = q.size();
		q.push(x);
		Top = x;
		for (int i = 0; i < lenght; ++i) {
			q.push(q.front());
			q.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int res = q.front();
		q.pop();
		Top = q.front();
		return res;
	}

	/** Get the top element. */
	int top() {
		return Top;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
};

