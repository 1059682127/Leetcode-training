/*
题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）
*/

class Solution {
public:
	//思路：哈希表
	int FirstNotRepeatingChar(string str) {
		unordered_map<char, int> map;
		for (int i = 0; i < str.size(); ++i) map[str[i]]++;
		for (int i = 0; i < str.size(); ++i) {
			if (map[str[i]] == 1) return i;
		}
		return -1;
	}
};