/*
��Ŀ����
�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ���������������һ���������ַ�����S���������ѭ������Kλ���������������磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����
*/

class Solution {
public:
	string LeftRotateString(string str, int n) {
		int len = str.size();
		if (str.size() == 0) return "";
		if (n == 0) return str;
		int index = n % len;
		return str.substr(index, len - index) + str.substr(0, index);
	}
};