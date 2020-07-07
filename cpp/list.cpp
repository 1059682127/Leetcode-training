// Leetcode.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
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

	//��ȡ�����е�index������ֵ
	int get(int index) {
		ListNode* cur = head;
		int i = 0;
		while (cur && i < index) {
			cur = cur->next;
			++i;
		}
		//����ĩβ
		if (cur) return cur->val;
		else return -1;
	}

	//��ͷ���ǰ���������
	void addAtHead(int val) {
		ListNode* newHead = new ListNode(val);
		newHead->next = head;
		head = newHead;   //ָ���һ�����
	}
	//������ĩβ���Ԫ��
	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		//����Ϊ�գ�ֱ�ӽ��½ڵ���Ϊͷ���
		ListNode* p = new ListNode(val);
		if (!head) {
			head = p;
			return;
		}
		//����Ϊ�գ�����β����ӣ��ҵ�β���
		ListNode* cur = head;
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = p;
	}

	//�������е�index�����֮ǰ���ֵΪval�Ľ��
	void addAtIndex(int index, int val) {
		ListNode* p = new ListNode(val);
		if (index <= 0) {
			addAtHead(val);  //index <= 0, ��ͷ������
			return;
		}
		ListNode* cur = head;
		int i = 0;
		//��õ�index - 1�����
		while (cur && i < index - 1) {
			cur = cur->next;
			++i;
		}
		//һ����cur == NULL��˵������β��㣬�����
		//��һ����cur != NULL,��ӽ��(����)
		if (cur) {
			p->next = cur->next;
			cur->next = p;
		}

	}

	//ɾ����index�����
	void deleteAtIndex(int index) {
		if (head == NULL || index < 0) return;
		if (index == 0) {
			head = head->next;
			return;
		}
		ListNode* cur = head;
		int i = 0;
		//�ҵ���index - 1��Ԫ��
		while (cur && i < index - 1) {
			cur = cur->next;
			++i; //��ǰ��++����
		}
		if (cur) {
			//���index - 1�����һ�����
			if (!cur->next) return;
			else {
				cur->next = cur->next->next;
			}
		}
	}
	//����������
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