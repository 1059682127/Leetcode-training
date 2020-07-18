//lt139

/*
��Ŀ������

����һ���ǿ��ַ��� s ��һ�������ǿյ����б���ֵ� wordDict���ж� s �Ƿ���Ա��ո���Ϊһ���������ֵ��г��ֵĵ��ʡ�

˵����


	���ʱ�����ظ�ʹ���ֵ��еĵ��ʡ�
	����Լ����ֵ���û���ظ��ĵ��ʡ�


ʾ�� 1��

����: s = "leetcode", wordDict = ["leet", "code"]
���: true
����: ���� true ��Ϊ "leetcode" ���Ա���ֳ� "leet code"��


ʾ�� 2��

����: s = "applepenapple", wordDict = ["apple", "pen"]
���: true
����: ���� true ��Ϊ "applepenapple" ���Ա���ֳ� "apple pen apple"��
	 ע��������ظ�ʹ���ֵ��еĵ��ʡ�


ʾ�� 3��

����: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
���: false

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/word-break
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

//˼·1��
//���������ݹ�+���ݣ��ֳ�ǰ׺��ʣ���Ӵ���ǰ׺������ʣ��ݹ����㣬�򷵻�true
//O(n^n)/O(n):��������aaaaaa������������Ϊn
//�ᳬʱ
class Solution {
	//֪ʶ�㣺find������
public:
	//����
	bool wordBreak(string s, vector<string>& wordDict) {
		int len = s.size();
		if (len == 0) return false;

		return backtracking(s, wordDict, 0, len);
	}
	bool backtracking(string s, vector<string>& wordDict, int start, int len) {
		if (start == len) return true;

		for (int i = start; i < len; i++) {
			if (find(wordDict.begin(), wordDict.end(), s.substr(start, i - start + 1)) == wordDict.end()) continue;  //ǰ׺�����㣬����
			if (backtracking(s, wordDict, i + 1, len) == true) return true;
		}
		return false;
	}
};

//˼·2��
//����+���䣺�������ݴ��ںܶ��ظ��жϵ��Ӵ�;ͨ�����仯������������������Լ����Ż����������õ��˼�֦����˼����С��ʱ�临�Ӷȡ�
//O(N^2)/O(N):�������Ĵ�С���ﵽN^2

class Solution {
	//֪ʶ�㣺����һ��δ��¼��vector:0,-1,1
public:
	
	bool wordBreak(string s, vector<string>& wordDict) {
		int len = s.size();
		if (len == 0) return false;
		vector<int> memo(len, -1);  //-1δ��¼��0���ɷֽ⣬1�ɷֽ�
		return backtracking(s, wordDict, 0, len, memo);
	}
	bool backtracking(string s, vector<string>& wordDict, int start, int len, vector<int>& memo) {
		if (start == len) return true;

		//�Ƿ��Ѽ�¼
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

//˼·3�������������BFS

//˼·4����̬�滮
//״̬��ѡ��״̬ת�ơ�base case

//״̬��start(0��start֮����Ӵ�����)

//ѡ��ƥ���ֵ���һ������

//״̬ת�ƣ� dp[start]�������ֵ��� ; dp[start] = dp[��start] && s[��start:��start]�������ֵ�

//base case: dp[0] = true

//��� return dp[len(s)]
class Solution {
	//֪ʶ��:��סsubstr(start, len) !!!len
public:
	//��̬�滮
	bool wordBreak(string s, vector<string>& wordDict) {
		//����dp
		int len = s.size();
		vector<bool>dp(len + 1, 0);
		dp[0] = 1;
		//i�ǵ�ǰ�ַ�����ͷ��ʼ�����ַ������ȣ�j�ǲ��λ��
		for (int i = 1; i <= len; i++) {  //i��1��ʼ
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