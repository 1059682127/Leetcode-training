/*
题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

class Solution {
public:
	//双指针，数空格数num->新字符串长度->从后往前移动字符串
	//新长度：length + num * 2
	void replaceSpace(char *str, int length) {
		if (str == NULL || length == 0) return;
		int num = 0;
		for (int i = 0; i < length; ++i) {
			if (str[i] == ' ') ++num;
		}
		//进行替换
		char *p1 = str + length - 1;
		char *p2 = str + length + num * 2 - 1;
		//进行复制
		for (int i = length - 1; i >= 0; --i) {
			if (*p1 == ' ') {
				*p2-- = '0';
				*p2-- = '2';
				*p2-- = '%';
				p1--;
			}
			else {
				*p2-- = *p1--;
			}
		}
	}
};