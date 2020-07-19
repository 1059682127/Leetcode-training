/*
题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/

class Solution {
public:
	//整个反转->滑动窗口，遇空格停止，单词内反转->滑动到下一个单词
	string ReverseSentence(string str) {
		if (str.size() == 0) return str;
		reverse(str.begin(), str.end());
		int l = 0, r = 0;
		while (r < str.size()) {
			if (str[r] == ' ') {
				//交换该单词
				reverseWord(str, l, r - 1);
				++r;
				l = r;
			}
			//最后一次停止
			if (r == str.size() - 1) {
				reverseWord(str, l, r);
				break;
			}
			++r;
		}
		return str;
	}
	void reverseWord(string &str, int l, int r) {
		while (l < r) {
			char temp = str[l];
			str[l] = str[r];
			str[r] = temp;
			++l;
			--r;
		}
	}
};