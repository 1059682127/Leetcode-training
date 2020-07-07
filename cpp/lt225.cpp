//lt225

/*
��ջʵ�ֶ���

ʹ��ջʵ�ֶ��е����в�����
push(x) -- ��һ��Ԫ�ط�����е�β����
pop() -- �Ӷ����ײ��Ƴ�Ԫ�ء�
peek() -- ���ض����ײ���Ԫ�ء�
empty() -- ���ض����Ƿ�Ϊ�ա�
ʾ��:
MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // ���� 1
queue.pop();   // ���� 1
queue.empty(); // ���� false
˵��:
��ֻ��ʹ�ñ�׼��ջ���� -- Ҳ����ֻ�� push to top, peek/pop from top, size, �� is empty �����ǺϷ��ġ�
����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
�������в���������Ч�� �����磬һ���յĶ��в������ pop ���� peek ��������

//˼·1��˫����(push O(1), pop O(N))(�½�Ԫ�ش�q1����У���ջʱ��q1������ֱ��ֻ���½���Ԫ��)
//˼·2��˫����(push O(N), pop O(1))(push���½�Ԫ�ش�q2����У���q1�ǿգ�q1�����е�q2�У���֤�½�Ԫ����q2�Ķ��ף�q1,q2����)
//˼·3����˼·�������Ƽ���һ�����е�ʵ�֣�ֻ��Ҫ�ڲ���ʱ���µ���Ԫ��˳�򼴿�(��֮ǰ��Ԫ�س����У��ؽ������У�ʹ���½�Ԫ���ڶ���)
*/
class MyStack {
public:
	/** Initialize your data structure here. */
	//���������ô���½����е�Ԫ�س����ڶ���
	//˼·1��˫���У�q1����push��O(1)����Ԫ�أ�Ȼ�����pop()����ʱ������βԪ��֮���Ԫ�أ�pop()��q2�У���ʱ���һ��Ԫ��Ϊջ��Ԫ�أ���Ԫ��ֱ�ӳ����У�Ȼ��q1,q2������queue<int> temp;  temp = q2; q1 = q2; q2 = temp;
	//push:O(1)
	//pop:O(N),N�γ�����q1,N-1�������q2��
	queue<int> q1;
	queue<int> q2;
	int Top;  //����ջ��Ԫ��
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
			//ע��topֵ�ĸ���
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
	//���������ô���½����е�Ԫ�س����ڶ���
	//˼·2��˫����(push O(N), pop O(1))(push���½�Ԫ�ش�q2����У���q1�ǿգ�q1�����е�q2�У���֤�½�Ԫ����q2�Ķ��ף�q1,q2����)
	queue<int> q1;
	queue<int> q2;
	int Top;  //����ջ��Ԫ��
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
	//���������ô���½����е�Ԫ�س����ڶ���
	//˼·3��һ�����е�ʵ�֣�ֻ��Ҫ�ڲ���ʱ���µ���Ԫ��˳�򼴿�(��֮ǰ��Ԫ�س����У��ؽ������У�ʹ���½�Ԫ���ڶ���)
	queue<int> q;
	int Top;  //����ջ��Ԫ��
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

