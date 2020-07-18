//lt133
/*

克隆图

给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。

图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。

class Node {
	public int val;
	public List<Node> neighbors;
}



测试用例格式：

简单起见，每个节点的值都和它的索引相同。例如，第一个节点值为 1，第二个节点值为 2，以此类推。该图在测试用例中使用邻接列表表示。

邻接列表是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。

给定节点将始终是图中的第一个节点（值为 1）。你必须将 给定节点的拷贝 作为对克隆图的引用返回。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/clone-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//思路1：深度优先遍历
//思路2：广度优先遍历
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
	//思路1：深度优先遍历（hash_table记录已经访问过的节点及该节点克隆结果）
	//如果node==NULL,回溯
	//如果已经已经访问过，返回克隆结果；否则，创建新节点，并添加邻居
	//0——1——2——3 DFS(0)创建节点,val, nerghbor.push_back(DFS(1));
	Node* cloneGraph(Node* node) {
		map<Node*, Node*> hash_table;
		return helper(node, hash_table);
	}
	Node* helper(Node* node, map<Node*, Node*>& hash_table) {
		if (node == NULL) return NULL;
		if (hash_table.count(node)) return hash_table[node];
		//创建新节点
		Node* copyNode = new Node(node->val);
		hash_table[node] = copyNode;
		for (auto& neighbor : node->neighbors) copyNode->neighbors.push_back(helper(neighbor, hash_table));
		return copyNode;
	}
};

class Solution {
public:
	//思路2：广度优先遍历
	//Trick1:hash_table记录<Node*, 复制的节点>

	//判断邻居是否未访问过，是的话入队列，且添加到neighbors中；若访问过，不入队列，添加到neighbor中
	Node* cloneGraph(Node* node) {
		//边界条件
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
			//遍历邻居
			for (auto& neighbor : cur->neighbors) {
				if (hash_table.count(neighbor)) {
					hash_table[cur]->neighbors.push_back(hash_table[neighbor]);
				}  //已经访问过,不入队列,避免成环无限循环
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