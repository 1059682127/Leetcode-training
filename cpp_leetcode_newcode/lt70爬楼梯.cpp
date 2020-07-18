/*
70. 爬楼梯


假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。
示例 1：
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
*/

class Solution {
public:
	//动态规划：dp[i] = dp[i - 1] + dp[i - 2]
	int climbStairs(int n) {
		if (n <= 0) return 0;
		if (n == 1) return n;
		int pre = 1, prepre = 1;
		for (int i = 2; i <= n; ++i) {
			int cur = pre + prepre;
			prepre = pre;
			pre = cur;
		}
		return pre;
	}
};