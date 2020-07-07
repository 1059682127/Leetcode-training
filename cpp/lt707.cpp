//lt707

/*
设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

在链表类中实现这些功能：


	get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
	addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
	addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
	addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
	deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。


*/


//执行用时:40 ms, 在所有 C++ 提交中击败了98.40%的用户
//内存消耗 :19.3 MB, 在所有 C++ 提交中击败了21.27%的用户
class MyLinkedList {
private:
	//单链表版本
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


//双向链表版
class MyLinkedList {
private:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode* prev;
		ListNode(int x) :val(x), prev(NULL), next(NULL) {}
	};
	ListNode* head;
	ListNode* tail;
	int size;
public:
	MyLinkedList() :size(0), head(NULL), tail(NULL) {
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
		if (head) {
			newHead->next = head;
			head->prev = newHead;
			head = newHead;   //重定位head

		}
		else {
			//如果头尾结点都不存在
			head = tail = newHead;

		}
		++size; //累计数量
	}
	//在链表末尾添加元素
	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		//链表不为空，直接将新节点作为头结点
		ListNode* p = new ListNode(val);
		if (tail) {
			tail->next = p;
			p->prev = tail;
			tail = p;   //重定位tail
		}
		else {
			tail = head = p;
		}
		++size;
	}

	//在链表中第index个结点之前添加值为val的结点
	void addAtIndex(int index, int val) {
		ListNode* p = new ListNode(val);
		if (index <= 0) {
			addAtHead(val);  //index <= 0, 在头部插入
			return;
		}
		if (index == size) {
			addAtTail(val);
			return;
		}
		if (index > size) return;
		//寻找第index个结点cur，记录前面一个结点before，before->next = p...
		ListNode* cur = head;
		ListNode* b = NULL;
		int i = 0;
		while (cur && i < index) {
			b = cur;
			cur = cur->next;
			++i;
		}
		if (cur) {
			b->next = p;
			p->prev = b;
			p->next = cur;
			cur->prev = p;
			++size;
		}
	}

	//删除第index个结点
	void deleteAtIndex(int index) {
		//如果索引不在范围内，不作处理
		if (index < 0 || index > size - 1) return;
		//如果删除头结点
		if (index == 0) {
			head = head->next;  //重定位head
			if (head) {
				head->prev = NULL;
			}
			else {
				tail = NULL; //重定位tail
			}
			--size;
			return;
		}
		//删除尾结点
		if (index == size - 1) {
			tail = tail->prev; //重定位尾结点
			//不用单结点，前面index = 0已经考虑过了
			tail->next = NULL;
			--size;
			return;
		}
		//删除中间结点,先找到索引为index的结点
		ListNode* b = NULL, *cur = head;
		int i = 0;
		while (cur && i < index) {
			b = cur;
			cur = cur->next;
			++i;
		}
		b->next = cur->next;
		cur->next->prev = b;
		--size;
	}
	//计算链表长度
	int length() {
		return size;
	}
};