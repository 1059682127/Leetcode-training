//lt322

/*
322. 零钱兑换
难度
中等

给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:
输入: coins = [1, 2, 5], amount = 11
输出: 3
解释: 11 = 5 + 5 + 1
示例 2:
输入: coins = [2], amount = 3
输出: -1
*/

class Solution {
public:
	//dp:O(kn)/O(N)
	int coinChange(vector<int>& coins, int amount) {
		//memo，初始化为amount + 1,相当于无穷大
		vector<int> dp(amount + 1, amount + 1);
		//base case
		dp[0] = 0;
		for (int i = 1; i <= amount; ++i) {
			//子问题求解,状态转移方程
			for (auto coin : coins) {
				if (i - coin < 0) continue; //不存在
				dp[i] = min(dp[i], 1 + dp[i - coin]);
			}
		}
		return dp[amount] == amount + 1 ? -1 : dp[amount];
	}
};