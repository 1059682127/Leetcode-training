
/*
53. 最大子序和



给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例:
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:
如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/

class Solution {
public:
	//一次遍历，进行值更新
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		if (len <= 0) return 0;
		int sumCur = nums[0];
		int Max = nums[0];
		for (int i = 1; i < len; ++i) {
			sumCur = sumCur > 0 ? sumCur + nums[i] : nums[i];  //根据之前的总和
			Max = max(Max, sumCur);
		}
		return Max;
	}
};