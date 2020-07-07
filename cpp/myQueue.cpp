//myQueue.cpp


#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

//�ö�̬����ʵ�ֶ���
class myQueue {
private:
	vector<int> data;
	int p_start;
public:
	myQueue() :p_start(0) {}
	//����Ԫ��
	bool enQueue(int val) {
		data.push_back(val);
		return true;
	}
	//ɾ��Ԫ��
	bool deQueue() {
		if (isEmpty()) return false;
		else {
			++p_start;
			return true;
		}
	}
	//��ö���Ԫ��
	int Front() {
		return data[p_start];
	}
	//�ж��Ƿ�Ϊ�ն���
	bool isEmpty() {
		return p_start == data.size();
	}

};

int main() {
	myQueue q;
	q.enQueue(5);
	q.enQueue(3);
	if (!q.isEmpty()) {
		cout << q.Front() << endl;
	}
	q.deQueue();
	if (!q.isEmpty()) {
		cout << q.Front() << endl;
	}
	q.deQueue();
	if (!q.isEmpty()) {
		cout << q.Front() << endl;
	}
}