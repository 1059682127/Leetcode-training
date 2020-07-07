//lt707

/*
��������ʵ�֡�������ѡ��ʹ�õ������˫�����������еĽڵ�Ӧ�þ����������ԣ�val �� next��val �ǵ�ǰ�ڵ��ֵ��next ��ָ����һ���ڵ��ָ��/���á����Ҫʹ��˫����������Ҫһ������ prev ��ָʾ�����е���һ���ڵ㡣���������е����нڵ㶼�� 0-index �ġ�

����������ʵ����Щ���ܣ�


	get(index)����ȡ�����е� index ���ڵ��ֵ�����������Ч���򷵻�-1��
	addAtHead(val)��������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ val �Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ㡣
	addAtTail(val)����ֵΪ val �Ľڵ�׷�ӵ���������һ��Ԫ�ء�
	addAtIndex(index,val)���������еĵ� index ���ڵ�֮ǰ���ֵΪ val  �Ľڵ㡣��� index ��������ĳ��ȣ���ýڵ㽫���ӵ������ĩβ����� index ���������ȣ��򲻻����ڵ㡣���indexС��0������ͷ������ڵ㡣
	deleteAtIndex(index)��������� index ��Ч����ɾ�������еĵ� index ���ڵ㡣


*/


//ִ����ʱ:40 ms, ������ C++ �ύ�л�����98.40%���û�
//�ڴ����� :19.3 MB, ������ C++ �ύ�л�����21.27%���û�
class MyLinkedList {
private:
	//������汾
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


//˫�������
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
		if (head) {
			newHead->next = head;
			head->prev = newHead;
			head = newHead;   //�ض�λhead

		}
		else {
			//���ͷβ��㶼������
			head = tail = newHead;

		}
		++size; //�ۼ�����
	}
	//������ĩβ���Ԫ��
	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		//����Ϊ�գ�ֱ�ӽ��½ڵ���Ϊͷ���
		ListNode* p = new ListNode(val);
		if (tail) {
			tail->next = p;
			p->prev = tail;
			tail = p;   //�ض�λtail
		}
		else {
			tail = head = p;
		}
		++size;
	}

	//�������е�index�����֮ǰ���ֵΪval�Ľ��
	void addAtIndex(int index, int val) {
		ListNode* p = new ListNode(val);
		if (index <= 0) {
			addAtHead(val);  //index <= 0, ��ͷ������
			return;
		}
		if (index == size) {
			addAtTail(val);
			return;
		}
		if (index > size) return;
		//Ѱ�ҵ�index�����cur����¼ǰ��һ�����before��before->next = p...
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

	//ɾ����index�����
	void deleteAtIndex(int index) {
		//����������ڷ�Χ�ڣ���������
		if (index < 0 || index > size - 1) return;
		//���ɾ��ͷ���
		if (index == 0) {
			head = head->next;  //�ض�λhead
			if (head) {
				head->prev = NULL;
			}
			else {
				tail = NULL; //�ض�λtail
			}
			--size;
			return;
		}
		//ɾ��β���
		if (index == size - 1) {
			tail = tail->prev; //�ض�λβ���
			//���õ���㣬ǰ��index = 0�Ѿ����ǹ���
			tail->next = NULL;
			--size;
			return;
		}
		//ɾ���м���,���ҵ�����Ϊindex�Ľ��
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
	//����������
	int length() {
		return size;
	}
};