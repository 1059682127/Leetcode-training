/*
字符流中第一个不重复的字符

题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。

*/

class Solution
{
public:
	//思路：用先进先出队列保持顺序，哈希表统计次数
	//插入时，只有次数为0的才插入
	//判断队首元素是否重复了，重复则移除
	unordered_map<int, int> charInt;
	queue<char> q;
	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (charInt[ch]++ == 0) q.push(ch);
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		while (!q.empty()) {
			if (charInt[q.front()] == 1) return q.front();
			else q.pop();
		}
		return '#';
	}

};