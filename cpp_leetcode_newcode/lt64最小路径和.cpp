/*
64. 最小路径和



给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。
示例:
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
*/


class Solution {
public:
	//动态规划：第一行都为1，第一列都为1，
	//dp[j] = min(dp[j], dp[j - 1]);
	//return dp[j]
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0) return 0;
		int m = grid.size();
		int n = grid[0].size();
		vector<int> dp(n);
		//base case
		dp[0] = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				//先j, 避免出现dp[-1]
				if (j == 0) dp[j] = dp[j];
				else if (i == 0) dp[j] = dp[j - 1];
				else dp[j] = min(dp[j], dp[j - 1]);
				dp[j] += grid[i][j];
			}
		}
		return dp[n - 1];
	}
};