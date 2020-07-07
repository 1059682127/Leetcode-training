//lt179

/*
最大数

给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
示例 1:
输入: [10,2]
输出: 210
示例 2:
输入: [3,30,34,5,9]
输出: 9534330
*/


class Solution {
public:
	//思路：1、自定义比较方式，再调用sort，降序
	//排序的比较算法应该是对组合后的数字进行比较,比如：4跟30，430 > 304，所以4在前面
	//计算组合数的方式：交叉相乘再相加 (a * (b 的位数) + b) ，实现将两个数字组合到一起

	//知识点：int转字符串to_string(int)
	//超过int范围，采用long long 
	//f_sort2用字符串比较规避范围问题
	string largestNumber(vector<int>& nums) {
		auto f_sort = [](const int &a, const int &b) {
			long long n_a = 10, n_b = 10;
			while (a / n_a) n_a *= 10;
			while (b / n_b) n_b *= 10;
			long long l_a = (long long)a * n_b + (long long)b;
			long long l_b = (long long)b * n_a + (long long)a;
			return l_a > l_b;
		};

		auto f_sort2 = [](const int &a, const int &b) {
			string sa = to_string(a);
			string sb = to_string(b);
			return sa + sb > sb + sa;
		};
		sort(nums.begin(), nums.end(), f_sort);
		string res;
		for (int i = 0; i < nums.size(); ++i) {
			res = (res == "0") ? to_string(nums[i]) : res += to_string(nums[i]);  //需要考虑["0", "0"]特殊情况
		}
		return res;
	}

};