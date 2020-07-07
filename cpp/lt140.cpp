//lt140

//回溯
/*
题目描述
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：


	分隔时可以重复使用字典中的单词。
	你可以假设字典中没有重复的单词。


示例 1：

输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
  "cats and dog",
  "cat sand dog"
]


示例 2：

输入:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
输出:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
解释: 注意你可以重复使用字典中的单词。


示例 3：

输入:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
输出:
[]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//思路1：
1、回溯法
2、回溯+记忆
3、
*/

//思路1：
//参考lt139单词拆分，可以用回溯
//O(N^N)/O(N),超时
class Solution {
public:
	//回溯
	//难点：怎么保存子串并用" "连接
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> dict(wordDict.begin(), wordDict.end());  //采用set检测是否包含该字母
		int len = s.size();
		if (len == 0) return {};
		vector<string> res;
		string cur;
		backtracking(s, dict, 0, len, cur, res);
		return res;

	}
	void backtracking(string s, unordered_set<string>& dict, int start, int len, string cur, vector<string>& res) {
		//去掉空白符
		if (start == len) {
			res.push_back(cur);
			return;
		}
		//剪枝
		for (int i = start; i < len; i++) {
			if (dict.count(s.substr(start, i - start + 1))) {
				int curSize = cur.size();
				cur = cur + s.substr(start, i - start + 1) + ((i == s.size() - 1) ? "" : " "); //判断是否添加空格
				backtracking(s, dict, i + 1, len, cur, res);
				cur.erase(curSize, cur.size() - curSize + 1);  //去掉该次循环添加的
			}

		}
	}
};


//思路2：
//回溯+记忆（哈希表）：O(N^3)回溯树的大小最多N^2
//可以用哈希表优化，key是当前考虑字符串的开始下标，value是对应当前开始下标的所有可行句子

class Solution {
public:
	//回溯+记忆
	//难点：怎么用哈希表记录，用map记录从当前下标开始的子串的拆分情况
	//知识点：map是否包含某键map.count(key)
	//回溯中的res与start对应，所以可以用map记录
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> dict(wordDict.begin(), wordDict.end());  //采用set检测是否包含该字母
		int len = s.size();
		if (len == 0) return {};
		string cur;
		map<int, vector<string>> map;
		return backtracking(s, dict, 0, len, cur, map);

	}
	vector<string> backtracking(string s, unordered_set<string>& dict, int start, int len, string cur, map<int, vector<string>>& map) {
		//检查是否存在记录
		if (map.count(start)) {
			return map[start];
		}
		vector<string> res;
		//去掉空白符
		if (start == len) {
			res.push_back("");
		}
		else {
			//剪枝
			for (int i = start; i < len; i++) {
				if (dict.count(s.substr(start, i - start + 1))) {
					vector<string> temp = backtracking(s, dict, i + 1, len, cur, map);
					//添加子串对应的res
					for (int j = 0; j < temp.size(); j++) {
						res.push_back(s.substr(start, i - start + 1) + (temp[j].empty() ? "" : " ") + temp[j]);
					}
				}
			}
		}

		map[start] = res;
		return res;
	}
};

//思路3：动态规划O(N^3)/O(N^2)
//dp[k] 被用来存储用 s[0:k−1] 可被拆分成合法单词的句子。
//为了求出dp[i]，先检查dp[j]是否存在,再检查j+1到i的子串是否在字典当中

class Solution {
public:
	
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> dict(wordDict.begin(), wordDict.end());  //采用set检测是否包含该字母
		int len = s.size();
		if (len == 0) return {};
		//创建dp,dp[k] 被用来存储用s[0:k−1] 可被拆分成合法单词的句子
		vector<vector<string>> dp(len + 1);
		//base case
		dp[0].push_back("");
		//状态转移
		for (int i = 1; i <= len; i++) {
			for (int j = 0; j < i; j++) {
				//如果0~j已记录且i+1~j在字典当中
				if (dp[j].size() > 0 && dict.count(s.substr(j, i - j))) {
					//保存dp[i]
					for (auto temp : dp[j]) {
						dp[i].push_back(temp + (temp.empty() ? "" : " ") + s.substr(j, i - j)); //empty()检查是否为空串
					}
				}
			}
		}
		//返回dp[len]
		return dp[len];
	}

};


//DP+回溯
https://leetcode-cn.com/problems/word-break-ii/solution/leetcodebi-ji-java-py-si-ke-yi-dao-ti-140-dan-ci-c/
//单纯DP会因为保存vector<string>出现超时，可以用DP表示0~i的子串是否可拆分，然后用回溯
class Solution {
public:
	//动态规划+回溯
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> dict(wordDict.begin(), wordDict.end());  //采用set检测是否包含该字母
		int len = s.size();
		if (len == 0) return {};
		//创建dp,dp[k] 被用来存储s[0:k−1] 是否可被拆分成合法单词的句子
		vector<vector<bool>> dp(len + 1);
		//base case
		dp[0] = true;
		//状态转移
		for (int i = 1; i <= len; i++) {
			for (int j = 0; j < i; j++) {
				//如果0~j已记录且i+1~j在字典当中
				if (dp[j] && dict.count(s.substr(j, i - j))) {
					dp[i] = true;
					break;
				}
			}
		}
		//如果可拆分，进行dfs
		if (dp[len]) {
			dfs();
		}
		//返回dp[len]
		return dp[len];
	}
	void dfs(string s, unordered_set<string>& dict, int) {
		......
	}

};