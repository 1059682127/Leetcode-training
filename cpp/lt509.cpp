//lt509

/*
쳲�������
쳲���������ͨ���� F(n) ��ʾ���γɵ����г�Ϊ쳲��������С��������� 0 �� 1 ��ʼ�������ÿһ�����ֶ���ǰ���������ֵĺ͡�Ҳ���ǣ�

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), ���� N > 1.


���� N������ F(N)��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/fibonacci-number
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


class Solution {
public:
	//ʹ�õݹ�
	int fib(int N) {
		if (N < 2) {
			return N == 0 ? 0 : 1;
		}
		return fib(N - 1) + fib(N - 2);
	}
};


class Solution {
public:
	//ʹ�ô�����¼�ĵݹ�
	//O(N)/O(N):���������N�����������O(1)
	int dfs(int i, vector<int> &memo) {
		if (memo[i] != 0) return memo[i];
		if (i == 0) return 0;
		if (i == 1) return 1;
		memo[i] = dfs(i - 1, memo) + dfs(i - 2, memo);
		return memo[i];
	}
	int fib(int N) {
		if (N < 1) return 0;
		vector<int> memo(N + 1, 0);
		return dfs(N, memo);
	}
};

class Solution {
public:
	//dp
	int fib(int N) {
		if (N < 1) return 0;
		vector<int> dp(N + 1, 0);
		dp[0] = 0, dp[1] = 1;
		//��С����
		for (int i = 2; i <= N; ++i) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[N];
	}
};