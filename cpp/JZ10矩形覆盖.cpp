/*
题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

比如n=3时，2*3的矩形块有3种覆盖方法：
*/

class Solution {
public:
	//动态规划：f(1) = 1
	//f(n) = f(n - 1,左边两个) + f(n - 2, 右边)
	int rectCover(int number) {

		vector<int> dp(number + 1);
		dp[0] = 0;
		dp[1] = 1, dp[2] = 2;
		for (int i = 3; i <= number; ++i) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[number];
	}
};