/*
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
n<=39
*/

class Solution {
public:
	//dp数组
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