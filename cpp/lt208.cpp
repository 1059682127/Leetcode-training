//lt208

/*
ʵ�� Trie (ǰ׺��)

ʵ��һ�� Trie (ǰ׺��)������ insert, search, �� startsWith ������������
ʾ��:
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // ���� true
trie.search("app");     // ���� false
trie.startsWith("app"); // ���� true
trie.insert("app");
trie.search("app");     // ���� true
˵��:
����Լ������е����붼����Сд��ĸ a-z ���ɵġ�
��֤���������Ϊ�ǿ��ַ�����
*/

class Trie {
private:
	bool is_end = false; //�ǲ����ս��
	Trie* next[26] = { nullptr };  //26������ 
public:
	/** Initialize your data structure here. */
	Trie() {}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Trie* node = this;
		for (const auto& w : word) {
			//�Ƿ��б�Ǹ��ַ��ı�
			if (node->next[w - 'a'] == nullptr) node->next[w - 'a'] = new Trie();
			//�ƶ����ӽڵ�
			node = node->next[w - 'a'];
		}
		node->is_end = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Trie* node = this;
		for (const auto& w : word) {
			//�Ƿ��б�Ǹ��ַ��ıߣ�û�з�false
			if (node->next[w - 'a'] == nullptr) return false;
			node = node->next[w - 'a'];
		}
		return node->is_end;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) { //����ǰ׺
		Trie* node = this;
		for (const auto& w : prefix) {
			if (node->next[w - 'a'] == nullptr) return false;
			node = node->next[w - 'a'];
		}
		return true;
	}

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */