/*
��Ŀ����
��һ���ַ���(0<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��, ���û���򷵻� -1����Ҫ���ִ�Сд��.����0��ʼ������
*/

class Solution {
public:
	//˼·����ϣ��
	int FirstNotRepeatingChar(string str) {
		unordered_map<char, int> map;
		for (int i = 0; i < str.size(); ++i) map[str[i]]++;
		for (int i = 0; i < str.size(); ++i) {
			if (map[str[i]] == 1) return i;
		}
		return -1;
	}
};