//lt208

/*
实现 Trie (前缀树)

实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
示例:
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");
trie.search("app");     // 返回 true
说明:
你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。
*/

class Trie {
private:
	bool is_end = false; //是不是终结点
	Trie* next[26] = { nullptr };  //26个链接 
public:
	/** Initialize your data structure here. */
	Trie() {}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Trie* node = this;
		for (const auto& w : word) {
			//是否有标记该字符的边
			if (node->next[w - 'a'] == nullptr) node->next[w - 'a'] = new Trie();
			//移动到子节点
			node = node->next[w - 'a'];
		}
		node->is_end = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Trie* node = this;
		for (const auto& w : word) {
			//是否有标记该字符的边，没有返false
			if (node->next[w - 'a'] == nullptr) return false;
			node = node->next[w - 'a'];
		}
		return node->is_end;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) { //查找前缀
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