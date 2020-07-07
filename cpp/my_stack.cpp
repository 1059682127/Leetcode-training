// Leetcode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

//用链表实现栈
struct StackNode
{
	int val;
	StackNode* next;
	StackNode(int x) :val(x), next(NULL) {}
};
class my_stack {
private:	
	StackNode* top;
	int size;
	StackNode* buttom;
public:
	my_stack():size(0), top(NULL), buttom(NULL) {}
	//清空栈
	void stackClear() {
		while (top) {
			top = top->next;
		}
		size = 0;
	}
	//返回栈大小
	int stackSize() {
		return size;
	}
	//元素入栈,先头插后重定位top指针
	bool stackPush(int x) {
		//头插法
		StackNode* node = new StackNode(x);
		node->next = top;
		top = node;
		++size;
		return true;
	}
	//元素出栈,top指针下移即可
	bool stackPop() {
		if (top != NULL) {
			top = top->next;
			--size;
			return true;
		}
		else {
			cout << "栈已空" << endl;
			return false;
		}
	}
};
int main() {
	my_stack stack;
	stack.stackPop();
	stack.stackPush(2);
	stack.stackPush(3);
	stack.stackPop();
	stack.stackClear();
	return 0;
}