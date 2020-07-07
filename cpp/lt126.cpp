//lt126

/*
���ʽ��� II

�����������ʣ�beginWord �� endWord����һ���ֵ� wordList���ҳ����д� beginWord �� endWord �����ת�����С�ת������ѭ���¹���


	ÿ��ת��ֻ�ܸı�һ����ĸ��
	ת�������е��м䵥�ʱ������ֵ��еĵ��ʡ�


˵��:


	���������������ת�����У�����һ�����б�
	���е��ʾ�����ͬ�ĳ��ȡ�
	���е���ֻ��Сд��ĸ��ɡ�
	�ֵ��в������ظ��ĵ��ʡ�
	����Լ��� beginWord �� endWord �Ƿǿյģ��Ҷ��߲���ͬ��


ʾ�� 1:

����:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

���:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]

//˼·1����ȱ���+����(��ʱ)
//˼·2��DFS+��֦����ʱ��
//˼·3��BFS+DFS(��������)
*/


class Solution {
public:
	//˼·1����ȱ���+����
	//����ĳһ�㵽��һ��Ŀ���·������¼�䳤�Ȳ�������С����
	//�ڵ��ʽ��������У������ĵ㲻�ٷ��ʣ���������������У��������·�����ܾ���ͬһ���㣬����Ӧ�ö�������:
	//(Ҫ�㣡����)����·�������ظ�����һ���㣬���ǲ�ͬ·�����Է���ͬһ����
	//isVisted��0δ���ʣ�����ǰ������1���ڻ��ݵ�ʱ������Ϊ0
	int minDepth;
	int L;  //���ʳ���
	vector<vector<string>> res;   //������г���Ϊ��С���ȵ�·��
	vector<string> temp;
	map<string, bool> isVisited;
	map<string, vector<string>> all_combo_dict;
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		minDepth = INT_MAX;
		L = beginWord.size();
		map<string, bool> isVisited;
		map<string, vector<string>> all_combo_dict;
		//����ѡ�������ϣ���У�״̬���Ϊfalse(δ����)
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
		//�߽�����
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
		//�����ǰ�ڵ㲻��Ŀ�ĵ�
		//���ھӽ��з���
		for (int i = 0; i < L; ++i) {
			string newCur = cur.substr(0, i) + '*' + cur.substr(i + 1, L - i - 1);
			if (!all_combo_dict.count(newCur)) continue;
			for (auto& nei : all_combo_dict[newCur]) {
				if (!isVisited[nei]) {
					temp.push_back(nei);
					isVisited[nei] = true;
					helper(nei, endWord, depth + 1, all_combo_dict);
					isVisited[*(temp.end() - 1)] = false;
					temp.pop_back();  //����
				}
			}
		}
	}
};

class Solution {
public:
	//˼·2��DFS+��֦����ʱ��

	//�Ż�������֦������һ���ڵ㣨��ǰ��k�㣩������һ��·���Ѿ������ʣ������������ڵ� 1 �� k-1 ���Ѿ����ֹ���������ʵ�Ͳ�����������̽���ˡ�
	//Trick1����ϣ���¼�ڵ㱻���ʵĲ�������ʵʱ���£�0��ʾδ������
	int minDepth;
	int L;  //���ʳ���
	vector<vector<string>> res;   //������г���Ϊ��С���ȵ�·��
	vector<string> temp;
	map<string, int> isVisited;
	map<string, vector<string>> all_combo_dict;
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		minDepth = INT_MAX;
		L = beginWord.size();
		map<string, int> isVisited;
		map<string, vector<string>> all_combo_dict;
		//����ѡ�������ϣ���У�״̬���Ϊfalse(δ����)
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
		//�߽�����
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
		//�����ǰ�ڵ㲻��Ŀ�ĵ�
		//���ھӽ��з���
		for (int i = 0; i < L; ++i) {
			string newCur = cur.substr(0, i) + '*' + cur.substr(i + 1, L - i - 1);
			if (!all_combo_dict.count(newCur)) continue;
			for (auto& nei : all_combo_dict[newCur]) {
				//��֦
				if (isVisited[nei] == 0 || isVisited[nei] >= depth) {
					temp.push_back(nei);
					isVisited[nei] = depth;
					helper(nei, endWord, depth + 1, all_combo_dict);
					temp.pop_back();  //����
				}
			}
		}
	}
};


class Solution {
public:
	//˼·3��BFS+DFS(��������)
	//DSF������һ�������ߵ����ٻ��ݣ������᳢�Ժܶ�β��ҵ�һ�����·���������ǰ֪�����·���ĳ��ȣ��Ϳ�����ǰ����
	//������BFS �У��Ͱ�ÿ���ڵ���������ڽڵ㱣�浽 hash_table �У���ʡȥ�� DFS ��ȥ�����ڽڵ��ʱ��
	//ͬʱ BFS �Ĺ����У������·���ĸ߶��� min Ҳ��¼�������� DFS ��ʱ�򵽴�߶Ⱥ�Ϳ�����ǰ������

	//�Ż�������֦�����ݵ�ʱ����һ���ڵ㣨��ǰ���ݵ�k�㣩������һ��·���Ѿ������ʣ������������ڵ� 1 �� k-1 ���Ѿ����ֹ���������ʵ�Ͳ�����������̽���ˡ�
	//Trick1����ϣ���¼�ڵ㱻���ʵĲ�������ʵʱ���£�0��ʾδ������
	int minDepth;
	int L;  //���ʳ���
	vector<vector<string>> res;   //������г���Ϊ��С���ȵ�·��
	vector<string> temp;
	map<string, int> isVisited;
	map<string, vector<string>> all_combo_dict;
	map<string, vector<pair<string, int>>> adjacency;  //�����ڽӱ�����¼�ھӵ��ڹ�ȱ����еĲ��
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		L = beginWord.size();
		map<string, int> isVisited;
		map<string, vector<string>> all_combo_dict;
		//����ѡ�������ϣ���У�״̬���Ϊfalse(δ����)
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
		//�߽�����
		if (cur.first == endWord) {
			if (cur.second == minDepth) {
				res.push_back(temp);
			}
			return;
		}
		//�����ǰ�ڵ㲻��Ŀ�ĵ�
		//���ھӽ��з���
		for (auto& nei : adjacency[cur.first]) {
			if (nei.second == cur.second + 1) {
				temp.push_back(nei.first);
				helper(nei, endWord, all_combo_dict);
				temp.pop_back();  //����
			}
		}
	}
};