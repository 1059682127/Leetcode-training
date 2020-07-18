/*
��Ŀ����
���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����

����n=3ʱ��2*3�ľ��ο���3�ָ��Ƿ�����
*/

class Solution {
public:
	//��̬�滮��f(1) = 1
	//f(n) = f(n - 1,�������) + f(n - 2, �ұ�)
	int rectCover(int number) {

		vector<int> dp(number + 1);
		dp[0] = 0;
		dp[1] = 1, dp[2] = 2;
		for (int i = 3; i <= number; ++i) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[number];
	}
};