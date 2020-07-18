//lt72

/*
72. 编辑距离

给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符

示例 1：
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：
输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
*/


class Solution {
public:
	//思路：动态规划（递归版）
	//两个指针 `i,j` 分别指向两个字符串的最后，然后一步步往前走，缩小问题的规模
	//dp(i, j):s1[0..i] 和 s2[0..j] 的最小编辑距离
	//base case：base case 是 `i` 走完 `s1` 或 `j` 走完 `s2`，可以直接返回另一个字符串剩下的长度。
	//状态转移：
	//如果s[i] = s[j],i, j 前移：return dp[i - 1][j - 1]
	//否则，三种情况选最小，插入dp[i][j - 1] + 1, 删除dp[i - 1][j] + 1,替换dp[i - 1][j - 1] + 1
	//优化：重叠子问题，备忘录
	int dp(int i, int j, vector<vector<int>> &memo, string &s1, string &s2) {
		//base case
		if (i == -1) return j + 1;
		if (j == -1) return i + 1;
		//如果已经记录
		if (memo[i][j] != -1) return memo[i][j];
		else {
			if (s1[i] == s2[j]) {
				memo[i][j] = dp(i - 1, j - 1, memo, s1, s2);
				return memo[i][j];
			}
			else {
				memo[i][j] = min(min(dp(i, j - 1, memo, s1, s2) + 1, dp(i - 1, j, memo, s1, s2) + 1), dp(i - 1, j - 1, memo, s1, s2) + 1);
				return memo[i][j];
			}
		}
	}
	int minDistance(string word1, string word2) {
		int len1 = word1.size();
		int len2 = word2.size();
		vector<vector<int>> memo(len1, vector<int>(len2, -1));
		return dp(len1 - 1, len2 - 1, memo, word1, word2);
	}
};


class Solution {
public:
	//思路：动态规划（自底向上）
	//两个指针 `i,j` 分别指向两个字符串的最后，然后一步步往前走，缩小问题的规模
	//dp[0][j]]表示s1走完
	//dp(i - 1, j - 1):s1[0..i] 和 s2[0..j] 的最小编辑距离
	//base case：base case 是 `i` 走完 `s1` 或 `j` 走完 `s2`，可以直接返回另一个字符串剩下的长度。
	//状态转移：
	//如果s[i] = s[j],i, j 前移：return dp[i - 1][j - 1]
	//否则，三种情况选最小，化：重叠子问题，备忘录插入dp[i][j - 1] + 1, 删除dp[i - 1][j] + 1,替换dp[i - 1][j - 1] + 1

	int minDistance(string word1, string word2) {
		int len1 = word1.size();
		int len2 = word2.size();
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
		//base case
		for (int i = 1; i <= len1; ++i) {
			dp[i][0] = i;
		}
		for (int j = 1; j <= len2; ++j) {
			dp[0][j] = j;
		}
		for (int i = 1; i <= len1; ++i) {
			for (int j = 1; j <= len2; ++j) {
				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
				}
			}
		}
		return dp[len1][len2];
	}
};