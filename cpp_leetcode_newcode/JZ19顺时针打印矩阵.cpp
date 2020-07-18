/*
��Ŀ����
����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣����磬�����������4 X 4���� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 �����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

class Solution {
public:
	vector<vector<int>> direction = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int height = matrix.size();
		if (height < 1) return {};
		int width = matrix[0].size();
		vector<vector<bool>> isVisited(height, vector<bool>(width, false));
		vector<int> res;
		int curX = 0, curY = 0, dire = 0;
		while (curX >= 0 && curX < height && curY >= 0 && curY < width && !isVisited[curX][curY]) {
			res.push_back(matrix[curX][curY]);
			isVisited[curX][curY] = true;
			while (true) {
				int neiX = curX + direction[dire][0];
				int neiY = curY + direction[dire][1];
				if (neiX >= 0 && neiX < height && neiY >= 0 && neiY < width && !isVisited[neiX][neiY]) {
					res.push_back(matrix[neiX][neiY]);
					isVisited[neiX][neiY] = true;
					curX = neiX;
					curY = neiY;
				}
				else {
					break;
				}
			}
			//��������
			dire = (dire + 1) % 4;
			curX = curX + direction[dire][0];
			curY = curY + direction[dire][1];
		}
		return res;
	}
};