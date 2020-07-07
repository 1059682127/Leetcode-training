//lt387

/*
 字符串中的第一个唯一字符

给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
案例:
s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.

注意事项：您可以假定该字符串只包含小写字母。

思路：
1、用哈希表记录次数，然后从头遍历字符串，找到第一个为次数为1的字符O(n)/O(1)
*/


class Solution {
public:
	//思路：用哈希表记录次数，然后从头遍历字符串，找到第一个为次数为1的字符
	int firstUniqChar(string s) {
		vector<int> a(26);
		for (int i = 0; i < s.size(); i++) {
			a[s[i] - 'a']++;
		}
		for (int i = 0; i < s.size(); i++) {
			if (a[s[i] - 'a'] == 1) return i;
		}
		return -1;
	}
};