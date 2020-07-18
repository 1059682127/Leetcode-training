/*
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/

class Solution {
public:
	//深度遍历
	set<string> res;
	vector<string> Permutation(string str) {
		for (int i = 0; i < str.size(); ++i) {
			vector<bool> isVisited(str.size(), false);
			dfs(str, i, isVisited, "");
		}
		vector<string> resV(res.begin(), res.end());
		sort(resV.begin(), resV.end());
		return resV;
	}
	void dfs(string &str, int cur, vector<bool> isVisited, string temp) {
		if (temp.size() == str.size() - 1) {
			temp.push_back(str[cur]);
			res.insert(temp);
			return;
		}
		temp.push_back(str[cur]);
		isVisited[cur] = true;
		//遍历邻居
		for (int i = 0; i < str.size(); ++i) {
			if (!isVisited[i]) {
				dfs(str, i, isVisited, temp);
			}
		}
	}
};