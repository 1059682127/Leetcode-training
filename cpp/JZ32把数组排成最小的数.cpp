/*
题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

class Solution {
public:
	//排序，从小到大，然后串在一起
	//比较函数：s1 + s2 < s2 + s1, 则s1 < s2
	static bool comp(string s1, string s2) {
		string temp1 = s1 + s2;
		string temp2 = s2 + s1;
		return temp1.compare(temp2) < 0;
	}
	string PrintMinNumber(vector<int> numbers) {
		int len = numbers.size();
		stringstream sst;
		vector<string> ss(len);
		for (int i = 0; i < len; ++i) {
			sst << numbers[i];
			sst >> ss[i];
			sst.clear();
		}
		sort(ss.begin(), ss.end(), comp);
		string res;
		for (auto s : ss) res += s;
		return res;
	}
};