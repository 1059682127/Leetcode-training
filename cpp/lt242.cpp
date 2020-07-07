//lt242

/*
有效的字母异位词

给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
示例 1:
输入: s = "anagram", t = "nagaram"
输出: true
示例 2:
输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。
进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

思路：
1、sort，然后判断是否相等O(nlogn)/O(1)
2、哈希表,用哈希表记录s中字母出现的次数，用t减少哈希表中字母的次数，如果都减为0，则为true;O(n)/O(1)
*/



//思路1：sort+判断
class Solution {
public:
	//思路：
	//1、如果两个子串相同，true；否则进行sort,判断是否相同O(nlogn)/O(n)
	//知识点：母异位词是指由相同的字母按照不同的顺序组成的单词
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		vector<char> sTemp(s.begin(), s.end());
		vector<char> tTemp(t.begin(), t.end());
		sort(sTemp.begin(), sTemp.end());
		sort(tTemp.begin(), tTemp.end());
		return sTemp == tTemp;
	}
};

//自己写的快排
class Solution {
public:
	//思路2：排序
	//1、将序列s进行排序，如果排序后两串相同，则是字母异位词
	//2、边界条件，如果两边长度不等，可以提前返回
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		quickSort(s, 0, s.size() - 1);
		quickSort(t, 0, t.size() - 1);
		return s == t;
	}
	void quickSort(string& s, int low, int high) {
		if (low < high) {
			//划分
			int mid = partition(s, low, high);
			quickSort(s, low, mid - 1);
			quickSort(s, mid + 1, high);
		}
	}
	int partition(string& s, int low, int high) {
		int p = s[low];
		int m = low;
		for (int k = low + 1; k <= high; ++k) {
			if (s[k] < p) {
				++m;
				swap(s, m, k);
			}
		}
		swap(s, low, m);
		return m;
	}
	void swap(string& s, int i, int j) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
};

class Solution {
public:
	//思路：哈希表
	//1、用哈希表记录s中字母出现的次数，用t减少哈希表中字母的次数，如果都减为0，则为true
	//知识点：母异位词是指由相同的字母按照不同的顺序组成的单词
	//初始化大小为26的vector  vector<int> a(26);
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		vector<int> a(26);
		for (int i = 0; i < s.size(); i++) {
			a[s[i] - 'a']++;
			a[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (a[i] != 0) return false;
		}
		return true;
	}
};