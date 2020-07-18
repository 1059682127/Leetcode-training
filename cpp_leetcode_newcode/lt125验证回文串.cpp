//lt125

/*
��Ŀ������
��֤���Ĵ�

����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
ʾ�� 1:
����: "A man, a plan, a canal: Panama"
���: true
ʾ�� 2:
����: "race a car"
���: false

˼����
1����ɸѡ�ַ����ٱ�����O(N)/O(N)


֪ʶ�㣺
1�����ֵ�ʶ�𣬴�дתд
2��ASCII���ձ�'0':48;'A':64;'a':97
*/


//ɸѡ+����
class Solution {
public:
	bool isPalindrome(string s) {
		//���ַ���
		if (s == " ") return true;
		//���ɸѡ����ַ�
		vector<char> temp;
		//�޳������֣�����дתΪСд
		for (int i = 0; i < s.size(); i++) {
			if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z')) temp.push_back(s[i]);
			if (s[i] >= 'A' && s[i] <= 'Z') temp.push_back(s[i] - 'A' + 'a');
		}
		//����
		int len = temp.size();
		for (int i = 0; i < len / 2; i++) {
			if (temp[i] != temp[len - 1 - i]) return false;
		}
		return true;
	}
};

//˫ָ�뷨
class Solution {
public:
	//˫ָ��
	bool isPalindrome(string s) {
		//���ַ���
		if (s == " ") return true;
		int first = 0;
		int second = s.size() - 1;
		while (first < second) {
			//ȥ������ĸ�������
			if (s[first] < '0' || (s[first] > '9' && s[first] < 'A') || (s[first] > 'Z' && s[first] < 'a') || s[first] > 'z') {
				first++;
				continue;
			}
			if (s[second] < '0' || (s[second] > '9' && s[second] < 'A') || (s[second] > 'Z' && s[second] < 'a') || s[second] > 'z') {
				second--;
				continue;
			}
			//�����ַ�ת��
			if (s[first] >= 'A' && s[first] <= 'Z') s[first] = s[first] - 'A' + 'a';
			if (s[second] >= 'A' && s[second] <= 'Z') s[second] = s[second] - 'A' + 'a';
			if (s[first++] != s[second--]) return false;
		}
		return true;
	}
};