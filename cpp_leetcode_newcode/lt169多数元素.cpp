//lt169

/*
题目描述：
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ? n/2 ? 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
示例 1:
输入: [3,2,3]
输出: 3
示例 2:
输入: [2,2,1,1,1,2,2]
输出: 2

思路：
1、遍历nums,使用hash_table,记录不同元素出现的次数，返回value>? n/2 ?的key, O(N)/O(N)
2、sort一般，取中间元素，O(nlog2n)/O(1)

官方：
1、随机化解法：随机检测一个下标，检查它的值是否为众数
2、分治：不断二分化，再将各自的众数向上汇合，0(nlogn)/O(logn)
3、Boyer-Moore 投票算法：维护一个计数器，众数为1，非众数为-1。
选定一个候选众数，如果计数器为0，就把前面访问的数忘掉（去掉相同的众数和非众数，或者去掉更多的非众数），
总有一个后缀满足计数器是大于 0 的，此时这个后缀的众数就是整个数组的众数。


知识点：
1、向上取整, 运算称为 ceil，用数学符号 ??  （上有起止，开口向下）表示；向下取整, 运算称为 floor，用数学符号 ?? （下有起止，开口向上）表示。
2、unordered_map与map的区别：最主要就是底层结构不同，使用场景不容；
如果需要得到一个有序序列，使用红黑树系列的关联式容器map，如果需要更高的查询效率，使用以哈希表为底层的关联式容器unordered_map
3、分治并每个二分段进行一次线性扫描的时间复杂度为0(nlogn)；
4、由于递归树是平衡的，所以从根到每个叶子节点的长度都是 O(lgn)。由于递归树是深度优先的，空间复杂度等于最长的一条路径，也就是 O(lgn)

*/

class Solution {
public:
	//sort，取中间元素
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];  //不管哪种情况，会在下标为? n/2 ?处，注意是下标，不是第? n/2 ?个
	}

	//哈希表，统计次数，获取数量大于len_half的
	int majorityElement(vector<int>& nums) {
		int len = nums.size();
		int len_half = len / 2;
		int cur;
		map<int, int>a;
		for (int i = 0; i < len; i++) {
			cur = nums[i];
			a[cur]++;
			if (a[cur] > len_half) {
				return cur;
			}
		}
		return -1;
	}
};


//分治
class Solution {
public:
	//采用分治的思想
	int majorityElement(vector<int>& nums) {
		return majorityElemence(nums, 0, nums.size() - 1);
	}
	int majorityElemence(vector<int>& nums, int lower, int upper) {
		//如果是单数，则返回
		if (lower == upper) {
			return nums[lower];
		}
		//获得左右子数组的众数
		int mid = (upper - lower) / 2 + lower;
		int left = majorityElemence(nums, lower, mid);
		int right = majorityElemence(nums, mid + 1, upper);
		//如果左右众数相同
		if (left == right) {
			return left;
		}
		//如果众数不相同，计算两子数组的众数对应的数量
		int leftNum = countNum(nums, lower, mid, left);
		int rightNum = countNum(nums, mid + 1, upper, right);
		return leftNum > rightNum ? left : right;
	}
	int countNum(vector<int>& nums, int lower, int upper, int Number) {
		int Num = 0;
		for (int i = lower; i <= upper; i++) {
			if (nums[i] == Number) Num++;
		}
		return Num;
	}
};

class Solution {
public:
	//采用投票算法
	int majorityElement(vector<int>& nums) {
		int candidate;
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (count == 0) {   //如果为0，忘掉前面的数
				count = 0;     //重置计数器和候选众数
				candidate = nums[i];
			}
			count += (nums[i] == candidate ? 1 : -1);  //更新计数器的值

		}
		return candidate;
	}

};