/*
��Ŀ����
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
*/

class Solution {
public:
	//˼·3����ջ����һ������min����ջ�ڼ�Сֵ�������¼�Сֵʱ����push_back֮ǰ��min
	//��ջ������x <= minʱ����push(min),��push(x),�ٸ���min = x
	//��ջ����data.top() == minʱ����data.pop(),��min = data.top(),���data.pop()
	//��Сֵ:min
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