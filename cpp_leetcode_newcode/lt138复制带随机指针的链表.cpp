//lt138

/*
���ƴ����ָ�������

����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
Ҫ�󷵻��������� �����
������һ���� n ���ڵ���ɵ���������ʾ����/����е�����ÿ���ڵ���һ�� [val, random_index] ��ʾ��
val��һ����ʾ Node.val ��������
random_index�����ָ��ָ��Ľڵ���������Χ�� 0 �� n-1���������ָ���κνڵ㣬��Ϊ  null ��

˼·1������+��ϣ��O(N)/O(N)
//ʱ�临�Ӷȣ�O(N),��Ҫ����N���ڵ�
//�ռ临�Ӷȣ�O(N)����Ҫ��¼���ʹ��Ľڵ��Լ����ݵ�ջ
˼·2������+��ϣ�� O(N)/O(N)
˼·3(�Ƽ���˼·������)������+��ϣ�����α�����һ�α����ȿ��������Ľڵ㲢�����ڹ�ϣ���У����α�����ʱ�������ӹ�ϵ��
˼·4��ԭ�ظ���O(N)/0(1)
*/


/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
*/
class Solution {
public:
	//˼·1������+��ϣ��
	//��next\random���л���
	//Trick1:Ϊ�˱���randomָ���γ���ѭ������ϣ���¼�Ѿ����ʹ��Ľڵ㣨��ϣ���¼�ڵ㼰�俽�������
	//�������ڵ��Ѿ����˿������Ͳ���Ҫ���п���
	//�������ڵ�head��û�������ʹ���һ���½ڵ�node(head->val)�����䱣���ϣ��visitedHash�У����ֱ���next,randomָ����л���

	//֪ʶ�㣺���ɶ���ָ��
	//����1����ջ�Ϸ����ڴ棺Node node(head->val); Node* np = &node;(�᷵�ش���)
	//����2���ڶ��ϴ�������Node* node = new Node(head->val);

	//��ϣ���¼�ڵ㼰�俽�����
	map<Node*, Node*> visitedHash;
	Node* copyRandomList(Node* head) {
		if (head == NULL) return NULL;
		//����Ѿ����ڣ��ӹ�ϣ����ȡ��
		if (visitedHash.count(head)) return visitedHash[head];
		//Node nodetemp(head->val);
		//Node* node = &nodetemp;
		//�������򴴽�
		Node* node = new Node(head->val);
		//��ӵ�visitedHash��
		visitedHash[head] = node;
		//���л���
		node->next = copyRandomList(head->next);
		node->random = copyRandomList(head->random);
		return node;
	}

};


/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
*/

//ִ����ʱ:20 ms, ������ C++ �ύ�л�����45.11%���û�
//�ڴ����� :13.5 MB, ������ C++ �ύ�л�����80.98%���û�
class Solution {
public:
	//˼·2������+��ϣ�� O(N)/O(N)
	//��next���б���oldNodeֱ����β
	//Trick1:
	//�������ڵ�oldNodeָ��Ľڵ��Ѿ����˿������Ͳ���Ҫ���п���
	//�������ڵ�oldNodeָ��Ľڵ㻹û�������ʹ���һ���½ڵ�node(head->val)�����䱣���ϣ��visitedHash��

	//֪ʶ�㣺���ɶ���ָ��
	//����1����ջ�Ϸ����ڴ棺Node node(head->val); Node* np = &node;(�᷵�ش���)
	//����2���ڶ��ϴ�������Node* node = new Node(head->val);
	map<Node*, Node*> visitedHash;
	Node* copyRandomList(Node* head) {
		if (head == NULL) return NULL;
		Node* oldNode = head;
		Node* newHead = new Node(oldNode->val);
		Node* newNode = newHead;
		visitedHash[oldNode] = newNode;
		while (oldNode != NULL) {
			//�����ڵ����
			newNode->next = getCloneNode(oldNode->next);
			newNode->random = getCloneNode(oldNode->random);
			//�����ƶ�
			oldNode = oldNode->next;
			newNode = newNode->next;
		}
		return newHead;
	}
	Node* getCloneNode(Node* node) {
		if (node == NULL) return NULL;
		if (visitedHash.count(node)) return visitedHash[node];
		else {
			//û�м�¼���򴴽�һ���µĽڵ㣬����¼
			Node* newNode = new Node(node->val);
			visitedHash[node] = newNode;
			return newNode;
		}
	}

};


//ִ����ʱ:12 ms, ������ C++ �ύ�л�����84.13%���û�
//�ڴ����� :13.6 MB, ������ C++ �ύ�л�����73.14%���û�
class Solution {
public:
	//˼·3������+��ϣ�����α�����һ�α����ȿ��������Ľڵ㲢�����ڹ�ϣ���У����α�����ʱ�������ӹ�ϵ��
	//Trick1:
	map<Node*, Node*> visitedHash;
	Node* copyRandomList(Node* head) {
		if (head == NULL) return NULL;
		Node* cur = head;
		//1�α�������¼�ڵ���Ϣ
		while (cur != NULL) {
			Node* node = new Node(cur->val);
			visitedHash[cur] = node;
			cur = cur->next;
		}
		cur = head;
		//2�α���������ϣ���еĽڵ㽨�����ӹ�ϵ
		while (cur != NULL) {
			visitedHash[cur]->next = visitedHash[cur->next];
			visitedHash[cur]->random = visitedHash[cur->random];
			cur = cur->next;
		}
		//����head
		return visitedHash[head];
	}
};


//ִ����ʱ:12 ms, ������ C++ �ύ�л�����84.13%���û�
//�ڴ����� :13.5 MB, ������ C++ �ύ�л�����82.40%���û�
class Solution {
public:
	//˼·4��ԭ�ظ���O(N)/0(1)
	//Trick1:
	//���ƽڵ㣬ͬʱ�����ƽڵ����ӵ�ԭ�ڵ���棬��A->B->C ��Ϊ A->A'->B->B'->C->C'��
	//���ýڵ�randomֵ��
	//�����������ԭ������롣
	Node* copyRandomList(Node* head) {
		if (head == NULL) return NULL;
		Node* node = head;
		//���ƽڵ�
		while (node != NULL) {
			Node* copy = new Node(node->val);
			copy->next = node->next;
			node->next = copy;
			node = copy->next;
		}
		//���ýڵ�randomֵ
		node = head;
		while (node != NULL) {
			if (node->random != NULL) {
				node->next->random = node->random->next;
			}
			node = node->next->next;
		}
		//�����������ԭ�������
		node = head;
		Node *newHead = head->next;
		Node *newNode = newHead;
		while (node != nullptr) {
			node->next = node->next->next;
			if (newNode->next != nullptr) {
				newNode->next = newNode->next->next;
			}
			node = node->next;
			newNode = newNode->next;
		}

		return newHead;
	}
};