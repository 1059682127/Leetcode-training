//lt200

/*
��������

����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά���񣬼��㵺���������һ������ˮ��Χ����������ͨ��ˮƽ�����ֱ���������ڵ�½�����Ӷ��ɵġ�����Լ���������ĸ��߾���ˮ��Χ��
ʾ�� 1:
����:
11110
11010
11000
00000

���: 1
ʾ�� 2:
����:
11000
11000
00100
00011

���: 3
�ο���https://leetcode-cn.com/problems/number-of-islands/solution/dfs-bfs-bing-cha-ji-python-dai-ma-java-dai-ma-by-l/
˼·1��BFS�����й�����ȱ������Ƚ��ȳ����������У�ÿ�������ĸ�������֮���������е㶼����ϣ���Ϊͬһ�����죻���ж��ٴ�BFS�����ٸ�����
˼·2��DFS����������ȱ�����һ��·�����ʵ��ף��ٻ��ݣ�ÿ���㣨�ȱ�ǣ��ٷ��ĸ����������ȱ�����
*/




class Solution {
public:
	//���⣺��ʵ��������ͨ����ĸ���
	//˼·1��BFS�����й�����ȱ������Ƚ��ȳ����������У�ÿ�������ĸ�������֮���������е㶼����ϣ���Ϊͬһ�����죻���ж��ٴ�BFS�����ٸ�����
	//Trick1�������ʱ�ͱ�Ǹõ��Ѿ�����
	//Trick2�������ʱ����i * col + j����ʾ�õ㣬�����Ϳ��Բ���pair
	//Trick3������ĸ���������ö�ά�����ʾvector<vector<int> > direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	//BFS˼�룺ÿ�ΰ����ڵ�δ���ʵĵ�����У�Ȼ�󽫵�ǰ������У�ֱ������Ϊ�գ���BFS��ϣ��ҵ��������ʼ�������ĵ�


	//֪ʶ�㣺
	//1��������ȱ����������߱�ÿһ�ֿ��ܵ�·������һ��·���ߵ��ײ�һ������Զ������·�����п����ȳ����߽Ͻ���·��������ڽӱ�����ڽӾ�����ô��¼ͼ�йأ���һ��·������߲�ͨ�ͷ������ݣ������µ�·��������ʵĽ���ڻ��ݵ�ʱ���ȳ�ջ�����ȷ��ʵĽ������ջ������ʹ��ջ��
	//2��������ȱ�����һ��ʼ����ȥ���뵱ǰ�ڵ�����Ľڵ㣬�����������˲��ö���ʵ�֡�
	//3��������ת��Ϊ���ֵ�ʱ����i * col + j, ������i * row + j
	/*3��STL����ʹ�ã���Ҫʹ�����ȼ�����priority_queue��
	queue<int> q;
	q.empty()// �������Ϊ�շ���true�����򷵻�false
	q.size() // ���ض�����Ԫ�صĸ���
	q.pop()  //ɾ��������Ԫ�ص���������ֵ
	q.front()  // ���ض���Ԫ�ص�ֵ������ɾ����Ԫ��
	q.push(X) //�ڶ�βѹ����Ԫ�� ��XΪҪѹ���Ԫ��
	q.back() //���ض���βԪ�ص�ֵ������ɾ����Ԫ��
	*/
	int numIslands(vector<vector<char>>& grid) {
		//��¼�ĸ�����
		vector<vector<int> > direction = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
		int row = grid.size();
		if (row == 0) return 0;
		int col = grid[0].size();
		//��¼�Ƿ���ʹ�
		vector<vector<bool>> visited(row, vector<bool>(col, false));

		int count = 0; //��¼��������
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				//����õ�Ϊ½����û�б����ʹ����Ըõ�Ϊ��ʼ�����BFS
				if (!visited[i][j] && grid[i][j] == '1') {
					++count;
					queue<int> q;
					q.push(i * col + j);  //������ת��Ϊ���֣���ס���ǳ�������
					visited[i][j] = true;  //��ջ����ӱ�ǣ��ȳ�ջ�ٱ�ǻᵼ���ظ���ջ
					while (!q.empty()) {
						int cur = q.front();
						int curx = cur / col;
						int cury = cur % col;
						//���ĸ������Ƿ��������������ӣ��õ�δ�����ʣ�����½�أ�û�г����߽�
						for (int k = 0; k < 4; ++k) {  //!!!ע�⣬�˴������ض���i,������ѭ����i���ǵ�
							int nodex = curx + direction[k][0];
							int nodey = cury + direction[k][1];
							//���ж��Ƿ���߽磬���ж�����������������������Խ��
							if ((nodex >= 0 && nodex < row) && (nodey >= 0 && nodey < col) && !visited[nodex][nodey] && grid[nodex][nodey] == '1') {
								q.push(nodex * col + nodey);
								visited[nodex][nodey] = true;
							}
						}
						//��ǰ�ڵ������
						q.pop();
					}
				}
			}
		}
		return count;
	}
};

//ִ����ʱ:12 ms, ������ C++ �ύ�л�����88.06%���û�
//�ڴ����� :11.6 MB, ������ C++ �ύ�л�����17.90%���û�
class Solution {

	//���⣺��ʵ��������ͨ����ĸ���
	//˼·2:����������ȱ�����һ��·�����ʵ��ף��ٻ��ݣ�ÿ���㣨�ȱ�ǣ��ٷ��ĸ����������ȱ�����
	//Trick1����Ƿ��ʹ���ʵ�ּ�֦



	//֪ʶ�㣺
	//1��������ȱ����������߱�ÿһ�ֿ��ܵ�·������һ��·���ߵ��ײ�һ������Զ������·�����п����ȳ����߽Ͻ���·��������ڽӱ�����ڽӾ�����ô��¼ͼ�йأ���һ��·������߲�ͨ�ͷ������ݣ������µ�·��������ʵĽ���ڻ��ݵ�ʱ���ȳ�ջ�����ȷ��ʵĽ������ջ������ʹ��ջ��
	//2��������ȱ�����һ��ʼ����ȥ���뵱ǰ�ڵ�����Ľڵ㣬�����������˲��ö���ʵ�֡�
	//3��������ת��Ϊ���ֵ�ʱ����i * col + j, ������i * row + j
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
		int count = 0; //��¼��������
		//������ά���飬�ҵ�δ���ʵ�'1'��Ϊdfs���
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (!visited[i][j] && grid[i][j] == '1') {
					++count;
					//������ȱ���
					dfs(i, j);
				}
			}
		}
		return count;
	}
	void dfs(int i, int j) {
		visited[i][j] = true;
		for (int k = 0; k < 4; ++k) {  //!!!ע�⣬�˴������ض���i,������ѭ����i���ǵ�
			int nodex = i + direction[k][0];
			int nodey = j + direction[k][1];
			//���ж��Ƿ���߽磬���ж�����������������������Խ��
			if ((nodex >= 0 && nodex < row) && (nodey >= 0 && nodey < col) && !visited[nodex][nodey] && grid[nodex][nodey] == '1') {
				dfs(nodex, nodey);
			}
		}
	}
};