//lt239

/*
滑动窗口最大值

给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回滑动窗口中的最大值。

示例:
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7]
解释:

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


 //思路1:暴力法，遍历0~i-k 0(nk)/O(n - k + 1)
 //思路2:双端队列/单调队列


*/

//执行用时:156 ms, 在所有 C++ 提交中击败了10.58%的用户
//内存消耗 :14 MB, 在所有 C++ 提交中击败了15.61%的用户
class Solution {
public:
	//思路1:暴力法，遍历0~i-k 0(nk)/O(n - k + 1)
	//思路2：
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int len = nums.size();
		if (len == 0) return nums;
		vector<int> res;
		for (int i = 0; i <= len - k; i++) {
			int Max = nums[i];
			for (int j = 1; j < k; j++) {
				Max = (nums[i + j] > Max) ? nums[i + j] : Max;
			}
			res.push_back(Max);
		}
		return res;
	}
};

//执行用时:28 ms, 在所有 C++ 提交中击败了79.28%的用户
//内存消耗 :14.1 MB, 在所有 C++ 提交中击败了14.97%的用户
class Solution {
public:
	//思路2:双端队列/单调队列
	//可以使用堆保存最大值，但是怎么去掉不在滑动窗口范围内的元素？？？使用双端队列
	//https://leetcode-cn.com/problems/sliding-window-maximum/solution/shuang-xiang-dui-lie-jie-jue-hua-dong-chuang-kou-z/
	//用双端队列可以轻松实现对首元素的O(1)访问，用首元素保存窗口最大元素的下标，队列保持单调递减
	//插入元素：每次新添加元素时，去掉队尾比nums[i]小的，直到队尾比nums[i],再添加num[i]
	//最大元素：每次窗口移动,先检查最大元素是否还在窗口范围内，不在则window.pop_front();不管怎样，最后最大值在window.front()
	//O(N)/O(N)每个元素被处理两次（插入和删除），输出数组使用O(N - K + 1),双向队列使用O(K)

	//知识点：
	//插入：window.push_back()
	//弹出首元素：window.pop_front();
	//弹出尾元素：window.pop_back()
	//取得首元素的值：window.front();
	//取得尾元素的值：window.back()
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int len = nums.size();
		if (len == 0) return nums;
		vector<int> res;
		deque<int> window;
		//初始化deque
		for (int i = 0; i < k; i++) {
			while (!window.empty() && nums[window.back()] <= nums[i]) window.pop_back();
			window.push_back(i);
		}
		res.push_back(nums[window.front()]);
		//进行滑动更新(i为当前元素)
		for (int i = k; i < len; i++) {
			if (!window.empty() && window.front() < i - k + 1) window.pop_front();
			while (!window.empty() && nums[window.back()] <= nums[i]) window.pop_back();

			window.push_back(i);
			res.push_back(nums[window.front()]);
		}
		return res;
	}
};