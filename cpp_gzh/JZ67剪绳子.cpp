/*
剪绳子

题目描述
给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1，m<=n），每段绳子的长度记为k[1],...,k[m]。请问k[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
输入描述:
输入一个数n，意义见题面。（2 <= n <= 60）
输出描述:
输出答案。
示例1
输入
复制
8
输出
复制
18
*/

class Solution {
public:
	//动态规划：
	//f(n) = max(f(i) * f(n - i)), i = 1...n-1
	int cutRope(int number) {
		if (number < 2) return 0;
		if (number == 2) return 1;
		if (number == 3) return 2;
		vector<int> dp(number + 1, 1);
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;
		for (int i = 4; i <= number; ++i) {
			int Max = 0;
			for (int j = 1; j < i / 2 + 1; ++j) {
				Max = max(Max, dp[j] * dp[i - j]);
			}
			dp[i] = Max;
		}
		return dp[number];
	}
};