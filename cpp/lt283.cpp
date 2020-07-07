//lt283

/*
移动零

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
示例:
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:
必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。


//思路1、双指针，遍历数组，将非零数往前移，再补充剩余空间O(N)/O(1)

*/

class Solution {
public:
	//双指针，遍历数组，将非零数往前移，再补充剩余空间
	void moveZeroes(vector<int>& nums) {
		int i = 0;
		for (int j = 0; j < nums.size(); j++) {
			if (nums[j] != 0) {
				nums[i] = nums[j];
				i++;
			}
		}
		for (int k = i; k < nums.size(); k++) {
			nums[k] = 0;
		}
	}
};