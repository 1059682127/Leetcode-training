//lt315

/*
计算右侧小于当前元素的个数

给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
示例:
输入: [5,2,6,1]
输出: [2,1,1,0]
解释:
5 的右侧有 2 个更小的元素 (2 和 1).
2 的右侧仅有 1 个更小的元素 (1).
6 的右侧有 1 个更小的元素 (1).
1 的右侧有 0 个更小的元素.

//思路1：循环遍历0(N^2)/O(1)
//思路2：归并排序+索引数组O(NlogN)/O(N)
*/




class Solution {
public:
	//思路1：循环遍历0(N^2)/O(1)
	//思路2：归并排序+索引数组
	//参考“逆序对”实现思路，归并排序完成之后，原数组的逆序数也就出来了
	//前有序数组，右有序数组，求前有序数组的元素的右边有多少元素比自己小，那么应该统计该元素出列之前，右有序数组已经出列的个数（因为这些已经出列的元素都小于等于当前元素）
	//其实主体就是归并排序的过程，但是归并子例程中前有序数组出列的时候要累计数量

	//归并操作完成后，原数组的位置已经发生变化，如何定位元素是关键？？？
	//Trick1:使用索引数组，好处是在“索引数组进行归并的时候”，可以清楚的直到这个元素在原数组的索引是多少
	//Trick2:使用索引数组长度的临时数组，把索引数组的值复制过去，双指针排序完之后就复制回去
	//Trick3:分治分划分和解决，在解决的时候，前有序数组出列的时候，马上可以统计右边比自己小的元素个数
	//Trick4:如果前有序数组的最大元素小于右边的最小元素，不用归并

	vector<int> count;  //保存结果
	vector<int> index;  //索引数组
	vector<int> helper; //临时数组，用于复制操作
	vector<int> countSmaller(vector<int>& nums) {
		//边界条件
		int len = nums.size();
		if (len == 0) return {};
		count.resize(len);  //保存结果
		index.resize(len);  //索引数组
		helper.resize(len); //临时数组，用于复制操作

		//索引数组初始化
		for (int i = 0; i < len; ++i) {
			index[i] = i;
			count[i] = 0;
		}

		mergeSort(nums, 0, len - 1);

		return count;
	}
	//划分操作
	void mergeSort(vector<int>& nums, int low, int high) {
		if (low < high) {
			int mid = (low + high) / 2;
			mergeSort(nums, low, mid);
			mergeSort(nums, mid + 1, high);
			merge(nums, low, mid, high);
		}
	}
	//归并操作
	void merge(vector<int>& nums, int low, int mid, int high) {
		int left = low, right = mid + 1, copyIndex = low;
		while (left <= mid && right <= high) {
			//进行指针移动
			if (nums[index[left]] <= nums[index[right]]) {
				//左边元素出列，要计数
				count[index[left]] += right - (mid + 1);  //用+=累计计数
				helper[copyIndex++] = index[left++];
			}
			else {
				helper[copyIndex++] = index[right++];
			}
		}
		while (left <= mid) {
			count[index[left]] += right - (mid + 1);
			helper[copyIndex++] = index[left++];
		}
		while (right <= high) helper[copyIndex++] = index[right++];

		for (int i = low; i <= high; ++i) index[i] = helper[i];
	}
};


