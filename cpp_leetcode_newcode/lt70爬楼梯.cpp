/*
70. ��¥��


������������¥�ݡ���Ҫ n ������ܵ���¥����
ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
ע�⣺���� n ��һ����������
ʾ�� 1��
���룺 2
����� 2
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 ��
2.  2 ��
*/

class Solution {
public:
	//��̬�滮��dp[i] = dp[i - 1] + dp[i - 2]
	int climbStairs(int n) {
		if (n <= 0) return 0;
		if (n == 1) return n;
		int pre = 1, prepre = 1;
		for (int i = 2; i <= n; ++i) {
			int cur = pre + prepre;
			prepre = pre;
			pre = cur;
		}
		return pre;
	}
};