//lt334

/*
 递增的三元子序列

给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。
数学表达式如下:
如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。
说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1) 。
示例 1:
输入: [1,2,3,4,5]
输出: true
示例 2:
输入: [5,4,3,2,1]
输出: false

//思路1：暴力法O(N^3))/O(1)
//（推荐）思路2：双指针，设定small,mid,遍历数组，更新small,mid,找到比mid大的返true O(N)/O(1)
//思路3:动态规划O(N^2)/O(N)
//思路4:前后遍历O(N)/O(N)
*/


//执行用时:320 ms, 在所有 C++ 提交中击败了6.00%的用户
//内存消耗 :9.2 MB, 在所有 C++ 提交中击败了5.34%的用户
class Solution {
public:
	//思路1：暴力法O(N^3))/O(1),不符合O(N)
	bool increasingTriplet(vector<int>& nums) {
		int len = nums.size();
		for (int i = 0; i <= len - 3; i++) {
			for (int j = i + 1; j <= len - 2; j++) {
				if (nums[i] < nums[j]) {
					for (int k = j + 1; k <= len - 1; k++) {
						if (nums[j] < nums[k]) return true;
					}
				}
			}
		}
		return false;
	}
};


class Solution {
public:
	//思路2：双指针，设定small,mid,遍历数组，更新small,mid,找到比mid大的返true
	//Trick1:遇到比small小的要更新，[3,5]遇到1,2，要更新small,防止错过[1,2,3]
	//Trick2:遇到比small大，比mid小的，更新mid（因为如果最小的中间值都得不到解，那么就是false）
	//Trick3:更新之后small和mid的索引不能保证递增，但是隐含mid之前有比small大比mid小的出现，只要后面找到比mid大的即可
	//参考：https://leetcode-cn.com/problems/increasing-triplet-subsequence/solution/c-xian-xing-shi-jian-fu-za-du-xiang-xi-jie-xi-da-b/
	bool increasingTriplet(vector<int>& nums) {
		int len = nums.size();
		if (len < 3) return false;
		int small = INT_MAX, mid = INT_MAX;
		for (auto num : nums) {
			if (num <= small) {
				small = num;
			}
			else if (num <= mid) {
				mid = num;
			}
			else {
				return true;   //找到大于mid，返true
			}
		}
		return false;
	}
};

//执行用时:456 ms, 在所有 C++ 提交中击败了5.18%的用户
//内存消耗 :9.2 MB, 在所有 C++ 提交中击败了5.34%的用户
class Solution {
public:
	//思路3:动态规划O(N^2)/O(N)
	//状态：dp[i],记录0~i-1比当前元素小的个数,初始化为0
	//base sample dp[0] = 0
	//转换：遍历j，if(nums[j] < nums[i]) dp[i] = max(dp[i] + 1, dp[i])
	bool increasingTriplet(vector<int>& nums) {
		int len = nums.size();
		vector<int> dp(len, 0);
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[j] < nums[i]) {
					dp[i] = max(dp[j] + 1, dp[i]);
				}
				if (dp[i] >= 2) return true;
			}
		}
		return false;
	}
};

class Solution {
public:
	//思路4:前后遍历O(N)/O(N)
	//数组forwards[i]记录从[0,i]的最小元素(动态规划)
	//数组backwwards[i]记录从[i,len-1]的最大元素
	//遍历nums[i]，找到forwards[i] < nums[i] < backwards[i]元素


	//技巧：(forwards[j] < nums[j] && nums[j] < backwards[j])不等同与(forwards[j] < nums[j] < backwards[j])
	bool increasingTriplet(vector<int>& nums) {
		int len = nums.size();
		if (len < 3) return false;
		vector<int> forwards(len);
		vector<int> backwards(len);
		forwards[0] = nums[0];
		backwards[len - 1] = nums[len - 1];
		for (int i = 1; i < len; i++) {
			forwards[i] = min(nums[i], forwards[i - 1]);
		}
		for (int j = len - 2; j >= 0; j--) {
			backwards[j] = max(nums[j], backwards[j + 1]);
			if (forwards[j] < nums[j] && nums[j] < backwards[j]) return true;
		}
		return false;
	}
};