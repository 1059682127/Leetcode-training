// Leetcode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

//用动态数组实现队列
//区别空队列的办法，删除元素的时候，如果front = -1 时，为空队列;（front == rear说明只有一个元素,删除之后要重置front,rear = -1）
//添加元素的时候，如果(rear+1)%maxSize = front, 则为满队列

//front(),rear()的时候记得判断队列是否为空
class MyCircularQueue {
private:
	vector<int> data;
	int front;   //指向头元素
	int rear;  //指向尾元素
	int maxSize;
public:
	//初始化大小为k的数组
	MyCircularQueue(int k) :front(-1), rear(-1), maxSize(k) { data.resize(k); }
	//如果队列不满，插入元素
	bool enQueue(int val) {
		if (isFull()) return false;
		if (isEmpty()) front = 0;
		rear = (++rear) % maxSize;  //若rear到最后，则转至数组头部
		data[rear] = val;
		return true;
	}
	//如果数组不空，删除元素
	bool deQueue() {
		if (isEmpty()) return false;
		//如果只要一个元素
		if (front == rear) {
			front = -1;
			rear = -1;
			return true;
		}
		else {
			front = (++front) % maxSize;
			return true;
		}
	}
	int QueueLength() {
		return (rear - front + maxSize) % maxSize;
	}
	//获得队首元素
	int Front() {
		if (isEmpty()) return -1;
		else return data[front];

	}
	//获得队尾元素
	int Rear() {
		if (isEmpty()) return -1;
		else return data[rear];
	}

	//判断是否为空队列
	bool isEmpty() {
		return front == -1;
	}
	//判断是否为满队列
	bool isFull() {
		return (rear + 1) % maxSize == front;
	}

};

int main() {
	MyCircularQueue circularQueue = MyCircularQueue(3); // 设置长度为 3

	circularQueue.enQueue(1);  // 返回 true

	circularQueue.enQueue(2);  // 返回 true

	circularQueue.enQueue(3);  // 返回 true

	circularQueue.enQueue(4);  // 返回 false，队列已满

	circularQueue.Rear();  // 返回 3

	circularQueue.isFull();  // 返回 true

	circularQueue.deQueue();  // 返回 true

	circularQueue.enQueue(4);  // 返回 true

	circularQueue.Rear();  // 返回 4

	return 0;
}