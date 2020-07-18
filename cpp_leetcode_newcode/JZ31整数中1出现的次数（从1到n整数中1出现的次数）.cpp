/*
��Ŀ����
���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,���Ƕ��ں�����������û���ˡ�ACMerϣ�����ǰ����,������������ձ黯,���Ժܿ���������Ǹ�����������1���ֵĴ�������1 �� n ��1���ֵĴ�������
*/

class Solution {
public:
	//���ƣ��ҹ��ɣ�
	//ÿ��λֻ���Լ�Ϊ1ʱ�����ֵĴ���
	//��high, cur, low
	//cur = 0ʱ������high * digit
	//cur = 1ʱ������high * gigit + low + 1
	//cur > 1ʱ������(high + 1) * digit
	//��ʼ����high = n / 10, cur = n % 10, low = 0, digit = 1
	int NumberOf1Between1AndN_Solution(int n)
	{
		int res = 0, digit = 1, low = 0;
		int high = n / 10, cur = n % 10;
		while (high != 0 || cur != 0) {
			if (cur == 0) res += high * digit;
			else if (cur == 1) res += high * digit + low + 1;
			else res += (high + 1) * digit;
			low += cur * digit;
			cur = high % 10;
			high /= 10;
			digit *= 10;
		}
		return res;
	}
};