/*
题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

class Solution {
public:
	//用递归
	//f(n) = f(n - 1) + n
	//f(1) = 1
	//考虑A&&B,如果A==0,则B不用执行
	int Sum_Solution(int n) {
		int sum = n;
		n && (sum += Sum_Solution(n - 1));
		return sum;
	}
};