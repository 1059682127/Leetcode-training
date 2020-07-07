//lt215

/*
数组中的第K个最大元素

在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
示例 1:
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:
你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。


//思路1：sort,从大到小遍第四个数O(nlogn)/O(1)
//思路2:小顶堆，保持大小为k，最后堆顶为答案O(NlogK)/O(K)
*/

//执行用时:20 ms, 在所有 C++ 提交中击败了39.86%的用户
//内存消耗 :9.4 MB, 在所有 C++ 提交中击败了34.30%的用户
class Solution {
public:
	//思路1：sort,从大到小遍第四个数O(nlogn)/O(1)
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}
};


class Solution {
public:
	//思路2:小顶堆，保持大小为k，最后堆顶为答案
	//每次添加新元素，添加后重排，若大小>k, 弹出堆顶
	//结果：堆顶
	//像大小为 k 的堆中添加元素的时间复杂度为 O(log⁡k)，我们将重复该操作 N 次，故总时间复杂度为 O(Nlog⁡k)。
	//Ttick1:使用STL优先级队列priority_queue<int, vector<int>, greate<int> >q;添加元素之后自动排序

	//知识点：创建小顶堆：priority_queue<int, vector<int>, greater<int> >q;
	//创建大顶堆：priority_queue <int,vector<int>,less<int> >q;
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int> >q;
		for (auto& num : nums) {
			q.push(num);
			if (q.size() > k) q.pop();
		}
		return q.top();
	}
};

