///lt28

/*
28. 实现 strStr()

实现 strStr() 函数。
给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1

//思路1：最坏的情况是O(M-N+1)*N
*/

class Solution {
public:
	//思路1：遍历
	int strStr(string haystack, string needle) {
		int len1 = haystack.size();
		int len2 = needle.size();
		if (len1 < len2) return -1;
		if (len1 == 0 || len2 == 0) return 0;
		bool match;
		for (int i = 0; i + len2 - 1 < len1; ++i) {
			match = true;
			for (int j = 0; j < len2; ++j) {
				if (haystack[i + j] != needle[j]) {
					match = false;
					break;
				}

			}
			if (match) return i;
		}
		return -1;
	}
};