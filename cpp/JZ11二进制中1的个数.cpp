/*
��Ŀ����
����һ���������������32λ�����Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*/

class Solution {
public:
	int  NumberOf1(int n) {
		int sum = 0;
		while (n) {
			++sum;
			n = n & (n - 1);
		}
		return sum;
	}
};