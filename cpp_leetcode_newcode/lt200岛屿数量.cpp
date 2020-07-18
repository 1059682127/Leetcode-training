//lt200

/*
岛屿数量

给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
示例 1:
输入:
11110
11010
11000
00000

输出: 1
示例 2:
输入:
11000
11000
00100
00011

输出: 3
参考：https://leetcode-cn.com/problems/number-of-islands/solution/dfs-bfs-bing-cha-ji-python-dai-ma-java-dai-ma-by-l/
思路1：BFS：进行广度优先遍历，先进先出，辅助队列，每个点有四个方向，与之相连的所有点都标记上，视为同一个岛屿；进行多少次BFS即多少个岛屿
思路2：DFS进行深度优先遍历，一条路径访问到底，再回溯，每个点（先标记，再分四个方向进行深度遍历）
*/




class Solution {
public:
	//题意：其实就是求连通区域的个数
	//思路1：BFS：进行广度优先遍历，先进先出，辅助队列，每个点有四个方向，与之相连的所有点都标记上，视为同一个岛屿；进行多少次BFS即多少个岛屿
	//Trick1：入队列时就标记该点已经访问
	//Trick2：入队列时采用i * col + j来表示该点，这样就可以不用pair
	//Trick3：点的四个方向可以用二维数组表示vector<vector<int> > direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	//BFS思想：每次把相邻的未访问的点入队列，然后将当前点出队列，直到队列为空，即BFS完毕，找到所有与初始点相连的点


	//知识点：
	//1、深度优先遍历：尝试走遍每一种可能的路径（先一条路径走到底不一定是最远的那条路径，有可能先尝试走较近的路径，这和邻接表或者邻接矩阵怎么记录图有关），一条路径如果走不通就发生回溯，尝试新的路径。后访问的结点在回溯的时候先出栈，最先访问的结点最后出栈，所以使用栈。
	//2、广度优先遍历：一开始优先去找离当前节点最近的节点，再逐个处理。因此采用队列实现。
	//3、将坐标转换为数字的时候，用i * col + j, 而不是i * row + j
	/*3、STL队列使用（不要使用优先级队列priority_queue）
	queue<int> q;
	q.empty()// 如果队列为空返回true，否则返回false
	q.size() // 返回队列中元素的个数
	q.pop()  //删除队列首元素但不返回其值
	q.front()  // 返回队首元素的值，但不删除该元素
	q.push(X) //在队尾压入新元素 ，X为要压入的元素
	q.back() //返回队列尾元素的值，但不删除该元素
	*/
	int numIslands(vector<vector<char>>& grid) {
		//记录四个方向
		vector<vector<int> > direction = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
		int row = grid.size();
		if (row == 0) return 0;
		int col = grid[0].size();
		//记录是否访问过
		vector<vector<bool>> visited(row, vector<bool>(col, false));

		int count = 0; //记录岛屿数量
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				//如果该点为陆地且没有被访问过，以该点为初始点进行BFS
				if (!visited[i][j] && grid[i][j] == '1') {
					++count;
					queue<int> q;
					q.push(i * col + j);  //将坐标转换为数字，记住，是乘以列数
					visited[i][j] = true;  //进栈即添加标记，等出栈再标记会导致重复入栈
					while (!q.empty()) {
						int cur = q.front();
						int curx = cur / col;
						int cury = cur % col;
						//看四个方向是否有其它点可以添加，该点未被访问，属于陆地，没有超过边界
						for (int k = 0; k < 4; ++k) {  //!!!注意，此处不用重定义i,会把外层循环的i覆盖掉
							int nodex = curx + direction[k][0];
							int nodey = cury + direction[k][1];
							//先判断是否出边界，再判断其它条件，否则会产生数组越界
							if ((nodex >= 0 && nodex < row) && (nodey >= 0 && nodey < col) && !visited[nodex][nodey] && grid[nodex][nodey] == '1') {
								q.push(nodex * col + nodey);
								visited[nodex][nodey] = true;
							}
						}
						//当前节点出队列
						q.pop();
					}
				}
			}
		}
		return count;
	}
};

//执行用时:12 ms, 在所有 C++ 提交中击败了88.06%的用户
//内存消耗 :11.6 MB, 在所有 C++ 提交中击败了17.90%的用户
class Solution {

	//题意：其实就是求连通区域的个数
	//思路2:进行深度优先遍历，一条路径访问到底，再回溯，每个点（先标记，再分四个方向进行深度遍历）
	//Trick1：标记访问过的实现剪枝



	//知识点：
	//1、深度优先遍历：尝试走遍每一种可能的路径（先一条路径走到底不一定是最远的那条路径，有可能先尝试走较近的路径，这和邻接表或者邻接矩阵怎么记录图有关），一条路径如果走不通就发生回溯，尝试新的路径。后访问的结点在回溯的时候先出栈，最先访问的结点最后出栈，所以使用栈。
	//2、广度优先遍历：一开始优先去找离当前节点最近的节点，再逐个处理。因此采用队列实现。
	//3、将坐标转换为数字的时候，用i * col + j, 而不是i * row + j
private:
	int row;
	int col;
	vector<vector<int> > direction = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	vector<vector<bool>> visited;
	vector<vector<char>> grid;
public:
	int numIslands(vector<vector<char>>& grid) {

		row = grid.size();
		if (row == 0) return 0;
		col = grid[0].size();
		this->grid = grid;
		visited = vector(row, vector<bool>(col, false));
		int count = 0; //记录岛屿数量
		//遍历二维数组，找到未访问的'1'作为dfs起点
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (!visited[i][j] && grid[i][j] == '1') {
					++count;
					//进行深度遍历
					dfs(i, j);
				}
			}
		}
		return count;
	}
	void dfs(int i, int j) {
		visited[i][j] = true;
		for (int k = 0; k < 4; ++k) {  //!!!注意，此处不用重定义i,会把外层循环的i覆盖掉
			int nodex = i + direction[k][0];
			int nodey = j + direction[k][1];
			//先判断是否出边界，再判断其它条件，否则会产生数组越界
			if ((nodex >= 0 && nodex < row) && (nodey >= 0 && nodey < col) && !visited[nodex][nodey] && grid[nodex][nodey] == '1') {
				dfs(nodex, nodey);
			}
		}
	}
};