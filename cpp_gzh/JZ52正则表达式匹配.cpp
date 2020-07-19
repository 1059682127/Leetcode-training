/*
正则表达式匹配

题目描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

class Solution {
public:
	//递归
	bool match(char* str, char* pattern)
	{
		//如果s, p都遍历完了
		if (*str == '\0' && *pattern == '\0') return true;
		//如果s没完，p完了，false
		if (*pattern == '\0') return false;
		//如果有*
		if (*(pattern + 1) != '*') {
			if (*str != '\0' && (*str == *pattern || *pattern == '.')) return match(str + 1, pattern + 1);
			else return false;
		}
		else {
			//重复一次或者多次
			bool ret = false;
			if (*str != '\0' && (*str == *pattern || *pattern == '.'))
				ret = match(str + 1, pattern);
			//重复0次
			return ret || match(str, pattern + 2);
		}
	}
};