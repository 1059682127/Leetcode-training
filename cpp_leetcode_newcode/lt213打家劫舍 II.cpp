
/*

213. 打家劫舍 II


你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
示例 1:
输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
*/


class Solution {
public:
	//动态规划
	//环形的话，nums[0]选中，则num[i - 1]不能选
	int rob(vector<int>& nums) {
		int len = nums.size();
		if (len <= 0) return 0;
		if (len == 1) return nums[0];
		return max(rob(nums, 0, len - 2), rob(nums, 1, len - 1));
	}
	int rob(vector<int>& nums, int l, int r) {
		int pre = 0, prepre = 0;
		for (int i = l; i <= r; ++i) {
			int cur = max(prepre + nums[i], pre);
			prepre = pre;
			pre = cur;
		}
		return pre;
	}
};