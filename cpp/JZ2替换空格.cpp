/*
��Ŀ����
��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*/

class Solution {
public:
	//˫ָ�룬���ո���num->���ַ�������->�Ӻ���ǰ�ƶ��ַ���
	//�³��ȣ�length + num * 2
	void replaceSpace(char *str, int length) {
		if (str == NULL || length == 0) return;
		int num = 0;
		for (int i = 0; i < length; ++i) {
			if (str[i] == ' ') ++num;
		}
		//�����滻
		char *p1 = str + length - 1;
		char *p2 = str + length + num * 2 - 1;
		//���и���
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