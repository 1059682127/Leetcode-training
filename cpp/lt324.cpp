//lt324

/*
摆动排序 II

给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。
示例 1:
输入: nums = [1, 5, 1, 1, 6, 4]
输出: 一个可能的答案是 [1, 4, 1, 5, 1, 6]
示例 2:
输入: nums = [1, 3, 2, 2, 3, 1]
输出: 一个可能的答案是 [2, 3, 1, 3, 1, 2]
说明:
你可以假设所有输入都会得到有效的结果。
进阶:
你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？

//思路1：排序+中位数O(NlogN)/O(N)
//思路2：快速选择 + 3-way-partition O(N)/O(N)
*/



class Solution {
public:
	//执行用时 :20 ms, 在所有 C++ 提交中击败了95.62%的用户
	//内存消耗 :19.2 MB, 在所有 C++ 提交中击败了5.17%的用户
	//思路1：排序+中位数O(NlogN)/O(N)
	//分两段（长度相等或者前面多1个），将前面数组最后一个元素排在原数组最后一个元素，将后面数组最后一个元素放在原数组第二个元素。。。  
	//left0 left1 right0 right1(left1 == right0)
	//Trick1:交叉存的时候倒着存，可以保证 left1 < right1 left0 right0(这种情况可以使中间的数分割两端)...但是如果交叉的时候正着存：left0 < right0 >= left1 < right1（这种情况可能使中间的数在一起）
	void wiggleSort(vector<int>& nums) {
		//边界条件
		//排序
		vector<int> temp(nums);
		sort(temp.begin(), temp.end());
		//合并
		int low = 0, high = temp.size() - 1;
		int mid = (low + high) / 2;
		int right = mid + 1;
		for (int i = 0; i < temp.size(); ++i) {
			nums[i] = (i % 2 == 0) ? temp[mid--] : temp[high--];  //如果是偶数下标，取左边；奇数下标，取右边
		}
	}
};