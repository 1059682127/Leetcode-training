//lt133
/*

��¡ͼ

�������� ��ͨ ͼ��һ���ڵ�����ã����㷵�ظ�ͼ�� �������¡����

ͼ�е�ÿ���ڵ㶼��������ֵ val��int�� �����ھӵ��б�list[Node]����

class Node {
	public int val;
	public List<Node> neighbors;
}



����������ʽ��

�������ÿ���ڵ��ֵ��������������ͬ�����磬��һ���ڵ�ֵΪ 1���ڶ����ڵ�ֵΪ 2���Դ����ơ���ͼ�ڲ���������ʹ���ڽ��б��ʾ��

�ڽ��б������ڱ�ʾ����ͼ�������б�ļ��ϡ�ÿ���б�������ͼ�нڵ���ھӼ���

�����ڵ㽫ʼ����ͼ�еĵ�һ���ڵ㣨ֵΪ 1��������뽫 �����ڵ�Ŀ��� ��Ϊ�Կ�¡ͼ�����÷��ء�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/clone-graph
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

//˼·1��������ȱ���
//˼·2��������ȱ���
*/
/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};
*/
class Solution {
public:
	//˼·1��������ȱ�����hash_table��¼�Ѿ����ʹ��Ľڵ㼰�ýڵ��¡�����
	//���node==NULL,����
	//����Ѿ��Ѿ����ʹ������ؿ�¡��������򣬴����½ڵ㣬������ھ�
	//0����1����2����3 DFS(0)�����ڵ�,val, nerghbor.push_back(DFS(1));
	Node* cloneGraph(Node* node) {
		map<Node*, Node*> hash_table;
		return helper(node, hash_table);
	}
	Node* helper(Node* node, map<Node*, Node*>& hash_table) {
		if (node == NULL) return NULL;
		if (hash_table.count(node)) return hash_table[node];
		//�����½ڵ�
		Node* copyNode = new Node(node->val);
		hash_table[node] = copyNode;
		for (auto& neighbor : node->neighbors) copyNode->neighbors.push_back(helper(neighbor, hash_table));
		return copyNode;
	}
};

class Solution {
public:
	//˼·2��������ȱ���
	//Trick1:hash_table��¼<Node*, ���ƵĽڵ�>

	//�ж��ھ��Ƿ�δ���ʹ����ǵĻ�����У�����ӵ�neighbors�У������ʹ���������У���ӵ�neighbor��
	Node* cloneGraph(Node* node) {
		//�߽�����
		if (node == NULL) return NULL;
		queue<Node*> q;
		map<Node*, Node*> hash_table;
		Node* copy = new Node(node->val);
		q.push(node);
		hash_table[node] = copy;
		Node* cur = NULL;
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			//�����ھ�
			for (auto& neighbor : cur->neighbors) {
				if (hash_table.count(neighbor)) {
					hash_table[cur]->neighbors.push_back(hash_table[neighbor]);
				}  //�Ѿ����ʹ�,�������,����ɻ�����ѭ��
				else {
					q.push(neighbor);
					Node* copyNeighbor = new Node(neighbor->val);
					hash_table[cur]->neighbors.push_back(copyNeighbor);
					hash_table[neighbor] = copyNeighbor;
				}
			}
		}
		return copy;
	}
};