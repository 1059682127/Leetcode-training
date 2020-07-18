// Leetcode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
class MyLinkedList {
private:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) :val(x), next(NULL) {}
	};
	ListNode* head;
public:
	MyLinkedList() :head(NULL) {
	}

	//获取链表中第index个结点的值
	int get(int index) {
		ListNode* cur = head;
		int i = 0;
		while (cur && i < index) {
			cur = cur->next;
			++i;
		}
		//不是末尾
		if (cur) return cur->val;
		else return -1;
	}

	//在头结点前面新增结点
	void addAtHead(int val) {
		ListNode* newHead = new ListNode(val);
		newHead->next = head;
		head = newHead;   //指向第一个结点
	}
	//在链表末尾添加元素
	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		//链表为空，直接将新节点作为头结点
		ListNode* p = new ListNode(val);
		if (!head) {
			head = p;
			return;
		}
		//链表不为空，则在尾部添加，找到尾结点
		ListNode* cur = head;
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = p;
	}

	//在链表中第index个结点之前添加值为val的结点
	void addAtIndex(int index, int val) {
		ListNode* p = new ListNode(val);
		if (index <= 0) {
			addAtHead(val);  //index <= 0, 在头部插入
			return;
		}
		ListNode* cur = head;
		int i = 0;
		//获得第index - 1个结点
		while (cur && i < index - 1) {
			cur = cur->next;
			++i;
		}
		//一种是cur == NULL，说明超出尾结点，不添加
		//另一种是cur != NULL,添加结点(包括)
		if (cur) {
			p->next = cur->next;
			cur->next = p;
		}

	}

	//删除第index个结点
	void deleteAtIndex(int index) {
		if (head == NULL || index < 0) return;
		if (index == 0) {
			head = head->next;
			return;
		}
		ListNode* cur = head;
		int i = 0;
		//找到第index - 1个元素
		while (cur && i < index - 1) {
			cur = cur->next;
			++i; //用前置++更好
		}
		if (cur) {
			//如果index - 1是最后一个结点
			if (!cur->next) return;
			else {
				cur->next = cur->next->next;
			}
		}
	}
	//计算链表长度
	int length() {
		int i = 0;
		ListNode* cur = head;
		while (cur) {
			++i;
			cur = cur->next;
		}
		return i;
	}
};


int main()
{
	MyLinkedList mlf;
	mlf.addAtHead(1);
	mlf.addAtTail(3);
	mlf.addAtIndex(1, 2);
	cout << mlf.get(1) << endl;
	mlf.deleteAtIndex(1);
	cout << mlf.get(1) << endl;
	system("pause");
}