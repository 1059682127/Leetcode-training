//lt79

/*
79. 单词搜索
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.

//思路1：递归

*/


class Solution {
public:
	//思路1：递归
	//建立邻接表，vector<vector<int> > v{{-1, 0},{0, 1}, {1, 0}, {0, -1}};
	//哈希表判断是否访问过，不能被当前路径访问，但是可以被别的路径
	//终止条件：递归字符不同，return flase; 如果字符相同且遍历到最后，返回true
	//Trick1:建立哈希表时将二维下标转为一维 i * col + row，0表示未访问，1表示被当前递归路径访问过
	//Trick2:建立反索引数组，根据字母找到下标
	//时间：O(M*N)图一次搜索的复杂度是O(E+V),在这里是O(M*N)，因为使用了反索引数组，所以选择起始点的时候不用尝试每个顶点
	//空间：O(M*N)

	//注意点：1、回溯时机 2、二维索引转一维索引
	int row;
	int col;
	vector<vector<int> > adjacency{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	bool exist(vector<vector<char>>& board, string word) {
		row = board.size();
		col = board[0].size();
		vector<bool> isVisited(row * col, 0);
		unordered_map <char, vector<int>> index;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				index[board[i][j]].push_back(i * col + j);
			}
		}
		int len = word.size();
		for (auto start : index[word[0]]) {
			if (DFS(start, 0, len, word, board, isVisited)) return true;
		}
		return false;
	}
	bool DFS(int start, int num, int len, string& word, vector<vector<char>>& board, vector<bool>& isVisited) {
		int X = start / col;
		int Y = start % col;
		if (num == len - 1) return board[X][Y] == word[num];
		if (board[X][Y] != word[num]) return false;
		isVisited[start] = true;
		//遍历邻居
		for (int i = 0; i < 4; ++i) {
			int newX = X + adjacency[i][0];
			int newY = Y + adjacency[i][1];
			int nei = newX * col + newY;
			if (newX >= 0 && newX < row && newY >= 0 && newY < col) {
				if (!isVisited[nei]) {
					if (DFS(nei, num + 1, len, word, board, isVisited)) return true;
				}
			}
		}
		isVisited[start] = false; //注意回溯的时机
		return false;
	}
};