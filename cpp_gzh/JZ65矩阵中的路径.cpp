/*
�����е�·��

�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ����һ��·�������˾����е�ĳһ�����ӣ����·�������ٽ���ø��ӡ� ���� 

�����а���һ���ַ���"bcced"��·�������Ǿ����в�����"abcb"·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�
*/

class Solution {
public:
	//˼·��DFS�ݹ�Ļ��ݼ�֦˼��
	//���ѭ���ҵ�DFS��ڣ��ڴ����DFS
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
		//��¼��ǰ��
		isVisited[x * cols + y] = true;
		//�����ھ�
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