//lt72

/*
72. �༭����

������������ word1 �� word2������������ word1 ת���� word2 ��ʹ�õ����ٲ����� ��
����Զ�һ�����ʽ����������ֲ�����
����һ���ַ�
ɾ��һ���ַ�
�滻һ���ַ�

ʾ�� 1��
���룺word1 = "horse", word2 = "ros"
�����3
���ͣ�
horse -> rorse (�� 'h' �滻Ϊ 'r')
rorse -> rose (ɾ�� 'r')
rose -> ros (ɾ�� 'e')
ʾ�� 2��
���룺word1 = "intention", word2 = "execution"
�����5
���ͣ�
intention -> inention (ɾ�� 't')
inention -> enention (�� 'i' �滻Ϊ 'e')
enention -> exention (�� 'n' �滻Ϊ 'x')
exention -> exection (�� 'n' �滻Ϊ 'c')
exection -> execution (���� 'u')
*/


class Solution {
public:
	//˼·����̬�滮���ݹ�棩
	//����ָ�� `i,j` �ֱ�ָ�������ַ��������Ȼ��һ������ǰ�ߣ���С����Ĺ�ģ
	//dp(i, j):s1[0..i] �� s2[0..j] ����С�༭����
	//base case��base case �� `i` ���� `s1` �� `j` ���� `s2`������ֱ�ӷ�����һ���ַ���ʣ�µĳ��ȡ�
	//״̬ת�ƣ�
	//���s[i] = s[j],i, j ǰ�ƣ�return dp[i - 1][j - 1]
	//�����������ѡ��С������dp[i][j - 1] + 1, ɾ��dp[i - 1][j] + 1,�滻dp[i - 1][j - 1] + 1
	//�Ż����ص������⣬����¼
	int dp(int i, int j, vector<vector<int>> &memo, string &s1, string &s2) {
		//base case
		if (i == -1) return j + 1;
		if (j == -1) return i + 1;
		//����Ѿ���¼
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
	//˼·����̬�滮���Ե����ϣ�
	//����ָ�� `i,j` �ֱ�ָ�������ַ��������Ȼ��һ������ǰ�ߣ���С����Ĺ�ģ
	//dp[0][j]]��ʾs1����
	//dp(i - 1, j - 1):s1[0..i] �� s2[0..j] ����С�༭����
	//base case��base case �� `i` ���� `s1` �� `j` ���� `s2`������ֱ�ӷ�����һ���ַ���ʣ�µĳ��ȡ�
	//״̬ת�ƣ�
	//���s[i] = s[j],i, j ǰ�ƣ�return dp[i - 1][j - 1]
	//�����������ѡ��С�������ص������⣬����¼����dp[i][j - 1] + 1, ɾ��dp[i - 1][j] + 1,�滻dp[i - 1][j - 1] + 1

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