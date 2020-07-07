/*
lt300

300. 最长上升子序列
难度
中等

666





给定一个无序的整数数组，找到其中最长上升子序列的长度。
示例:
输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:
可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?


*/
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		//数组
		int len  = nums.size();
		if (len  < 1) return 0;
		if (len  == 1) return 1;
		vector<int> dp(len, 1);  //dp[i]是以nums[i]结尾的最长递增子序列的个数
		//base case
		dp[0] = 1;
		for (int i  = 1; i  < len; ++i ) {
			for (int j  = 0; j  < i; ++j ) {
				if (nums[j] < nums[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			cout  << dp[i] << endl;
		}
		//找出其中最大的
		int res  = 0;
		for (int i  = 0; i  < len; ++i) {
			res  = max(res, dp[i]);
		}
		return res;
	}
};