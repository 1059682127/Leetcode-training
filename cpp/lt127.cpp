//lt127
/*
127. ���ʽ���

�����������ʣ�beginWord �� endWord����һ���ֵ䣬�ҵ��� beginWord �� endWord �����ת�����еĳ��ȡ�ת������ѭ���¹���


	ÿ��ת��ֻ�ܸı�һ����ĸ��
	ת�������е��м䵥�ʱ������ֵ��еĵ��ʡ�


˵��:


	���������������ת�����У����� 0��
	���е��ʾ�����ͬ�ĳ��ȡ�
	���е���ֻ��Сд��ĸ��ɡ�
	�ֵ��в������ظ��ĵ��ʡ�
	����Լ��� beginWord �� endWord �Ƿǿյģ��Ҷ��߲���ͬ��


ʾ�� 1:

����:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

���: 5

����: һ�����ת�������� "hit" -> "hot" -> "dot" -> "dog" -> "cog",
	 �������ĳ��� 5��

//˼·1�������������+isVisted���	
//˼·2�������������+�Ż�����ת���ж�
*/


class Solution {
public:
	//˼·1�������������+isVisted���
	//��������ͼ�����·������
	//��Ŀ����˼�����ҵ�һ�����·������beginWord��endWord�����ù����������
	//�ؼ����ڽӱ�Ľ��������������ܷ�һ��ת����

	//Trick1:��hash���¼�Ѿ����ʹ��ĵ���
	//��ϣ���Ż�����visited��hash_table�ĳ�boolean���飬ͨ��index�ж��Ƿ��ѷ��ʡ�

	//����ת���ж�
	//˼·1������ѡ���ʣ�δ���ʹ��ĵ��ʣ��ȶԣ�����Աȵ��ʵ��ַ�
	//˼·2�����ǵ�������a~z�������������ַ���ɵģ����Ա�����ǰ������ת���ɵ����е��ʣ��ж����Ƿ�����ں�ѡ�����С���ѡ���ʱ�����hash_table�У����ʹ���ɾ��
	//�����������������Ӵ��ʱ��˼·1�ȽϺ�ʱ�������ʱȽϳ���ʱ��˼·2�ȽϺ�ʱ�����ǵ���һ�㲻��̫��
	//˼·3��Ԥ�����������е�ĳ����ĸ�� * ���棬����D*g ����ͬʱӳ�䵽 Dog ���� Dig��ӵ����ͬ��ͨ��״̬��ζ����������ֻ���һ����ĸ�����ǵĽڵ��������ġ� �ҵ� current_word ������ͨ��״̬���������Щͨ��״̬�Ƿ�����������ʵ�ӳ��

	//ʱ�䣺O(26^L)���������ǰ����г���ΪL�ĵ��ʶ���һ��
	//�ռ䣺O(min(26^L, size(wordList))
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		queue<string> q;
		q.push(beginWord);
		map<string, bool> isVisited;
		//����ѡ�������ϣ���У�״̬���Ϊfalse(δ����)
		for (auto& temp : wordList) isVisited[temp] = false;
		int level = 1;
		string cur;
		while (!q.empty()) {
			int size = q.size();
			while (size > 0) {
				cur = q.front();
				q.pop();
				--size;
				//Ѱ���ھ�
				for (int i = 0; i < cur.size(); ++i) {
					//�ַ���'a'�任��'z'
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
	//˼·2�������������+�Ż�����ת���ж�
	//��������ͼ�����·������
	//��Ŀ����˼�����ҵ�һ�����·������beginWord��endWord�����ù����������
	//�ؼ����ڽӱ�Ľ��������������ܷ�һ��ת����

	//����ת���ж�
	//˼·3��Ԥ�����������е�ĳ����ĸ�� * ���棬����D*g ����ͬʱӳ�䵽 Dog ���� Dig��ӵ����ͬ��ͨ��״̬��ζ����������ֻ���һ����ĸ�����ǵĽڵ��������ġ� �ҵ� current_word ������ͨ��״̬���������Щͨ��״̬�Ƿ�����������ʵ�ӳ��
	//isVisited�����ֵ��еĵ��ʣ�״̬Ϊ�Ƿ����
	//all_combo_dictΪͨ��״̬��Ӧ�ĵ��ʼ��ϣ���D*g��Ӧ{Dog,Dig}
	//ʱ�䣺O(M*N)MΪ���ʳ��ȣ�NΪ�ֵ��е�������
	//�ռ䣺O(M*N)

	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		int L = beginWord.size();
		queue<string> q;
		q.push(beginWord);
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
		int level = 1;
		string cur;
		while (!q.empty()) {
			int size = q.size();
			while (size > 0) {
				cur = q.front();
				q.pop();
				--size;
				//Ѱ���ھ�
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
	
	//˼·3:˫���������������������������ĸ����
	//���ֵ��е������϶�ʱ��ͼ��ǳ�����˿�����˫���������������ֱ��beginWord��endWord��ʼ
	//ά������queue,����isVisted,����level
	//��ֹ�������ҵ�һ�����ʱ��������������ʹ���
	//���أ���̱任���еĳ��Ⱦ����м�ڵ������ߵĲ��֮�͡�

	//Trick1:��Ҫ���Ż������ÿ�α���һ��ʱ���ӽڵ���ٵ�һ�˱���
	//Trick2:isVisted 0��ʾδ���ʣ���0��ʾ�����Ĳ���
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
		//����ѡ�������ϣ���У�״̬���Ϊfalse(δ����)
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
			//Ѱ���ھ�
			for (int i = 0; i < L; ++i) {
				string newCur = cur.substr(0, i) + '*' + cur.substr(i + 1, L - i - 1);
				if (!all_combo_dict.count(newCur)) continue;
				for (auto& temp : all_combo_dict[newCur]) {
					//�����һ�߷��ʹ�������ֹ
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