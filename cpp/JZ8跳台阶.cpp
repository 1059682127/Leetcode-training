/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

class Solution {
public:
	//动态规划：跳上n级台阶等于n - 1级 + 1, n - 2级 + 2
	int jumpFloor(int number) {
		if (number < 0) return 0;
		int pre = 1, prepre = 1;
		int res = 1;
		for (int i = 2; i <= number; ++i) {
			res = pre + prepre;
			prepre = pre;
			pre = res;
		}
		return res;
	}
};