/*
������ʽƥ��

��Ŀ����
��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� �ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
*/

class Solution {
public:
	//�ݹ�
	bool match(char* str, char* pattern)
	{
		//���s, p����������
		if (*str == '\0' && *pattern == '\0') return true;
		//���sû�꣬p���ˣ�false
		if (*pattern == '\0') return false;
		//�����*
		if (*(pattern + 1) != '*') {
			if (*str != '\0' && (*str == *pattern || *pattern == '.')) return match(str + 1, pattern + 1);
			else return false;
		}
		else {
			//�ظ�һ�λ��߶��
			bool ret = false;
			if (*str != '\0' && (*str == *pattern || *pattern == '.'))
				ret = match(str + 1, pattern);
			//�ظ�0��
			return ret || match(str, pattern + 2);
		}
	}
};