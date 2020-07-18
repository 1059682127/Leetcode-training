//lt126

/*
单词接龙 II

给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：


	每次转换只能改变一个字母。
	转换过程中的中间单词必须是字典中的单词。


说明:


	如果不存在这样的转换序列，返回一个空列表。
	所有单词具有相同的长度。
	所有单词只由小写字母组成。
	字典中不存在重复的单词。
	你可以假设 beginWord 和 endWord 是非空的，且二者不相同。


示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]

//思路1：深度遍历+回溯(超时)
//思路2：DFS+剪枝（超时）
//思路3：BFS+DFS(做不出来)
*/


class Solution {
public:
	//思路1：深度遍历+回溯
	//遍历某一点到另一点的可行路径，记录其长度并更新最小长度
	//在单词接龙问题中，经过的点不再访问，但是在这个问题中，多条最短路径可能经过同一个点，所以应该定义如下:
	//(要点！！！)单条路径不能重复访问一个点，但是不同路径可以访问同一个点
	//isVisted：0未访问，回溯前访问置1，在回溯的时候重置为0
	int minDepth;
	int L;  //单词长度
	vector<vector<string>> res;   //存放所有长度为最小长度的路径
	vector<string> temp;
	map<string, bool> isVisited;
	map<string, vector<string>> all_combo_dict;
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		minDepth = INT_MAX;
		L = beginWord.size();
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
		isVisited[beginWord] = true;
		temp.push_back(beginWord);
		helper(beginWord, endWord, 1, all_combo_dict);
		return res;

	}
	void helper(string cur, string endWord, int depth, map<string, vector<string>>& all_combo_dict) {
		//边界条件
		if (cur == endWord) {
			if (depth < minDepth) {
				res.clear();
				res.push_back(temp);
				minDepth = depth;
			}
			else if (depth == minDepth) {
				res.push_back(temp);
			}
			return;
		}
		//如果当前节点不是目的点
		//对邻居进行访问
		for (int i = 0; i < L; ++i) {
			string newCur = cur.substr(0, i) + '*' + cur.substr(i + 1, L - i - 1);
			if (!all_combo_dict.count(newCur)) continue;
			for (auto& nei : all_combo_dict[newCur]) {
				if (!isVisited[nei]) {
					temp.push_back(nei);
					isVisited[nei] = true;
					helper(nei, endWord, depth + 1, all_combo_dict);
					isVisited[*(temp.end() - 1)] = false;
					temp.pop_back();  //回溯
				}
			}
		}
	}
};

class Solution {
public:
	//思路2：DFS+剪枝（超时）

	//优化：（剪枝）发现一个节点（当前第k层）在另外一条路径已经被访问，如果这个单词在第 1 到 k-1 层已经出现过，我们其实就不过继续向下探索了。
	//Trick1：哈希表记录节点被访问的层数，并实时更新，0表示未被访问
	int minDepth;
	int L;  //单词长度
	vector<vector<string>> res;   //存放所有长度为最小长度的路径
	vector<string> temp;
	map<string, int> isVisited;
	map<string, vector<string>> all_combo_dict;
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		minDepth = INT_MAX;
		L = beginWord.size();
		map<string, int> isVisited;
		map<string, vector<string>> all_combo_dict;
		//将候选单词填到哈希表中，状态设计为false(未访问)
		for (auto& temp : wordList) {
			isVisited[temp] = 0;
			for (int i = 0; i < L; ++i) {
				string newWord = temp.substr(0, i) + '*' + temp.substr(i + 1, L - i - 1);
				all_combo_dict[newWord].push_back(temp);

			}
		}
		isVisited[beginWord] = 1;
		temp.push_back(beginWord);
		helper(beginWord, endWord, 1, all_combo_dict);
		return res;

	}
	void helper(string cur, string endWord, int depth, map<string, vector<string>>& all_combo_dict) {
		//边界条件
		if (cur == endWord) {
			if (depth < minDepth) {
				res.clear();
				res.push_back(temp);
				minDepth = depth;
			}
			else if (depth == minDepth) {
				res.push_back(temp);
			}
			return;
		}
		//如果当前节点不是目的点
		//对邻居进行访问
		for (int i = 0; i < L; ++i) {
			string newCur = cur.substr(0, i) + '*' + cur.substr(i + 1, L - i - 1);
			if (!all_combo_dict.count(newCur)) continue;
			for (auto& nei : all_combo_dict[newCur]) {
				//剪枝
				if (isVisited[nei] == 0 || isVisited[nei] >= depth) {
					temp.push_back(nei);
					isVisited[nei] = depth;
					helper(nei, endWord, depth + 1, all_combo_dict);
					temp.pop_back();  //回溯
				}
			}
		}
	}
};


class Solution {
public:
	//思路3：BFS+DFS(做不出来)
	//DSF尝试往一个方向走到底再回溯，这样会尝试很多次才找到一条最短路径，如果提前知道最短路径的长度，就可以提前回溯
	//可以在BFS 中，就把每个节点的所有相邻节点保存到 hash_table 中，就省去了 DFS 再去找相邻节点的时间
	//同时 BFS 的过程中，把最短路径的高度用 min 也记录下来，在 DFS 的时候到达高度后就可以提前结束。

	//优化：（剪枝）回溯的时候发现一个节点（当前回溯第k层）在另外一条路径已经被访问，如果这个单词在第 1 到 k-1 层已经出现过，我们其实就不过继续向下探索了。
	//Trick1：哈希表记录节点被访问的层数，并实时更新，0表示未被访问
	int minDepth;
	int L;  //单词长度
	vector<vector<string>> res;   //存放所有长度为最小长度的路径
	vector<string> temp;
	map<string, int> isVisited;
	map<string, vector<string>> all_combo_dict;
	map<string, vector<pair<string, int>>> adjacency;  //建立邻接表，并记录邻居点在广度遍历中的层次
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		L = beginWord.size();
		map<string, int> isVisited;
		map<string, vector<string>> all_combo_dict;
		//将候选单词填到哈希表中，状态设计为false(未访问)
		for (auto& temp : wordList) {
			isVisited[temp] = 0;
			for (int i = 0; i < L; ++i) {
				string newWord = temp.substr(0, i) + '*' + temp.substr(i + 1, L - i - 1);
				all_combo_dict[newWord].push_back(temp);
			}
		}
		minDepth = bfs(beginWord, endWord, all_combo_dict);
		cout << minDepth << endl;
		isVisited[beginWord] = 1;
		temp.push_back(beginWord);
		helper(pair(beginWord, 1), endWord, all_combo_dict);
		return res;

	}
	int bfs(string start, string end, map<string, vector<string>>& all_combo_dict) {
		queue<string> q;
		q.push(start);
		int level = 1;
		string cur;
		while (!q.empty()) {
			int size = q.size();
			while (size > 0) {
				cur = q.front();
				q.pop();
				--size;
				for (int i = 0; i < L; ++i) {
					string newCur = cur.substr(0, i) + '*' + cur.substr(i + 1, L - i - 1);
					if (!all_combo_dict.count(newCur)) continue;
					for (auto& nei : all_combo_dict[newCur]) {
						adjacency[cur].push_back(pair(nei, level + 1));
						q.push(nei);
						if (nei == end) return ++level;
					}
				}
			}
			++level;
		}
		return level;
	}
	void helper(pair<string, int> cur, string endWord, map<string, vector<string>>& all_combo_dict) {
		//边界条件
		if (cur.first == endWord) {
			if (cur.second == minDepth) {
				res.push_back(temp);
			}
			return;
		}
		//如果当前节点不是目的点
		//对邻居进行访问
		for (auto& nei : adjacency[cur.first]) {
			if (nei.second == cur.second + 1) {
				temp.push_back(nei.first);
				helper(nei, endWord, all_combo_dict);
				temp.pop_back();  //回溯
			}
		}
	}
};