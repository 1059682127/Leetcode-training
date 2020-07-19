/*
题目描述
统计一个数字在排序数组中出现的次数。
*/

class Solution {
public:
	//二分法
	int lower_bound(vector<int> &data, int k) {
		int lo = 0, hi = data.size() - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			//>k, 左边继续， = k， 左边继续， < k ,右边
			if (data[mid] < k) lo = mid + 1;
			else hi = mid - 1;
		}
		return lo;
	}
	int higher_bound(vector<int> &data, int k) {
		int lo = 0, hi = data.size() - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			//>k, 左边继续， = k， 右边继续， < k ,右边
			if (data[mid] <= k) lo = mid + 1;
			else hi = mid - 1;
		}
		return lo;
	}
	int GetNumberOfK(vector<int> data, int k) {
		//二分法找到左端点
		int l = lower_bound(data, k);
		int r = higher_bound(data, k);
		return r - l;
	}
};