/*
题目描述
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
*/

class Solution {
public:
	//递推，找规律：
	//每个位只管自己为1时，出现的次数
	//分high, cur, low
	//cur = 0时，出现high * digit
	//cur = 1时，出现high * gigit + low + 1
	//cur > 1时，出现(high + 1) * digit
	//初始化：high = n / 10, cur = n % 10, low = 0, digit = 1
	int NumberOf1Between1AndN_Solution(int n)
	{
		int res = 0, digit = 1, low = 0;
		int high = n / 10, cur = n % 10;
		while (high != 0 || cur != 0) {
			if (cur == 0) res += high * digit;
			else if (cur == 1) res += high * digit + low + 1;
			else res += (high + 1) * digit;
			low += cur * digit;
			cur = high % 10;
			high /= 10;
			digit *= 10;
		}
		return res;
	}
};