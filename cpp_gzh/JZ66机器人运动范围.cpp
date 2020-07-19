/*
机器人运动范围
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/

class Solution {
public:
	//递归
	//哈希表记录是否访问过
	vector<vector<int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	int movingCount(int threshold, int rows, int cols)
	{
		if (threshold <= 0) return 0;
		unordered_set<int> isVisited;
		dfs(threshold, 0, 0, rows, cols, isVisited);
		return isVisited.size();
	}
	bool inMatrix(int curX, int curY, int rows, int cols) {
		return curX >= 0 && curX < cols && curY >= 0 && curY < rows;
	}
	int sumBit(int a, int b) {
		int res = 0;
		while (a % 10) {
			res += a % 10;
			a /= 10;
		}
		while (b % 10) {
			res += b % 10;
			b /= 10;
		}
		return res;
	}
	void dfs(int threshold, int curX, int curY, int rows, int cols, unordered_set<int> &isVisited) {
		//退出条件
		isVisited.insert(curY * cols + curX);
		//遍历邻居
		for (int i = 0; i < 4; ++i) {
			int nextX = curX + directions[i][1];
			int nextY = curY + directions[i][0];
			if (inMatrix(nextX, nextY, rows, cols) && !isVisited.count(nextY * cols + nextX) && sumBit(nextY, nextX) <= threshold) {
				dfs(threshold, nextX, nextY, rows, cols, isVisited);
			}
		}
	}
};