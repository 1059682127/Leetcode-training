//lt887

/*
��Ŀ����
�㽫��� K ��������������ʹ��һ���� 1 �� N  ���� N ��¥�Ľ�����
ÿ�����Ĺ��ܶ���һ���ģ����һ�������ˣ���Ͳ����ٰ�������ȥ��
��֪������¥�� F ������ 0 <= F <= N �κδӸ��� F ��¥�����µļ��������飬�� F ¥�������͵�¥�����µļ����������ơ�
ÿ���ƶ��������ȡһ��������������������ļ���������������һ¥�� X ���£����� 1 <= X <= N����
���Ŀ����ȷ�е�֪�� F ��ֵ�Ƕ��١�
���� F �ĳ�ʼֵ��Σ���ȷ�� F ��ֵ����С�ƶ������Ƕ��٣�


ʾ�� 1��
���룺K = 1, N = 2
�����2
���ͣ�
������ 1 ¥���䡣��������ˣ����ǿ϶�֪�� F = 0 ��
���򣬼����� 2 ¥���䡣��������ˣ����ǿ϶�֪�� F = 1 ��
�����û�飬��ô���ǿ϶�֪�� F = 2 ��
��ˣ�����������������Ҫ�ƶ� 2 ����ȷ�� F �Ƕ��١�
ʾ�� 2��
���룺K = 2, N = 6
�����3
ʾ�� 3��
���룺K = 3, N = 14
�����4

��ʾ��
1 <= K <= 100
1 <= N <= 10000

˼·��
1����ֱ�ӵ�������ɨ�裺O(N)
2������������ޣ����ſ϶��Ƕ��ַ�:O(logN)
3������������ƣ����Կ����ö��ַ�������ɨ�裬������ַ�����ɨ��
4����̬�滮��O(KN^2)/O(KN)
���ߣ�labuladong
���ӣ�https://leetcode-cn.com/problems/super-egg-drop/solution/ji-ben-dong-tai-gui-hua-jie-fa-by-labuladong/
��1��״̬�������ԣ����ǵ�ǰӵ�еļ����� K ����Ҫ���Ե�¥���� N
��2��ѡ����ʵ����ȥѡ���Ĳ�¥�Ӽ���i��
�����㷨���:
# ��ǰ״̬Ϊ K ����������� N ��¥
# �������״̬�µ����Ž��
def dp(K, N):
	int res
	for 1 <= i <= N:
		res = min(res, ����ڵ� i ��¥�Ӽ���)
	return res

��3��״̬ת��:
����������ˣ���ô�����ĸ��� K Ӧ�ü�һ��������¥������Ӧ�ô� [1..N] ��Ϊ [1..i-1] �� i-1 ��¥��
�������û�飬��ô�����ĸ��� K ���䣬������¥������Ӧ�ô�  [1..N] ��Ϊ [i+1..N] �� N-i ��¥��
Ҫ������������Ӽ����Ĵ��������Լ����ڵ� i ��¥��û�飬ȡ������������Ľ������

��4���ݹ�� base case ��������⣺��¥���� N ���� 0 ʱ����Ȼ����Ҫ�Ӽ������������� K Ϊ 1 ʱ����Ȼֻ������ɨ������¥�㣺

5�����ֲ����Ż�:0(K*N*logN)/O(K*N)
�ο�labuladong��˵������ʵ״̬ת�Ʒ���min(max(f1,f2))f1������f2�ݼ�����ʵ������ɽ��ֵ,�����ö�������
6�����¶���״̬ת��



֪ʶ�㣺
1����̬�滮��
��1������˼·����ʲô��״̬������ʲô��ѡ�񡹣�Ȼ����١�
��2��ʱ�临�Ӷȣ���̬�滮�㷨��ʱ�临�ӶȾ������������ �� ��������ĸ��Ӷȡ�
��������ĸ��Ӷ��Ǻ��Եݹ鲿�֣���������ǲ�ͬ״̬��ϵ�����



*/


//��̬�滮���ᳬ��ʱ������
class Solution {
public:
	int superEggDrop(int K, int N) {
		int res = INT_MAX;

		//base case
		if (N == 0) return 0;
		if (K == 1) return N;
		//״̬ת��
		for (int i = 1; i <= N; i++) {
			res = min(res,
				max(superEggDrop(K, N - i), superEggDrop(K - 1, i - 1)) + 1);  //������ȥ���ߴ�ֵ������i��ˤһ��
		}
		return res;
	}
};


//��̬�滮+����¼��ͬ���ᳬ��ʱ��
class Solution {
public:
	

	int superEggDrop(int K, int N) {
		vector<vector<int>> matrix(K + 1, vector<int>(N + 1));
		return helper2(K, N, matrix);
	}
	int helper2(int K, int N, vector<vector<int>>& matrix) {
		int res = INT_MAX;
		if (matrix[K][N] != 0) return matrix[K][N];  //����¼�����ظ�����
		//base case
		if (N == 0) return 0;
		if (K == 1) return N;
		//״̬ת��
		for (int i = 1; i <= N; i++) {
			res = min(res,
				max(helper2(K, N - i,matrix ), helper2(K - 1, i - 1, matrix)) + 1);  //������ȥ���ߴ�ֵ������i��ˤһ��
		}
		matrix[K][N] = res; //���±���¼
		return res;
	}
};

//��̬�滮+����¼+��������
class Solution {
public:
	int superEggDrop(int K, int N) {
		vector<vector<int>> matrix(K + 1, vector<int>(N + 1));
		return helperBinarySearch(K, N, matrix);
	}
	int helperBinarySearch(int K, int N, vector<vector<int>>& matrix) {
		int res = INT_MAX;
		if (matrix[K][N] != 0) return matrix[K][N];  //����¼�����ظ�����
		//base case
		if (N == 0) return 0;
		if (K == 1) return N;
		//���������ҵ���Сֵ
		int lo = 1, hi = N;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			int notBroken = helperBinarySearch(K, N - mid, matrix);
			int broken = helperBinarySearch(K - 1, mid - 1, matrix);
			if (notBroken >= broken) {
				lo = mid + 1;
				res = min(res, notBroken + 1);
			}
			else {
				hi = mid - 1;
				res = min(res, broken + 1);
			}
		}
		matrix[K][N] = res; //���±���¼
		return res;
	}
};