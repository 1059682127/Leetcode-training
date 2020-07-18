/*
��Ŀ����
��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0����1����1����
n<=39
*/

class Solution {
public:
	//dp����
	int Fibonacci(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		vector<int> dp(n + 1);
		dp[0] = 0, dp[1] = 1;
		for (int i = 2; i <= n; ++i) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
};