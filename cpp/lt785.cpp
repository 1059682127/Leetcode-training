//lt785
/*
判断二分图

给定一个无向图graph，当这个图为二分图时返回true。

如果我们能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个节点一个来自A集合，一个来自B集合，我们就将这个图称为二分图。

graph将会以邻接表方式给出，graph[i]表示图中与节点i相连的所有节点。每个节点都是一个在0到graph.length-1之间的整数。这图中没有自环和平行边： graph[i] 中不存在i，并且graph[i]中没有重复的值。


示例 1:
输入: [[1,3], [0,2], [1,3], [0,2]]
输出: true
解释:
无向图如下:
0----1
|    |
|    |
3----2
我们可以将节点分成两组: {0, 2} 和 {1, 3}。

//思路1：递归（染色法）
//思路2：迭代（染色法/贪心思想）
*/

class Solution {
public:
	//思路1：递归（染色法）
	//遍历顶点，对每个未访问的顶点u，染色一种颜色， DFS(u)
	//对于u的每个顶点v，如果v未被访问,将u,v置不同色，则继续DFS(v)，如果u,v同色，则return false;

	//Trick1:可能是非连通图，因此要进行多次dfs，直到都遍历到所有顶点
	//Trick2:用哈希表，没访问到，bool代表白色，true代表黑色
	map<int, bool> isVisited;   //bool代表白色，true代表黑色
	bool isBipartite(vector<vector<int>>& graph) {
		int N = graph.size();
		for (int i = 0; i < N; ++i) {
			if (!isVisited.count(i)) {
				isVisited[i] = true;
				if (!DFS(i, graph)) return false;
			}
		}
		return true;
	}
	bool DFS(int u, vector<vector<int>>& graph) {
		//边界条件
		for (auto v : graph[u]) {
			if (!isVisited.count(v)) {
				isVisited[v] = !isVisited[u];
				if (!DFS(v, graph)) return false;
			}
			else {
				if (isVisited[u] == isVisited[v]) return false;
			}
		}
		return true;
	}

};


class Solution {
public:
	//思路2：递归（染色法/贪心思想）
	//遍历顶点，对每个未访问的顶点u，染色一种颜色， DFS(u)
	//对于u的每个顶点v，如果v未被访问,将u,v置不同色，则继续DFS(v)，如果u,v同色，则return false;
	//贪心思想：可以使用贪心思想给图着色：一个节点为蓝色，说明它的所有邻接点为红色，它的邻接点的所有邻接点为蓝色

	//Trick1:可能是非连通图，因此要进行多次dfs，直到都遍历到所有顶点
	//Trick2:用哈希表，没访问到，bool代表白色，true代表黑色
	map<int, bool> isVisited;   //bool代表白色，true代表黑色
	bool isBipartite(vector<vector<int>>& graph) {
		int N = graph.size();
		for (int start = 0; start < N; ++start) {
			if (!isVisited.count(start)) {
				isVisited[start] = true;
				stack<int> data;
				data.push(start);
				while (!data.empty()) {
					int cur = data.top();
					data.pop();
					//贪心算法，对每个邻居都进行着色
					for (auto nei : graph[cur]) {
						if (!isVisited.count(nei)) {
							isVisited[nei] = !isVisited[cur];
							data.push(nei);
						}
						else {
							if (isVisited[cur] == isVisited[nei]) return false;
						}
					}
				}
			}
		}
		return true;
	}
};