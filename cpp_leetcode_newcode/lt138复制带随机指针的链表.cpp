//lt138

/*
复制带随机指针的链表

给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
要求返回这个链表的 深拷贝。
我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。

思路1：回溯+哈希表O(N)/O(N)
//时间复杂度：O(N),需要访问N个节点
//空间复杂度：O(N)，需要记录访问过的节点以及回溯的栈
思路2：遍历+哈希表 O(N)/O(N)
思路3(推荐，思路清晰简单)：遍历+哈希表（两次遍历，一次遍历先拷贝单独的节点并保存在哈希表中，二次遍历的时候建立连接关系）
思路4：原地复制O(N)/0(1)
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
	//思路1：回溯+哈希表
	//按next\random进行回溯
	//Trick1:为了避免random指针形成死循环，哈希表记录已经访问过的节点（哈希表记录节点及其拷贝结果）
	//当遇到节点已经有了拷贝，就不需要进行拷贝
	//当遇到节点head还没拷贝，就创造一个新节点node(head->val)，将其保存哈希表visitedHash中，并分别按照next,random指针进行回溯

	//知识点：生成对象指针
	//方法1：在栈上分配内存：Node node(head->val); Node* np = &node;(会返回错误)
	//方法2：在堆上创建对象，Node* node = new Node(head->val);

	//哈希表记录节点及其拷贝结果
	map<Node*, Node*> visitedHash;
	Node* copyRandomList(Node* head) {
		if (head == NULL) return NULL;
		//如果已经存在，从哈希表中取出
		if (visitedHash.count(head)) return visitedHash[head];
		//Node nodetemp(head->val);
		//Node* node = &nodetemp;
		//不存在则创建
		Node* node = new Node(head->val);
		//添加到visitedHash中
		visitedHash[head] = node;
		//进行回溯
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

//执行用时:20 ms, 在所有 C++ 提交中击败了45.11%的用户
//内存消耗 :13.5 MB, 在所有 C++ 提交中击败了80.98%的用户
class Solution {
public:
	//思路2：遍历+哈希表 O(N)/O(N)
	//按next进行遍历oldNode直到链尾
	//Trick1:
	//当遇到节点oldNode指向的节点已经有了拷贝，就不需要进行拷贝
	//当遇到节点oldNode指向的节点还没拷贝，就创造一个新节点node(head->val)，将其保存哈希表visitedHash中

	//知识点：生成对象指针
	//方法1：在栈上分配内存：Node node(head->val); Node* np = &node;(会返回错误)
	//方法2：在堆上创建对象，Node* node = new Node(head->val);
	map<Node*, Node*> visitedHash;
	Node* copyRandomList(Node* head) {
		if (head == NULL) return NULL;
		Node* oldNode = head;
		Node* newHead = new Node(oldNode->val);
		Node* newNode = newHead;
		visitedHash[oldNode] = newNode;
		while (oldNode != NULL) {
			//拷贝节点操作
			newNode->next = getCloneNode(oldNode->next);
			newNode->random = getCloneNode(oldNode->random);
			//继续移动
			oldNode = oldNode->next;
			newNode = newNode->next;
		}
		return newHead;
	}
	Node* getCloneNode(Node* node) {
		if (node == NULL) return NULL;
		if (visitedHash.count(node)) return visitedHash[node];
		else {
			//没有记录，则创建一个新的节点，并记录
			Node* newNode = new Node(node->val);
			visitedHash[node] = newNode;
			return newNode;
		}
	}

};


//执行用时:12 ms, 在所有 C++ 提交中击败了84.13%的用户
//内存消耗 :13.6 MB, 在所有 C++ 提交中击败了73.14%的用户
class Solution {
public:
	//思路3：遍历+哈希表（两次遍历，一次遍历先拷贝单独的节点并保存在哈希表中，二次遍历的时候建立连接关系）
	//Trick1:
	map<Node*, Node*> visitedHash;
	Node* copyRandomList(Node* head) {
		if (head == NULL) return NULL;
		Node* cur = head;
		//1次遍历，记录节点信息
		while (cur != NULL) {
			Node* node = new Node(cur->val);
			visitedHash[cur] = node;
			cur = cur->next;
		}
		cur = head;
		//2次遍历，将哈希表中的节点建立连接关系
		while (cur != NULL) {
			visitedHash[cur]->next = visitedHash[cur->next];
			visitedHash[cur]->random = visitedHash[cur->random];
			cur = cur->next;
		}
		//返回head
		return visitedHash[head];
	}
};


//执行用时:12 ms, 在所有 C++ 提交中击败了84.13%的用户
//内存消耗 :13.5 MB, 在所有 C++ 提交中击败了82.40%的用户
class Solution {
public:
	//思路4：原地复制O(N)/0(1)
	//Trick1:
	//复制节点，同时将复制节点链接到原节点后面，如A->B->C 变为 A->A'->B->B'->C->C'。
	//设置节点random值。
	//将复制链表从原链表分离。
	Node* copyRandomList(Node* head) {
		if (head == NULL) return NULL;
		Node* node = head;
		//复制节点
		while (node != NULL) {
			Node* copy = new Node(node->val);
			copy->next = node->next;
			node->next = copy;
			node = copy->next;
		}
		//设置节点random值
		node = head;
		while (node != NULL) {
			if (node->random != NULL) {
				node->next->random = node->random->next;
			}
			node = node->next->next;
		}
		//将复制链表从原链表分离
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