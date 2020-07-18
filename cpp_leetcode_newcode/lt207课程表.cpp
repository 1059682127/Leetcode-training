//lt207
/*
课程表

现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？

示例 1:

输入: 2, [[1,0]]
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。

//思路1：拓扑排序+广度优先搜索+入度表
//思路2：深度优先搜索0(N+M)/O(N)
*/
class Solution {
public:
	//思路1：拓扑排序+广度优先搜索+入度表
	//本题可约化为：课程安排图是否是 有向无环图(DAG)。即课程间规定了前置条件，但不能构成任何环路，否则课程前置条件将不成立。

	//思路是通过 拓扑排序 判断此课程安排图是否是 有向无环图(DAG)。 
	//拓扑排序是对 DAG 的顶点进行排序，使得对每一条有向边(u,v)，均有u比v先出现（在排序记录中）

	//通过课程前置条件列表 prerequisites 可以得到课程安排图的 邻接矩阵 adjacency

	//算法步骤：
	//1、统计入度表：indegrees
	//2、入度为0的入队列
	//3、首元素出队列，并删除该节点pre（将所有邻接节点的入度-1，当邻接节点的入度为0，说明该邻接节点的前驱都已经被删除，可以入队列）
	//4、出队列时，numCourses--； 如果是有向无环图，所有的节点都入队出队过，完成拓扑排序

	//时间:O(N+M),遍历图需要访问所有的节点和邻边
	//空间:O(N),需要统计入度数
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> indegrees(numCourses, 0);
		for (int i = 0; i < prerequisites.size(); ++i) indegrees[prerequisites[i][0]]++;
		queue<int> q;
		for (int i = 0; i < numCourses; ++i) {
			if (indegrees[i] == 0) q.push(i);
		}
		while (!q.empty()) {
			int pre = q.front();
			q.pop();
			--numCourses;
			for (int i = 0; i < prerequisites.size(); ++i) {
				if (prerequisites[i][1] == pre) {
					if (--indegrees[prerequisites[i][0]] == 0) q.push(prerequisites[i][0]);
				}

			}
		}
		return numCourses == 0;
	}
};

class Solution {
public:
	//思路2：深度优先搜索0(N+M)/O(N)

	//深度搜索
	//flag标记，未访问过：0；被其它节点的DFS访问过：-1；被本节点的DFS访问过：1

	//DFS流程：
	//终止条件：
	//(1)如果flag = -1，则表示被其它节点搜索过，无需重复搜索，return true；
	//(2)如果flag = 1, 则表示被本节点的DFS访问过，return false;
	//将当前访问节点 i 对应 flag[i] 置1，即标记其被本轮 DFS 访问过；
	//递归访问当前节点 i 的所有邻接节点 j，当发现环直接返回false;
	//当前节点所有邻接节点已被遍历，并没有发现环，则将当前节点 flag 置为-1，并返回true

	//Trick1:建立邻接矩阵
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> isVisited(numCourses, 0);
		vector<vector<int>> adjacency(numCourses, vector<int>(numCourses));
		for (auto& req : prerequisites) adjacency[req[1]][req[0]] = 1;
		for (int i = 0; i < numCourses; ++i) {
			if (isVisited[i] == 0 && !DFS(i, adjacency, isVisited)) return false;
		}
		return true;
	}
	bool DFS(int u, vector<vector<int>>& adjacency, vector<int>& isVisited) {
		if (isVisited[u] == -1) return true;
		if (isVisited[u] == 1) return false;
		isVisited[u] = 1;  //在本轮访问过
		for (int v = 0; v < adjacency[u].size(); ++v) {
			if (adjacency[u][v] && !DFS(v, adjacency, isVisited)) return false;
		}
		isVisited[u] = -1;  //本轮访问完毕
		return true;
	}
};