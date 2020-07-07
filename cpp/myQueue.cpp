//myQueue.cpp


#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

//用动态数组实现队列
class myQueue {
private:
	vector<int> data;
	int p_start;
public:
	myQueue() :p_start(0) {}
	//插入元素
	bool enQueue(int val) {
		data.push_back(val);
		return true;
	}
	//删除元素
	bool deQueue() {
		if (isEmpty()) return false;
		else {
			++p_start;
			return true;
		}
	}
	//获得队首元素
	int Front() {
		return data[p_start];
	}
	//判断是否为空队列
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