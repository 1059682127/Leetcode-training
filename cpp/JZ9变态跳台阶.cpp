/*
��Ŀ����
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
*/

class Solution {
public:
	//dp���飬˫��ѭ��
	int jumpFloorII(int number) {
		if (number < 0) return 0;

		return 1 << (number - 1);
	}
};