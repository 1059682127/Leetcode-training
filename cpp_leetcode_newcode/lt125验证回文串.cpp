//lt125

/*
题目描述：
验证回文串

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:
输入: "race a car"
输出: false

思考：
1、先筛选字符，再遍历：O(N)/O(N)


知识点：
1、数字的识别，大写转写
2、ASCII对照表：'0':48;'A':64;'a':97
*/


//筛选+遍历
class Solution {
public:
	bool isPalindrome(string s) {
		//空字符串
		if (s == " ") return true;
		//存放筛选后的字符
		vector<char> temp;
		//剔除非数字，将大写转为小写
		for (int i = 0; i < s.size(); i++) {
			if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z')) temp.push_back(s[i]);
			if (s[i] >= 'A' && s[i] <= 'Z') temp.push_back(s[i] - 'A' + 'a');
		}
		//遍历
		int len = temp.size();
		for (int i = 0; i < len / 2; i++) {
			if (temp[i] != temp[len - 1 - i]) return false;
		}
		return true;
	}
};

//双指针法
class Solution {
public:
	//双指针
	bool isPalindrome(string s) {
		//空字符串
		if (s == " ") return true;
		int first = 0;
		int second = s.size() - 1;
		while (first < second) {
			//去除非字母或非数字
			if (s[first] < '0' || (s[first] > '9' && s[first] < 'A') || (s[first] > 'Z' && s[first] < 'a') || s[first] > 'z') {
				first++;
				continue;
			}
			if (s[second] < '0' || (s[second] > '9' && s[second] < 'A') || (s[second] > 'Z' && s[second] < 'a') || s[second] > 'z') {
				second--;
				continue;
			}
			//进行字符转换
			if (s[first] >= 'A' && s[first] <= 'Z') s[first] = s[first] - 'A' + 'a';
			if (s[second] >= 'A' && s[second] <= 'Z') s[second] = s[second] - 'A' + 'a';
			if (s[first++] != s[second--]) return false;
		}
		return true;
	}
};