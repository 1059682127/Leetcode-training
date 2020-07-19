/*
�ַ����е�һ�����ظ����ַ�

��Ŀ����
��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ������磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"�����Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��
�������:
�����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���

*/

class Solution
{
public:
	//˼·�����Ƚ��ȳ����б���˳�򣬹�ϣ��ͳ�ƴ���
	//����ʱ��ֻ�д���Ϊ0�ĲŲ���
	//�ж϶���Ԫ���Ƿ��ظ��ˣ��ظ����Ƴ�
	unordered_map<int, int> charInt;
	queue<char> q;
	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (charInt[ch]++ == 0) q.push(ch);
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		while (!q.empty()) {
			if (charInt[q.front()] == 1) return q.front();
			else q.pop();
		}
		return '#';
	}

};