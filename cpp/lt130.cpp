//lt130
/*
130. 被围绕的区域

给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X


运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X


解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

//思路1：广度优先搜索
//思路2：DFS递归
//思路3：DFS迭代
*/


class Solution {
public:
	//思路1：广度优先搜索
	//难点是怎么判断是否为边界，可以从边界'O'开始广度优先搜索，将与边界'O'的'0'置为'#';然后再遍历一遍，将'O'置为'X',将'#'置为'O'
	//时间：O(M*N)每个节点遍历一次
	//空间：O(M+N)最坏的情况是给定的broad全是'X',每次队列中的结点虽然会往四个方向拓展，但是事实上这些结点会有很多重复，假设从中点出发，可以想象最大的扩展不会超过一个菱形，也就是n/2*2+m/2*2=m+n
	
	//Trick1:为啥不用递归？递归很容易导致栈溢出，所以即使要用深度优先搜索，也最好使用非递归的实现方式哈
	int row;
	int col;
	vector<vector<int> > adjacency{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	void solve(vector<vector<char>>& board) {
		if (board.size() <= 1 || board[0].size() <= 1) return;
		row = board.size();
		col = board[0].size();
		//对边缘进行递归，状态设计为已访问
		for (int i = 0; i < col; ++i) {
			fill(board, 0, i);
			fill(board, row - 1, i);
		}
		for (int j = 1; j < row - 1; ++j) {
			fill(board, j, 0);
			fill(board, j, col - 1);
		}
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (board[i][j] == 'O') board[i][j] = 'X';
				else if (board[i][j] == '#') board[i][j] = 'O';
			}
		}
	}
	void fill(vector<vector<char>>& board, int i, int j) {
		if (board[i][j] != 'O') return;
		queue<int> q;
		q.push(i * col + j);
		board[i][j] = '#';
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			int curX = cur / col;
			int curY = cur % col;
			//遍历邻居
			for (int i = 0; i < 4; ++i) {
				int neiX = curX + adjacency[i][0];
				int neiY = curY + adjacency[i][1];
				int neiIndex = neiX * col + neiY;
				if (neiX >= 0 && neiX < row && neiY >= 0 && neiY < col && board[neiX][neiY] == 'O') {
					board[neiX][neiY] = '#';  //'#'说明已经访问过
					q.push(neiIndex);
				}
			}
		}
	}
};


class Solution {
public:
	//思路2：DFS递归
	//难点是怎么判断是否为边界，可以从边界'O'开始优先搜索，将与边界'O'的'0'置为'#';然后再遍历一遍，将'O'置为'X',将'#'置为'O'
	int row;
	int col;
	vector<vector<int> > adjacency{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	void solve(vector<vector<char>>& board) {
		if (board.size() <= 1 || board[0].size() <= 1) return;
		row = board.size();
		col = board[0].size();
		//对边缘进行递归，状态设计为已访问
		for (int i = 0; i < col; ++i) {
			fill(board, 0, i);
			fill(board, row - 1, i);
		}
		for (int j = 1; j < row - 1; ++j) {
			fill(board, j, 0);
			fill(board, j, col - 1);
		}
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (board[i][j] == 'O') board[i][j] = 'X';
				else if (board[i][j] == '#') board[i][j] = 'O';
			}
		}
	}
	void fill(vector<vector<char>>& board, int i, int j) {
		if (i < 0 || i >= row || j < 0 || j >= col || board[i][j] == '#' || board[i][j] == 'X') return;
		board[i][j] = '#';
		fill(board, i - 1, j);
		fill(board, i, j + 1);
		fill(board, i + 1, j);
		fill(board, i, j - 1);
	}
};

class Solution {
public:
	//思路3：DFS迭代
	//难点是怎么判断是否为边界，可以从边界'O'开始优先搜索，将与边界'O'的'0'置为'#';然后再遍历一遍，将'O'置为'X',将'#'置为'O'
	int row;
	int col;
	vector<vector<int> > adjacency{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	void solve(vector<vector<char>>& board) {
		if (board.size() <= 1 || board[0].size() <= 1) return;
		row = board.size();
		col = board[0].size();
		//对边缘进行递归，状态设计为已访问
		for (int i = 0; i < col; ++i) {
			fill(board, 0, i);
			fill(board, row - 1, i);
		}
		for (int j = 1; j < row - 1; ++j) {
			fill(board, j, 0);
			fill(board, j, col - 1);
		}
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (board[i][j] == 'O') board[i][j] = 'X';
				else if (board[i][j] == '#') board[i][j] = 'O';
			}
		}
	}
	//迭代版
	void fill(vector<vector<char>>& board, int i, int j) {
		if (board[i][j] == 'X') return;
		stack<int> data;
		data.push(i * col + j);
		board[i][j] = '#';
		while (!data.empty()) {
			//先往一个方向走到底
			int cur = data.top();
			int curX = cur / col;
			int curY = cur % col;
			//向上
			if (curX - 1 >= 0 && board[curX - 1][curY] == 'O') {
				data.push((curX - 1) * col + curY);
				board[curX - 1][curY] = '#';
				continue;
			}
			//向右
			if (curY + 1 < col && board[curX][curY + 1] == 'O') {
				data.push(curX * col + (curY + 1));
				board[curX][curY + 1] = '#';
				continue;
			}
			//向下
			if (curX + 1 < row && board[curX + 1][curY] == 'O') {
				data.push((curX + 1) * col + curY);
				board[curX + 1][curY] = '#';
				continue;
			}
			//向左
			if (curY - 1 >= 0 && board[curX][curY - 1] == 'O') {
				data.push(curX * col + (curY - 1));
				board[curX][curY - 1] = '#';
				continue;
			}
			//走到无路可走，本次搜索结束，弹出stack
			data.pop();

		}
	}
};