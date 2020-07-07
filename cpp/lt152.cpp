//lt152

/*
乘积最大子序列

给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
示例 1:
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

思路：
1、动态规划O(N)/O(N)
2、直接所有数字相乘，考虑负数的个数（偶数个就是直接相乘，奇数个分两种：不包含第一个负数的子数组/不包含最后一个负数的子数组）
参加：https://leetcode-cn.com/problems/maximum-product-subarray/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--36/
*/

//思路1：动态规划
class Solution {
public:
	//思路：动态规划
	//遍历数组不断更新最大组
	//当前最大值imax = max(imax*nums[i], imax);
	//由于负数的存在，会使最小的变为最大的，最大的变为最小的，因此还要维护imin，imin = min(imin*nums[i], imin);
	//当出现负数时，imax,imin交换进行下一步运算
	int maxProduct(vector<int>& nums) {
		int Max = INT_MIN, imax = 1, imin = 1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] < 0) {
				int temp = imax;
				imax = imin;
				imin = temp;

			}
			//更新值
			imax = max(imax * nums[i], nums[i]);
			imin = min(imin * nums[i], nums[i]);
			Max = max(imax, Max);
		}
		return Max;
	}

};

//思路2：直接相乘
class Solution {
public:
	//思路：直接相乘,分别从头和从尾乘一次
	int maxProduct(vector<int>& nums) {
		int res = INT_MIN;
		//从头乘一次
		int MaxL = 1;
		for (int i = 0; i < nums.size(); i++) {
			MaxL = MaxL * nums[i];
			res = max(res, MaxL);
			//考虑0的情况
			if (MaxL == 0) MaxL = 1;
		}
		int MaxR = 1;
		for (int i = nums.size() - 1; i >= 0; i--) {
			MaxR = MaxR * nums[i];
			res = max(res, MaxR);
			if (MaxR == 0) MaxR = 1;
		}
		return res;
	}

};