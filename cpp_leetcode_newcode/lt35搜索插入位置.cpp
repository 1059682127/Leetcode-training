//lt35

/*
35. 搜索插入位置

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2


示例 2:

输入: [1,3,5,6], 2
输出: 1


示例 3:

输入: [1,3,5,6], 7
输出: 4

//思路1：二分查找O(logN)/O(logN)
//思路2：二分查找(优化边界条件)
//思路3：二分查找（循环）

//Trick：一直分治，有可能出现lo > hi的情况，此时return lo;
*/

class Solution {
public:
	//思路1：二分查找

	int searchInsert(vector<int>& nums, int target) {
		return helper(nums, 0, nums.size() - 1, target);
	}
	int helper(vector<int>& nums, int lo, int hi, int target) {
		//边界条件
	//    if(lo > hi) return hi;
		int mid = (lo + hi) / 2;
		if (nums[mid] == target) return mid;
		//如大于目标，则在左边
		else if (nums[mid] > target) {
			if (mid - 1 < lo) return mid;
			else return helper(nums, lo, mid - 1, target);
		}
		else {
			if (mid + 1 > hi) return mid + 1;
			return helper(nums, mid + 1, hi, target);
		}
	}
};

class Solution {
public:
	//思路2：二分查找(优化边界条件)

	int searchInsert(vector<int>& nums, int target) {
		return helper(nums, 0, nums.size() - 1, target);
	}
	int helper(vector<int>& nums, int lo, int hi, int target) {
		//边界条件
		if (lo > hi) return lo;
		int mid = (lo + hi) / 2;
		if (nums[mid] == target) return mid;
		//如大于目标，则在左边
		else if (nums[mid] > target) {
			return helper(nums, lo, mid - 1, target);
		}
		else {
			return helper(nums, mid + 1, hi, target);
		}
	}
};


class Solution {
public:
	//思路3：二分查找（循环）
	//O(logN)/O(1)

	int searchInsert(vector<int>& nums, int target) {
		int lo = 0;
		int hi = nums.size() - 1;
		//边界条件
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (nums[mid] == target) return mid;
			//如大于目标，则在左边
			else if (nums[mid] > target) {
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
		return lo;   //如果出现lo > hi,返回lo
	}
};