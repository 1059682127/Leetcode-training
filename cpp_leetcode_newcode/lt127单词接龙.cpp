//lt127
/*
127. 单词接龙

给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：


	每次转换只能改变一个字母。
	转换过程中的中间单词必须是字典中的单词。


说明:


	如果不存在这样的转换序列，返回 0。
	所有单词具有相同的长度。
	所有单词只由小写字母组成。
	字典中不存在重复的单词。
	你可以假设 beginWord 和 endWord 是非空的，且二者不相同。


示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
	 返回它的长度 5。

//思路1：广度优先搜索+isVisted标记	
//思路2：广度优先搜索+优化单词转换判断
*/


class Solution {
public:
	//思路1：广度优先搜索+isVisted标记
	//本质上是图的最短路径问题
	//题目的意思就是找到一条最短路径，从beginWord到endWord，采用广度优先搜索
	//关键是邻接表的建立（两个单词能否一次转换）

	//Trick1:用hash表记录已经访问过的单词
	//哈希表优化：把visited从hash_table改成boolean数组，通过index判断是否已访问。

	//单词转换判断
	//思路1：跟候选单词（未访问过的单词）比对，逐个对比单词的字符
	//思路2：考虑到单词由a~z这有限数量的字符组成的，可以遍历当前单词能转换成的所有单词，判断其是否包含在候选单词中。候选单词保存在hash_table中，访问过即删除
	//分析：当单词总量庞大的时候，思路1比较耗时；当单词比较长的时候，思路2比较耗时，但是单词一般不会太长
	//思路3：预处理，将单词中的某个字母用 * 代替，比如D*g 可以同时映射到 Dog 或者 Dig，拥有相同的通用状态意味着两个单词只相差一个字母，他们的节点是相连的。 找到 current_word 的所有通用状态，并检查这些通用状态是否存在其它单词的映射

	//时间：O(26^L)最坏的情况就是把所有长度为L的单词都试一下
	//空间：O(min(26^L, size(wordList))
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		queue<string> q;
		q.push(beginWord);
		map<string, bool> isVisited;
		//将候选单词填到哈希表中，状态设计为false(未访问)
		for (auto& temp : wordList) isVisited[temp] = false;
		int level = 1;
		string cur;
		while (!q.empty()) {
			int size = q.size();
			while (size > 0) {
				cur = q.front();
				q.pop();
				--size;
				//寻找邻居
				for (int i = 0; i < cur.size(); ++i) {
					//字符从'a'变换到'z'
					string temp = cur;
					for (char c = 'a'; c <= 'z'; ++c) {
						temp[i] = c;
						if (!isVisited.count(temp)) continue;
						if (temp == endWord) return ++level;
						if (!isVisited[temp]) {
							q.push(temp);
							isVisited[temp] = true;
						}
					}
				}
			}
			++level;
		}
		return 0;
	}
};

class Solution {
public:
	//思路2：广度优先搜索+优化单词转换判断
	//本质上是图的最短路径问题
	//题目的意思就是找到一条最短路径，从beginWord到endWord，采用广度优先搜索
	//关键是邻接表的建立（两个单词能否一次转换）

	//单词转换判断
	//思路3：预处理，将单词中的某个字母用 * 代替，比如D*g 可以同时映射到 Dog 或者 Dig，拥有相同的通用状态意味着两个单词只相差一个字母，他们的节点是相连的。 找到 current_word 的所有通用状态，并检查这些通用状态是否存在其它单词的映射
	//isVisited保存字典中的单词，状态为是否访问
	//all_combo_dict为通用状态对应的单词集合，如D*g对应{Dog,Dig}
	//时间：O(M*N)M为单词长度，N为字典中单词数量
	//空间：O(M*N)

	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		int L = beginWord.size();
		queue<string> q;
		q.push(beginWord);
		map<string, bool> isVisited;
		map<string, vector<string>> all_combo_dict;
		//将候选单词填到哈希表中，状态设计为false(未访问)
		for (auto& temp : wordList) {
			isVisited[temp] = false;
			for (int i = 0; i < L; ++i) {
				string newWord = temp.substr(0, i) + '*' + temp.substr(i + 1, L - i - 1);
				all_combo_dict[newWord].push_back(temp);
			}
		}
		int level = 1;
		string cur;
		while (!q.empty()) {
			int size = q.size();
			while (size > 0) {
				cur = q.front();
				q.pop();
				--size;
				//寻找邻居
				for (int i = 0; i < L; ++i) {
					string newCur = cur.substr(0, i) + '*' + cur.substr(i + 1, L - i - 1);
					if (!all_combo_dict.count(newCur)) continue;
					for (auto& temp : all_combo_dict[newCur]) {
						if (temp == endWord) return ++level;
						if (!isVisited[temp]) {
							q.push(temp);
							isVisited[temp] = true;
						}
					}
				}
			}
			++level;
		}
		return 0;
	}
};

class Solution {
public:
	
	//思路3:双向广度优先搜索（编译出错。。。。母鸡）
	//当字典中单词数较多时，图会非常大，因此考虑用双向广度优先搜索，分别从beginWord和endWord开始
	//维护两个queue,两个isVisted,两个level
	//终止条件：找到一个单词被两边搜索都访问过了
	//返回：最短变换序列的长度就是中间节点在两边的层次之和。

	//Trick1:主要的优化点就是每次遍历一层时，从节点更少的一端遍历
	//Trick2:isVisted 0表示未访问，非0表示遍历的层数
	int L;
	string endWord;
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		L = beginWord.size();
		endWord = endWord;
		queue<string> q1;
		queue<string> q2;
		q1.push(beginWord);
		q2.push(endWord);
		map<string, int> isVisited1;
		map<string, int> isVisited2;
		isVisited1[beginWord] = 1;
		isVisited2[endWord] = 1;
		map<string, vector<string>> all_combo_dict;
		//将候选单词填到哈希表中，状态设计为false(未访问)
		for (auto& temp : wordList) {
			isVisited1[temp] = 0;
			isVisited2[temp] = 0;
			for (int i = 0; i < L; ++i) {
				string newWord = temp.substr(0, i) + '*' + temp.substr(i + 1, L - i - 1);
				all_combo_dict[newWord].push_back(temp);
			}
		}
		int level1 = 1;
		int level2 = 1;
		while (!q1.empty() && !q2.empty()) {
			int size1 = q1.size();
			int size2 = q2.size();
			if (size1 < size2) {
				int ans = helper(q1, all_combo_dict, isVisited1, isVisited2, size1, level1);
				if (ans > -1) return ans;
			}
			else {
				int ans = helper(q2, all_combo_dict, isVisited2, isVisited1, size2, level2);
				if (ans > -1) return ans;
			}
		}
		return 0;
	}
	int helper(queue<string>& q, map<string, vector<string>>& all_combo_dict, map<string, int>& isVisited1, map<string, int>& isVisited2, int size, int& level) {
		while (size > 0) {
			string cur = q.front();
			q.pop();
			--size;
			//寻找邻居
			for (int i = 0; i < L; ++i) {
				string newCur = cur.substr(0, i) + '*' + cur.substr(i + 1, L - i - 1);
				if (!all_combo_dict.count(newCur)) continue;
				for (auto& temp : all_combo_dict[newCur]) {
					//如果另一边访问过，则终止
					if (isVisited2.count(temp) && isVisited2[temp] != 0) return level + isVisited2[temp];
					if (isVisited1.count(temp) && isVisited1[temp] == 0) {
						q.push(temp);
						isVisited1[temp] = level + 1;
					}
				}
			}
		}
		++level;
		return -1;
	}
};