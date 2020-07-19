/*
表示数值的字符串

题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/

class Solution {
public:
	//+-号后面必定为数字或后面为.（-.123 = -0.123） 
	//+-号只出现在第一位或在eE的后一位 
	//.后面必定为数字或为最后一位（233. = 233.0） 
	//eE后面必定为数字或+-号
	bool isNumeric(char* str)
	{
		int len = strlen(str);
		bool point = false, exp = false;  //标志小数点和指数位,不能连续出现小数位和指数位
		for (int i = 0; i < len; ++i) {
			if (str[i] == '+' || str[i] == '-') {
				if (i + 1 == len || !(str[i + 1] >= '0' && str[i + 1] <= '9' || str[i + 1] == '.')) {
					cout << 1;
					return false;
				}
				if (!(i == 0 || str[i - 1] == 'e' || str[i - 1] == 'E')) {
					cout << 1;
					return false;
				}
			}
			else if (str[i] == '.') {
				if (point || exp || !(i + 1 < len && str[i + 1] >= '0' && str[i + 1] <= '9')) {
					cout << 1;
					return false;
				}
				point = true;  //记录已有小数位
			}
			else if (str[i] == 'e' || str[i] == 'E') {
				if (exp || i + 1 == len || !(str[i + 1] >= '0' && str[i + 1] <= '9' || str[i + 1] == '+' || str[i + 1] == '-')) {
					cout << 1;
					return false;
				}
				exp = true;
			}
			else if (str[i] >= '0' && str[i] <= '9') {}
			else return false;
		}
		return true;
	}

};