/*
题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。
*/

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		if (array.empty()) return vector<int>();
		int tmp = INT_MAX;
		pair<int, int> ret;
		unordered_map<int, int> mp;
		for (int i = 0; i < array.size(); ++i) {
			mp[array[i]] = i;
		}
		for (int i = 0; i < array.size(); ++i) {
			if (mp.find(sum - array[i]) != mp.end()) {
				int j = mp[sum - array[i]];
				if (j > i && array[i] * array[j] < tmp) {
					tmp = array[i] * array[j];
					ret = { i, j };
				}
			}
		}
		if (ret.first == ret.second) return vector<int>();
		return vector<int>({ array[ret.first], array[ret.second] });

	}
};