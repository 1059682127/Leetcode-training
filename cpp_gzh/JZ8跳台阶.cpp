/*
��Ŀ����
һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������
*/

class Solution {
public:
	//��̬�滮������n��̨�׵���n - 1�� + 1, n - 2�� + 2
	int jumpFloor(int number) {
		if (number < 0) return 0;
		int pre = 1, prepre = 1;
		int res = 1;
		for (int i = 2; i <= number; ++i) {
			res = pre + prepre;
			prepre = pre;
			pre = res;
		}
		return res;
	}
};