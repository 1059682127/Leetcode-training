//lt20

/*
有效的括号

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

//思路1：栈+哈希
*/



class Solution {
public:
	//思路1：栈，跟栈顶匹配则出栈，不匹配则进栈，遍历完毕，栈空即有效
	//Trick1:用哈希表记录匹配对
	bool isValid(string s) {
		stack<int> data;
		int len = s.size();
		if (len == 0) return true;
		map<char, char> hash_table;
		hash_table[')'] = '(';
		hash_table[']'] = '[';
		hash_table['}'] = '{';
		data.push(s[0]);
		for (int i = 1; i < len; ++i) {
			char c = s[i];
			if (!hash_table.count(c)) data.push(c);
			else {
				if (data.empty()) return false;
				if (data.top() == hash_table[c]) data.pop();
				else data.push(c);
			}
		}
		return data.empty();
	}
};