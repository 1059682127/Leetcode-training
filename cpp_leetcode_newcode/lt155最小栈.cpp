//lt155

/*
��Сջ

���һ��֧�� push��pop��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
push(x) -- ��Ԫ�� x ����ջ�С�
pop() -- ɾ��ջ����Ԫ�ء�
top() -- ��ȡջ��Ԫ�ء�
getMin() -- ����ջ�е���СԪ�ء�
ʾ��:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> ���� -3.
minStack.pop();
minStack.top();      --> ���� 0.
minStack.getMin();   --> ���� -2.

//˼·1��˫ջͬ��������������ͬ�����ÿ��Ǳ߽����⣬�����š�����Ҫ��Ԫ�أ�O(1)/O(N)
//˼·2��˫ջ��ͬ����������СԪ�أ�Ҫ���Ǳ߽����⣩O(1)/O(N)
//˼·3����ջ����һ������min����ջ�ڼ�СֵO(1)/O(N)
*/


//ִ����ʱ:28 ms, ������ C++ �ύ�л�����92.09%���û�
//�ڴ����� :16.9 MB, ������ C++ �ύ�л�����41.98%���û�
class MinStack {
public:
	/** initialize your data structure here. */
	//˼·��1��˫ջͬ��������������ͬ�����ÿ��Ǳ߽����⣬�����š�����Ҫ��Ԫ�أ�
	//Trick1:��ջʱ����x <= helper.top()ʱ��helper.push_back(x);��x > helper.top()ʱ��helper.push_back(helper.top())
	//Trick2:��ջʱ��˫ջpush_back
	//Trick3:��Сֵ��Ϊhelper.top();

	//֪ʶ�㣺stack��ջ����:stack.push(x)!!!

	stack<int> data;
	stack<int> helper; //�����Сֵ
	MinStack() {

	}

	void push(int x) {
		data.push(x);
		//��x <= helper.top()ʱ��helper.push_back(x);
		if (helper.empty() || x <= helper.top()) helper.push(x);
		//��x > helper.top()ʱ��helper.push_back(helper.top())
		else helper.push(helper.top());
	}

	void pop() {
		// ͬʱ��ջ��˫ջͬ����
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



//ִ����ʱ:12 ms, ������ C++ �ύ�л�����100.00%���û�
//�ڴ����� :17 MB, ������ C++ �ύ�л�����15.59%���û�
class MinStack {
public:
	/** initialize your data structure here. */
	//˼·��2��˫ջ��ͬ����������СԪ�أ�Ҫ���Ǳ߽����⣩
	//Trick1:��ջʱ����x <= helper.top()ʱ��helper.push(x);��Ҫ����=��������ͬ��������Сֵ��
	//Trick2:��ջʱ��helper.top() = data.top()ʱ��helper.pop()
	//Trick3:��Сֵ��Ϊhelper.top();

	//֪ʶ�㣺stack��ջ����:stack.push(x)!!!

	stack<int> data;
	stack<int> helper;
	MinStack() {

	}

	void push(int x) {
		data.push(x);
		//��x <= helper.top()ʱ��helper.push(x);��Ҫ����=��������ͬ��������Сֵ��
		if (helper.empty() || x <= helper.top()) helper.push(x);
	}

	void pop() {
		//ע���Ⱥ�˳��
		//helper.top() = data.top()ʱ��helper.pop()
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

//ִ����ʱ:28 ms, ������ C++ �ύ�л�����92.09%���û�
//�ڴ����� :16.9 MB, ������ C++ �ύ�л�����55.88%���û�
class MinStack {
public:
	/** initialize your data structure here. */
	//˼·3����ջ����һ������min����ջ�ڼ�Сֵ
	//��ջ������x <= minʱ����push(min),��push(x),�ٸ���min = x
	//��ջ����data.top() == minʱ����data.pop(),��min = data.top(),���data.pop()
	//��Сֵ:min

	stack<int> data;
	int min = INT_MAX;
	MinStack() {

	}

	void push(int x) {
		//��x <= minʱ����push(min),��push(x),�ٸ���min = x
		if (x <= min) {   //Ҫ����=��
			data.push(min);
			min = x;
		}
		data.push(x);

	}

	void pop() {
		//ע���Ⱥ�˳��
		//��data.top() == minʱ����data.pop(),��min = data.top(),���data.pop()
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