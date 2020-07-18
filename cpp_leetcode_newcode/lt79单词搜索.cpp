//lt79

/*
79. ��������
����һ����ά�����һ�����ʣ��ҳ��õ����Ƿ�����������С�

���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�

ʾ��:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

���� word = "ABCCED", ���� true.
���� word = "SEE", ���� true.
���� word = "ABCB", ���� false.

//˼·1���ݹ�

*/


class Solution {
public:
	//˼·1���ݹ�
	//�����ڽӱ�vector<vector<int> > v{{-1, 0},{0, 1}, {1, 0}, {0, -1}};
	//��ϣ���ж��Ƿ���ʹ������ܱ���ǰ·�����ʣ����ǿ��Ա����·��
	//��ֹ�������ݹ��ַ���ͬ��return flase; ����ַ���ͬ�ұ�������󣬷���true
	//Trick1:������ϣ��ʱ����ά�±�תΪһά i * col + row��0��ʾδ���ʣ�1��ʾ����ǰ�ݹ�·�����ʹ�
	//Trick2:�������������飬������ĸ�ҵ��±�
	//ʱ�䣺O(M*N)ͼһ�������ĸ��Ӷ���O(E+V),��������O(M*N)����Ϊʹ���˷��������飬����ѡ����ʼ���ʱ���ó���ÿ������
	//�ռ䣺O(M*N)

	//ע��㣺1������ʱ�� 2����ά����תһά����
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
		//�����ھ�
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
		isVisited[start] = false; //ע����ݵ�ʱ��
		return false;
	}
};