//lt344

/*
反转字符串

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

示例 1：
输入：["h","e","l","l","o"]
输出：["o","l","l","e","h"]
示例 2：
输入：["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]

思路：
1、双指针O(N)/O(1)
2、递归O(N)/O(N)
*/


反转字符串

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
 
示例 1：
输入：["h","e","l","l","o"]
输出：["o","l","l","e","h"]
示例 2：
输入：["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]



//思路1：双指针
class Solution {
public:
	//思路：双指针
	void reverseString(vector<char>& s) {
		int lo = 0;
		int hi = s.size() - 1;
		while (lo < hi) {
			int temp = s[lo];
			s[lo++] = s[hi];
			s[hi--] = temp;
		}
		return;
	}
};

//执行用时 :88 ms, 在所有 C++ 提交中击败了13.23%的用户
//内存消耗 :16.4 MB, 在所有 C++ 提交中击败了5.02%的用户
//思路2：递归
class Solution {
public:
	//思路：递归
	void reverseString(vector<char>& s) {
		helper(s, 0, s.size() - 1);
		return;
	}
	void helper(vector<char>& s, int lo, int hi) {

		if (lo < hi) {
			int temp = s[lo];
			s[lo++] = s[hi];
			s[hi--] = temp;
			helper(s, lo, hi);
		}

	}
};