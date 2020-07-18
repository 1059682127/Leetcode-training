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
		//��ϣ����¼�����
		map<char, char> hash_table;
		hash_table[')'] = '(';
		hash_table[']'] = '[';
		hash_table['}'] = '{';
		data.push(s[0]);
		for (int i = 1; i < len; ++i) {
			char c = s[i];
			//�����'(', '[', '{'������ջ
			if (!hash_table.count(c)) data.push(c);
			else {
				//�����')', ']', '}'
				//�ж��Ƿ���ջ��ƥ��
				//���ջΪ�գ���ƥ�䣬false
				if (data.empty()) return false;
				//���ƥ���ϣ���ջ
				if (data.top() == hash_table[c]) data.pop();
				//��ƥ�䣬��ջ
				else data.push(c);
			}
		}
		//���ջΪ����ƥ��
		return data.empty();
	}
};