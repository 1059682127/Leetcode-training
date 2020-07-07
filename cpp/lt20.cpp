//lt20

/*
��Ч������

����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
��Ч�ַ��������㣺
�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ע����ַ����ɱ���Ϊ����Ч�ַ�����

//˼·1��ջ+��ϣ
*/



class Solution {
public:
	//˼·1��ջ����ջ��ƥ�����ջ����ƥ�����ջ��������ϣ�ջ�ռ���Ч
	//Trick1:�ù�ϣ���¼ƥ���
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