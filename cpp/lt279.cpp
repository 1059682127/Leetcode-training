


//lt279

/*
��ȫƽ����

���������� n���ҵ����ɸ���ȫƽ���������� 1, 4, 9, 16, ...��ʹ�����ǵĺ͵��� n������Ҫ����ɺ͵���ȫƽ�����ĸ������١�
ʾ�� 1:
����: n = 12
���: 3
����: 12 = 4 + 4 + 4.
ʾ�� 2:
����: n = 13
���: 2
����: 13 = 4 + 9.
//˼·1��BFS
//˳��2����̬�滮
*/

//ִ����ʱ:36 ms, ������ C++ �ύ�л�����90.08%���û�
//�ڴ����� :10.7 MB, ������ C++ �ύ�л�����80.39%���û�
class Solution {
public:
	//˼·1��BFS����һ����13���ڶ���12��9��4��������11��8��3.������
	//BFSͼ�ɲο���https://leetcode-cn.com/problems/perfect-squares/solution/yan-du-you-xian-sou-suo-java-by-eiletxie/
	//Trick1:���֪����ǰ��������һ���ջ13���ڶ����ջ12��9��4��������һ�����֮ǰ�ȼ�¼�Ĳ����q.size()

	//��ÿһ�ζ������жϳ�����������ж�ε�ʱ����ʺ���BFS-������ȱ���
	//ʹ��BFSӦע�⣺
	//���У������洢ÿһ�ֱ����õ��Ľڵ㣻
	//��ǣ����ڱ������Ľڵ㣨ʣ��ֵ����Ӧ�ý�����ǣ���ֹ�ظ�������(�ڶ��α��������ýڵ��·�����ȿ϶���С�ڵ�һ�α����ĳ���)


	int numSquares(int n) {
		queue<int> q;
		q.push(n);
		int step = 0;
		vector<bool> isVisited(n, false);
		while (!q.empty()) {
			int size = q.size();
			++step;
			while (size > 0) {   //��size == 0, ��ʾ�ĳɱ�����
				int cur = q.front();
				q.pop();
				--size;
				for (int i = 1; i <= sqrt(cur); i++) {
					int nextVal = cur - i * i;
					if (nextVal == 0) return step;
					if (!isVisited[nextVal]) {
						q.push(nextVal);
						isVisited[nextVal] = true;
					}

				}
			}

		}
		return -1;
	}
};

//ִ����ʱ:248 ms, ������ C++ �ύ�л�����14.96%���û�
//�ڴ����� :11.4 MB, ������ C++ �ύ�л�����43.64%���û�
class Solution {
public:
	//˼·2����̬�滮
	//״̬dp[i],��¼ÿ����Ҫ��������ȫƽ����
	//base��dp[i] = i,����������һֱ+1
	//״̬ת�ƣ�dp[i] = min(dp[i], dp[i - j^2] + 1)

	int numSquares(int n) {
		vector<int> dp(n + 1);
		for (int i = 1; i <= n; i++) {
			dp[i] = i;  //��ֵ
			for (int j = 1; j <= sqrt(i); j++) {
				dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
		}
		return dp[n];
	}
};