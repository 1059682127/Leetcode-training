/*
��Ŀ����
LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...��������г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣���������A,����3,С��,����,��Ƭ5��,��Oh My God!������˳��.....LL��������,��������,������\С �����Կ����κ�����,����A����1,JΪ11,QΪ12,KΪ13�������5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),��So Lucky!����LL����ȥ��������Ʊ���� ����,Ҫ����ʹ�������ģ������Ĺ���,Ȼ���������LL��������Σ� ����������˳�Ӿ����true����������false��Ϊ�˷������,�������Ϊ��С����0��
*/

class Solution {
public:
	//��set
	//���⣺����Ϊ5���Ҳ��ظ������ֵ����Сֵ��С��5
	//0����С������Ҫ����set��0�ĸ���+set�ĸ���Ϊ5
	bool IsContinuous(vector<int> numbers) {
		int len = numbers.size();
		if (len < 5 || len > 5) return false;
		set<int> s;
		int sizezero = 0;
		for (int i = 0; i < len; ++i) {
			if (numbers[i] == 0) ++sizezero;
			else {
				s.insert(numbers[i]);
			}
		}
		if (s.size() + sizezero != 5) return false;
		int Min = *s.begin();
		int Max = *s.rbegin();
		if (abs(Max - Min) >= 5) return false;
		return true;
	}
};