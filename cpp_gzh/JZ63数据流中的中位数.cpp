/*
�������е���λ��

��Ŀ����
��εõ�һ���������е���λ����������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ������ʹ��Insert()������ȡ��������ʹ��GetMedian()������ȡ��ǰ��ȡ���ݵ���λ����
*/

class Solution {
public:
	//˫�ѣ��󶥶�+С���ѣ������ִ󶥶Ѹ��� == С���Ѹ�����ż����ȡ���Ѷ�ƽ����  ���� == С���Ѹ��� + 1��������ȡ�󶥶ѶѶ���
	//������ż��(���Ѹ������)����Ԫ�ز���С���ѣ�Ȼ��С���ѶѶ����󶥶�
	//�������������󶥶Ѹ�����1��������Ԫ�ز���󶥶ѣ�Ȼ��󶥶ѶѶ���С����
	priority_queue<int> bq;
	priority_queue<int, vector<int>, greater<int>> sq;  //С����
	int number = 0;
	void Insert(int num)
	{
		//�߽�����
		if (number % 2 == 0) {
			sq.push(num);
			bq.push(sq.top());
			sq.pop();
		}
		else {
			bq.push(num);
			sq.push(bq.top());
			bq.pop();
		}
		++number;
	}

	double GetMedian()
	{
		if (number % 2 == 0) return (double)(bq.top() + sq.top()) / 2;
		else return (double)bq.top();
	}

};