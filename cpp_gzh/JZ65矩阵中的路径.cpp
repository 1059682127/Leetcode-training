/*
矩阵中的路径

请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如 

矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/

class Solution {
public:
	//思路：DFS递归的回溯剪枝思想
	//外层循环找到DFS入口，内存进行DFS
	unordered_map<int, bool> isVisited;
	vector<vector<int>> direction = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (matrix[i * cols + j] == str[0]) {
					if (dfs(matrix, rows, cols, str, i, j, 0)) return true;
				}
			}
		}
		return false;
	}
	bool dfs(char* matrix, int rows, int cols, char* str, int x, int y, int index) {
		if (index == strlen(str) - 1) return true;
		//记录当前点
		isVisited[x * cols + y] = true;
		//遍历邻居
		for (int i = 0; i < 4; ++i) {
			int nei_x = x + direction[i][0];
			int nei_y = y + direction[i][1];
			if (inMatrix(rows, cols, nei_x, nei_y) && !isVisited[nei_x * cols + nei_y] && matrix[nei_x * cols + nei_y] == str[index + 1] && dfs(matrix, rows, cols, str, nei_x, nei_y, index + 1)) {
				return true;
			}
		}
		isVisited[x * cols + y] = false;
		return false;
	}
	bool inMatrix(int rows, int cols, int x, int y) {
		return x >= 0 && x < rows && y >= 0 && y < cols;
	}
};