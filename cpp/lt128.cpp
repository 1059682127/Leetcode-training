//lt128
/*
128. 最长连续序列

给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

//思路1：暴力法（枚举法）
//思路2：排序+遍历
//思路3：哈希表和线性空间的构造
//思路4：动态规划
//思路5：DFS

*/

class Solution {
public:
	//思路1：暴力法（枚举法）
	//序列可能在 nums 数组的任意一个数字开始，我们可以枚举每个数字作为序列的第一个数字，搜索所有的可能性。
	//将 nums 数组中的每一个数字，作为序列第一个数字(如1)，枚举后面的数字（2，3，4），直到有数字在原数组中没出现过（5），更新最大长度为4。
	//O(N^3)/O(1):三层循环，遍历数组获得第一个数字，枚举后面的数，判断是否在原数组中出现

	//思路3：哈希表和线性空间的构造
	//针对思路1暴力法的优化：
	//1、用哈希表存储nums数组中的元素，可以实现O(1)时间访问
	//2、只有num[i] - 1不在哈希表中，num[i]才作为序列第一个数字进行枚举，否则该元素肯定出现在别的元素num[i] - 1开头的序列中
	//时间:O(N)尽管两层嵌套，但是只有num[i] - 1不在哈希表中，才进行枚举
	//空间:O(N)哈希表分配了线性空间

	int longestConsecutive(vector<int>& nums) {
		//思路3：哈希表和线性空间的构造
		//unordered_set时间插入，查找时间为O(1)
		int len = nums.size();
		int maxL = 0;
		if (len <= 1) return len;
		unordered_set<int> s(nums.begin(), nums.end());
		for (auto num : s) {   //不能传引用
			if (!s.count(num - 1)) {
				//以num为序列开头
				int size = 1;
				while (s.count(++num)) {
					++size;
				}
				if (size > maxL) maxL = size;
			}
		}
		return maxL;
	}
};

class Solution {
public:
	//思路2：排序+遍历
	//数组进行排序，然后从头遍历，记录当前连续串长度，如果连续串中断，则比较是否为当前最长连续串，并且把当前串长度置0
	//如果问题是最长连续序列的所有情况，如果当前连续串长度<maxL, 不添加；如果>maxL,先clear再添加，==maxL,则添加该情况
	//0(nlog)/O(1):排序时间0(nlog)+遍历时间O(n)
	//Trick1:(重复性问题)如果当前数字和前一个数字相等，那么我们当前的序列既不会增长也不会中断，我们只需要继续考虑下一个数字。
	int longestConsecutive(vector<int>& nums) {
		//思路2：排序+遍历
		int len = nums.size();
		if (len <= 1) return len;
		sort(nums.begin(), nums.end());
		int maxL = 0;
		int size = 1;
		for (int i = 0; i < len - 1; ++i) {
			if (nums[i] + 1 == nums[i + 1]) {
				++size;
				continue;
			}
			if (nums[i] == nums[i + 1]) continue;
			else {
				//到末尾了
				if (size > maxL) maxL = size;
				size = 1;
			}
		}
		if (size > maxL) maxL = size;
		return maxL;
	}
};


class Solution {
public:

	//思路4：动态规划
	//本质上就是把连续的序列进行合并，思路就是考虑我们先解决了小问题，然后大问题怎么解决。
	//用一个 HashMap ，存储以当前 key 为边界的连续序列的长度，如已知123，56序列，存储(1,3),(3,3),(5,2)(6,3)
	//当添加一个新元素4，如果不在哈希表中，则考虑其左右元素2,3(以2结束的最长序列，以3开头的最长序列)，得最长序列长度为2+1+3 = 6，更新边界的连续序列长度(2,6),(6,6);若果左右元素不在哈希表中，则这个长度是 0
	//Trick1:将当前数字放到 map 中，防止重复考虑数字，value 可以随便给一个值

	int longestConsecutive(vector<int>& nums) {
		//思路4：动态规划
		//unordered_set时间插入，查找时间为O(1)
		int len = nums.size();
		int maxL = 0;
		if (len <= 1) return len;
		unordered_map<int, int> hash_table;
		for (auto num : nums) {
			if (!hash_table.count(num)) {
				int left = (hash_table.count(num - 1)) ? hash_table[num - 1] : 0;
				int right = (hash_table.count(num + 1)) ? hash_table[num + 1] : 0;
				int size = left + 1 + right;
				//注意更新的先后顺序
				hash_table[num] = -1;  //在中间，肯定不是最长的，不用再访问了
				hash_table[num + right] = size;
				hash_table[num - left] = size;

				if (size > maxL) maxL = size;
			}
		}
		return maxL;

	}
};

class Solution {
public:
	//思路5：DFS
	//看作是无向图，求最长路径（包含顶点的最长路径，并更新maxL）

	//其实就是类似于二叉树中的最大路径和
	//包含某顶点的最长路径长度 = 左路径长度 + 1 + 右路径长度
	//从某顶点开始的最长路径长度（不包含顶点）:递归直到左右分支不存在(类似于求树的最大深度，自底向上递归)

	//Trick1:把用过的数字从集合中移除（因为连续的关系，一个数字不会出现在两个串中）最后比较当前串是不是比当前最大串要长，是则更新。多次DFS直到集合为空。
	//Trick2:用unoredered_set存储数字，既可以去重，又可以常数时间访问
	int maxL;
	int longestConsecutive(vector<int>& nums) {
		int len = nums.size();
		maxL = 0;
		if (len <= 1) return len;
		unordered_set<int> s(nums.begin(), nums.end());
		//进行多次DFS，直到图遍历完毕
		while (!s.empty()) {
			//取第一个元素作为DFS起点
			int start = *s.begin();
			DFS(start, s);
		}
		return maxL;

	}
	//包含某顶点的最长路径长度 = 左路径长度 + 1 + 右路径长度
	//从某顶点开始的最长路径长度（不包含顶点）:递归直到左右分支不存在(类似于求树的最大深度，自底向上递归)
	int DFS(int start, unordered_set<int>& s) {
		if (!s.count(start)) return 0;
		s.erase(start);
		int left = DFS(start - 1, s);
		int right = DFS(start + 1, s);
		//更新最大路径和
		int size = left + right + 1;
		maxL = size > maxL ? size : maxL;
		return max(left, right) + 1;

	}
};