//lt349

/*
349. 两个数组的交集

给定两个数组，编写一个函数来计算它们的交集。
示例 1:
输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:
输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]

//思路1：哈希O(N)/O(N)
//思路2：排序+双指针+set去重0(N)/O(N)
//思路2：排序+双指针(不用set),每次把指针移动到重复元素的最后一个
*/



class Solution {
public:
	//思路1：哈希，用哈希表记录nums1中出现的元素，然后遍历nums2，hash_table[nums2[i]] && find(res.begin(), res.end(), nums[i]) == res.end()
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		map<int, bool> hash_table;
		//边界条件
		for (int i = 0; i < nums1.size(); ++i) {
			hash_table[nums1[i]] = true;
		}
		vector<int> res;
		for (int i = 0; i < nums2.size(); ++i) {
			if (hash_table[nums2[i]] && find(res.begin(), res.end(), nums2[i]) == res.end()) {
				res.push_back(nums2[i]);
			}
		}
		return res;
	}
};

class Solution {
public:
	//思路2：排序+双指针+set去重

	//知识点：
	//set
	//插入：s.insert(1);
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		auto first = nums1.begin(), second = nums2.begin();
		set<int> s;
		while (first < nums1.end() && second < nums2.end()) {
			//进行移动，相等则双指针进行，不等则值小的指针前进
			if (*first == *second) {
				s.insert(*second);
				++first;
				++second;

			}
			else if (*first < *second) {
				++first;
			}
			else {
				++second;
			}
		}
		vector<int> res(s.begin(), s.end());
		return res;
	}
};


class Solution {
public:
	//思路2：排序+双指针

	//知识点：
	//set
	//插入：s.insert(1);
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		auto first = nums1.begin(), second = nums2.begin();
		vector<int> res;
		while (first < nums1.end() && second < nums2.end()) {
			//进行移动，相等则双指针进行，不等则值小的指针前进
			int cur1 = *first;
			int cur2 = *second;
			//如果存在后一个元素，且重复，则指针循环移动
			while (first + 1 < nums1.end()) {
				if (*(first + 1) == cur1) ++first;
				else break;
			}
			while (second + 1 < nums2.end()) {
				if (*(second + 1) == cur2) ++second;
				else break;
			}
			if (*first == *second) {
				res.push_back(*second);
				++first;
				++second;
			}
			else if (*first < *second) {
				++first;
			}
			else {
				++second;
			}
		}
		return res;
	}
};