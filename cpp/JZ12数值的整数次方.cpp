/*
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

保证base和exponent不同时为0
*/

class Solution {
public:
	double Power(double base, int exponent) {
		double res = base;
		if (exponent == 0) return 1;
		if (base == 0) return 0;
		int neg = false;
		if (exponent < 0) {
			neg = true;
			exponent = -exponent;
		}
		while (exponent / 2) {
			res = res * res;
			exponent /= 2;
		}
		if (exponent == 1) res *= base;
		if (neg) res = 1 / res;
		return res;
	}
};