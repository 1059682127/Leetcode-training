//lt131

/*
题目描述：分割回文串
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
返回 s 所有可能的分割方案。
示例:
输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

*/

//回溯法：O(N*N*N)
//递归树，分支是截取的前缀，节点是截取后的子串
//通过检测该前缀分支是否是回文，进行剪枝
//回溯，可以采用栈，找到一组答案之后，从栈顶弹出，退回上一层继续试
class Solution {
	//知识点：
	//1、string截取子串：s.substr(start, len);
	//2、当 string 中含有空字符’\0’，使用 strlen() 获取 string 的长度时会被截断，使用成员函数 length() 和 size() 可以返回 string的真实长度。
	//3、深度优先遍历。找到一组答案之后，把栈顶弹出，继续试，回退到上一层，尝试另一分支
public:
	//回溯
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> cur;
		int len = s.size();
		backtracking(s, res, cur, 0, len);
		return res;
	}
	void backtracking(string& s, vector<vector<string>>& res, vector<string>& cur, int start, int len) {
		//到了空字符串
		if (start == len) {
			res.push_back(cur);
			return;
		}
		//进行剪枝
		for (int i = start; i < len; i++) {
			if (!isPalindrome(s, start, i)) continue;
			cur.push_back(s.substr(start, i - start + 1));  //截取子串，注意子串的长度
			backtracking(s, res, cur, i + 1, len);
			cur.pop_back();   //回退到上一层
		}
	}
	bool isPalindrome(string& s, int left, int right) {
		while (left < right) {
			if (s[left] != s[right]) return false;
			left++;
			right--;
		}
		return true;
	}
};


////回溯+动态优化,用空间换时间，这样回溯的时候将回文检测从O(N)将到O(1)
class Solution {


public:
	
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> cur;
		//预处理：动态规划
		int len = s.size();
		// 状态：dp[i][j] 表示 s[i][j] 是否是回文
		// 状态转移方程：在 s[i] == s[j] 的时候，dp[i][j] 参考 dp[i + 1][j - 1]
		vector<vector<bool>> isPalindrome(len, vector<bool>(len));
		for (int right = 0; right < len; right++) {
			for (int left = 0; left <= right; left++) {
				if (s[left] == s[right] && (right - left <= 2 || isPalindrome[left + 1][right - 1])) isPalindrome[left][right] = true;
			}
		}
		backtracking(s, res, cur, 0, len, isPalindrome);
		return res;
	}
	void backtracking(string& s, vector<vector<string>>& res, vector<string>& cur, int start, int len, vector<vector<bool>>& isPalindrome) {
		//到了空字符串
		if (start == len) {
			res.push_back(cur);
			return;
		}
		//进行剪枝
		for (int i = start; i < len; i++) {
			if (!isPalindrome[start][i]) continue;
			cur.push_back(s.substr(start, i - start + 1));  //截取子串，注意子串的长度
			backtracking(s, res, cur, i + 1, len, isPalindrome);
			cur.pop_back();   //回退到上一层
		}
	}

};