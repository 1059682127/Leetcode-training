/*
�������˶���Χ
������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ�񣬵��ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� ���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18�����ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
*/

class Solution {
public:
	//�ݹ�
	//��ϣ���¼�Ƿ���ʹ�
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
		//�˳�����
		isVisited.insert(curY * cols + curX);
		//�����ھ�
		for (int i = 0; i < 4; ++i) {
			int nextX = curX + directions[i][1];
			int nextY = curY + directions[i][0];
			if (inMatrix(nextX, nextY, rows, cols) && !isVisited.count(nextY * cols + nextX) && sumBit(nextY, nextX) <= threshold) {
				dfs(threshold, nextX, nextY, rows, cols, isVisited);
			}
		}
	}
};