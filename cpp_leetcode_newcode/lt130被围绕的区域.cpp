//lt130
/*
130. ��Χ�Ƶ�����

����һ����ά�ľ��󣬰��� 'X' �� 'O'����ĸ O����

�ҵ����б� 'X' Χ�Ƶ����򣬲�����Щ���������е� 'O' �� 'X' ��䡣

ʾ��:

X X X X
X O O X
X X O X
X O X X


������ĺ����󣬾����Ϊ��

X X X X
X X X X
X X X X
X O X X


����:

��Χ�Ƶ����䲻������ڱ߽��ϣ����仰˵���κα߽��ϵ� 'O' �����ᱻ���Ϊ 'X'�� �κβ��ڱ߽��ϣ�����߽��ϵ� 'O' ������ 'O' ���ն��ᱻ���Ϊ 'X'���������Ԫ����ˮƽ��ֱ�������ڣ���������ǡ��������ġ�

//˼·1�������������
//˼·2��DFS�ݹ�
//˼·3��DFS����
*/


class Solution {
public:
	//˼·1�������������
	//�ѵ�����ô�ж��Ƿ�Ϊ�߽磬���Դӱ߽�'O'��ʼ�����������������߽�'O'��'0'��Ϊ'#';Ȼ���ٱ���һ�飬��'O'��Ϊ'X',��'#'��Ϊ'O'
	//ʱ�䣺O(M*N)ÿ���ڵ����һ��
	//�ռ䣺O(M+N)�������Ǹ�����broadȫ��'X',ÿ�ζ����еĽ����Ȼ�����ĸ�������չ��������ʵ����Щ�����кܶ��ظ���������е��������������������չ���ᳬ��һ�����Σ�Ҳ����n/2*2+m/2*2=m+n
	
	//Trick1:Ϊɶ���õݹ飿�ݹ�����׵���ջ��������Լ�ʹҪ���������������Ҳ���ʹ�÷ǵݹ��ʵ�ַ�ʽ��
	int row;
	int col;
	vector<vector<int> > adjacency{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	void solve(vector<vector<char>>& board) {
		if (board.size() <= 1 || board[0].size() <= 1) return;
		row = board.size();
		col = board[0].size();
		//�Ա�Ե���еݹ飬״̬���Ϊ�ѷ���
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
			//�����ھ�
			for (int i = 0; i < 4; ++i) {
				int neiX = curX + adjacency[i][0];
				int neiY = curY + adjacency[i][1];
				int neiIndex = neiX * col + neiY;
				if (neiX >= 0 && neiX < row && neiY >= 0 && neiY < col && board[neiX][neiY] == 'O') {
					board[neiX][neiY] = '#';  //'#'˵���Ѿ����ʹ�
					q.push(neiIndex);
				}
			}
		}
	}
};


class Solution {
public:
	//˼·2��DFS�ݹ�
	//�ѵ�����ô�ж��Ƿ�Ϊ�߽磬���Դӱ߽�'O'��ʼ��������������߽�'O'��'0'��Ϊ'#';Ȼ���ٱ���һ�飬��'O'��Ϊ'X',��'#'��Ϊ'O'
	int row;
	int col;
	vector<vector<int> > adjacency{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	void solve(vector<vector<char>>& board) {
		if (board.size() <= 1 || board[0].size() <= 1) return;
		row = board.size();
		col = board[0].size();
		//�Ա�Ե���еݹ飬״̬���Ϊ�ѷ���
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
	//˼·3��DFS����
	//�ѵ�����ô�ж��Ƿ�Ϊ�߽磬���Դӱ߽�'O'��ʼ��������������߽�'O'��'0'��Ϊ'#';Ȼ���ٱ���һ�飬��'O'��Ϊ'X',��'#'��Ϊ'O'
	int row;
	int col;
	vector<vector<int> > adjacency{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	void solve(vector<vector<char>>& board) {
		if (board.size() <= 1 || board[0].size() <= 1) return;
		row = board.size();
		col = board[0].size();
		//�Ա�Ե���еݹ飬״̬���Ϊ�ѷ���
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
	//������
	void fill(vector<vector<char>>& board, int i, int j) {
		if (board[i][j] == 'X') return;
		stack<int> data;
		data.push(i * col + j);
		board[i][j] = '#';
		while (!data.empty()) {
			//����һ�������ߵ���
			int cur = data.top();
			int curX = cur / col;
			int curY = cur % col;
			//����
			if (curX - 1 >= 0 && board[curX - 1][curY] == 'O') {
				data.push((curX - 1) * col + curY);
				board[curX - 1][curY] = '#';
				continue;
			}
			//����
			if (curY + 1 < col && board[curX][curY + 1] == 'O') {
				data.push(curX * col + (curY + 1));
				board[curX][curY + 1] = '#';
				continue;
			}
			//����
			if (curX + 1 < row && board[curX + 1][curY] == 'O') {
				data.push((curX + 1) * col + curY);
				board[curX + 1][curY] = '#';
				continue;
			}
			//����
			if (curY - 1 >= 0 && board[curX][curY - 1] == 'O') {
				data.push(curX * col + (curY - 1));
				board[curX][curY - 1] = '#';
				continue;
			}
			//�ߵ���·���ߣ�������������������stack
			data.pop();

		}
	}
};