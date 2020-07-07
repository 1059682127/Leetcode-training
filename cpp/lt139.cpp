//lt139

/*
题目描述：

给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：


	拆分时可以重复使用字典中的单词。
	你可以假设字典中没有重复的单词。


示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。


示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
	 注意你可以重复使用字典中的单词。


示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//思路1：
//暴力法：递归+回溯，分成前缀和剩余子串，前缀满足且剩余递归满足，则返回true
//O(n^n)/O(n):最坏的情况是aaaaaa，数的最大深度为n
//会超时
class Solution {
	//知识点：find函数，
public:
	//回溯
	bool wordBreak(string s, vector<string>& wordDict) {
		int len = s.size();
		if (len == 0) return false;

		return backtracking(s, wordDict, 0, len);
	}
	bool backtracking(string s, vector<string>& wordDict, int start, int len) {
		if (start == len) return true;

		for (int i = start; i < len; i++) {
			if (find(wordDict.begin(), wordDict.end(), s.substr(start, i - start + 1)) == wordDict.end()) continue;  //前缀不满足，跳过
			if (backtracking(s, wordDict, i + 1, len) == true) return true;
		}
		return false;
	}
};

//思路2：
//回溯+记忆：单纯回溯存在很多重复判断的子串;通过记忆化，许多冗余的子问题可以极大被优化，回溯树得到了剪枝，因此极大减小了时间复杂度。
//O(N^2)/O(N):回溯树的大小最多达到N^2

class Solution {
	//知识点：建立一个未记录的vector:0,-1,1
public:
	
	bool wordBreak(string s, vector<string>& wordDict) {
		int len = s.size();
		if (len == 0) return false;
		vector<int> memo(len, -1);  //-1未记录，0不可分解，1可分解
		return backtracking(s, wordDict, 0, len, memo);
	}
	bool backtracking(string s, vector<string>& wordDict, int start, int len, vector<int>& memo) {
		if (start == len) return true;

		//是否已记录
		if (memo[start] != -1) return memo[start];
		for (int i = start; i < len; i++) {
			if (find(wordDict.begin(), wordDict.end(), s.substr(start, i - start + 1)) != wordDict.end() && backtracking(s, wordDict, i + 1, len, memo)) {
				memo[start] = 1;
				return true;
			}

		}
		memo[start] = 0;
		return false;
	}
};

//思路3：宽度有限搜索BFS

//思路4：动态规划
//状态、选择、状态转移、base case

//状态：start(0到start之间的子串符合)

//选择：匹配字典哪一个单词

//状态转移： dp[start]本身在字典中 ; dp[start] = dp[旧start] && s[旧start:新start]存在于字典

//base case: dp[0] = true

//最后 return dp[len(s)]
class Solution {
	//知识点:记住substr(start, len) !!!len
public:
	//动态规划
	bool wordBreak(string s, vector<string>& wordDict) {
		//建立dp
		int len = s.size();
		vector<bool>dp(len + 1, 0);
		dp[0] = 1;
		//i是当前字符串从头开始的子字符串长度，j是拆分位置
		for (int i = 1; i <= len; i++) {  //i从1开始
			for (int j = 0; j < i; j++) {
				if (dp[j] && (find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[len];
	}
};