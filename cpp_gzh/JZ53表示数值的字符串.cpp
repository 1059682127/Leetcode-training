/*
��ʾ��ֵ���ַ���

��Ŀ����
��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С���������磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ�� ����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�
*/

class Solution {
public:
	//+-�ź���ض�Ϊ���ֻ����Ϊ.��-.123 = -0.123�� 
	//+-��ֻ�����ڵ�һλ����eE�ĺ�һλ 
	//.����ض�Ϊ���ֻ�Ϊ���һλ��233. = 233.0�� 
	//eE����ض�Ϊ���ֻ�+-��
	bool isNumeric(char* str)
	{
		int len = strlen(str);
		bool point = false, exp = false;  //��־С�����ָ��λ,������������С��λ��ָ��λ
		for (int i = 0; i < len; ++i) {
			if (str[i] == '+' || str[i] == '-') {
				if (i + 1 == len || !(str[i + 1] >= '0' && str[i + 1] <= '9' || str[i + 1] == '.')) {
					cout << 1;
					return false;
				}
				if (!(i == 0 || str[i - 1] == 'e' || str[i - 1] == 'E')) {
					cout << 1;
					return false;
				}
			}
			else if (str[i] == '.') {
				if (point || exp || !(i + 1 < len && str[i + 1] >= '0' && str[i + 1] <= '9')) {
					cout << 1;
					return false;
				}
				point = true;  //��¼����С��λ
			}
			else if (str[i] == 'e' || str[i] == 'E') {
				if (exp || i + 1 == len || !(str[i + 1] >= '0' && str[i + 1] <= '9' || str[i + 1] == '+' || str[i + 1] == '-')) {
					cout << 1;
					return false;
				}
				exp = true;
			}
			else if (str[i] >= '0' && str[i] <= '9') {}
			else return false;
		}
		return true;
	}

};