/*
��Ŀ����
������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
*/

class Solution
{
	//����У��浽stack1�������У���stack2ջ��������û�еĻ���stack1ת��Ԫ�ص�stack2
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