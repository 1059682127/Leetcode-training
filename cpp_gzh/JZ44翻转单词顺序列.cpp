/*
��Ŀ����
ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼�����磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.����Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
*/

class Solution {
public:
	//������ת->�������ڣ����ո�ֹͣ�������ڷ�ת->��������һ������
	string ReverseSentence(string str) {
		if (str.size() == 0) return str;
		reverse(str.begin(), str.end());
		int l = 0, r = 0;
		while (r < str.size()) {
			if (str[r] == ' ') {
				//�����õ���
				reverseWord(str, l, r - 1);
				++r;
				l = r;
			}
			//���һ��ֹͣ
			if (r == str.size() - 1) {
				reverseWord(str, l, r);
				break;
			}
			++r;
		}
		return str;
	}
	void reverseWord(string &str, int l, int r) {
		while (l < r) {
			char temp = str[l];
			str[l] = str[r];
			str[r] = temp;
			++l;
			--r;
		}
	}
};