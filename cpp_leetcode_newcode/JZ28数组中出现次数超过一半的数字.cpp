/*
��Ŀ����
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
*/

class Solution {
public:
	//˼·1:����ȡ�м�ֵ
	//˼·2������prevalue,��ֵͬcount++,��ֵͬcount--,count == 0ʱ����preValue;����preValueΪres
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int len = numbers.size();
		if (len == 0) return -1;
		int preValue = numbers[0];

		int count = 1;
		for (int i = 1; i < len; ++i) {
			if (count == 0) {
				preValue = numbers[i];
				count = 1;
			}
			else {
				if (numbers[i] == preValue) ++count;
				else --count;
			}
		}
		//�жϸ����Ƿ���ĳ���һ��
		int num = 0;
		for (auto z : numbers) {
			if (z == preValue) ++num;
		}
		return (num > len / 2) ? preValue : 0;
	}
};