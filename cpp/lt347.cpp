//lt347

/*
 前 K 个高频元素

给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:
输入: nums = [1], k = 1
输出: [1]
说明：
你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

//思路1：用哈希表记录次数，用大顶堆记录频率,
*/


//执行用时:20 ms, 在所有 C++ 提交中击败了86.03%的用户
//内存消耗 :11.6 MB, 在所有 C++ 提交中击败了13.19%的用户
class Solution {
public:
	//思路1：用哈希表记录次数，用大顶堆记录频率,

	//Trick1:堆怎么既记录频率，又记录对应的数，使用序偶结构<x,y>
	//Trick2:堆中定义比较函数comp
	//知识点：
	//1、定义使用pair的vector:vector<pair<int, int>> ivec_p;
	//2、向该vector插入pair:ivec_p.push_back(make_pair<int, int>(x, y));
	//3、访问元素的值：vector<pair<int, int>>::iterator it; it->first;
	//4、pop_heap() 函数将第一个元素移到最后，并保证剩下的元素仍然是一个堆。！！！不是移除
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> hash_table;
		for (auto& num : nums) {
			hash_table[num]++;
		}
		using value_v = pair<int, int>;
		vector<value_v> container(hash_table.begin(), hash_table.end());
		auto comp = [](const value_v& v1, const value_v& v2) {return v1.second < v2.second; };
		make_heap(container.begin(), container.end(), comp);

		vector<int> res;
		for (int i = 0; i < k; i++) {
			res.push_back(container.begin()->first);
			pop_heap(container.begin(), container.end() - i, comp);  //需要用相同的比较函数
		}

		return res;
	}
};