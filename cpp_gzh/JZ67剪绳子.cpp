/*
������

��Ŀ����
����һ������Ϊn�����ӣ�������Ӽ�����������m�Σ�m��n����������n>1����m>1��m<=n����ÿ�����ӵĳ��ȼ�Ϊk[1],...,k[m]������k[1]x...xk[m]���ܵ����˻��Ƕ��٣����磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18��
��������:
����һ����n����������档��2 <= n <= 60��
�������:
����𰸡�
ʾ��1
����
����
8
���
����
18
*/

class Solution {
public:
	//��̬�滮��
	//f(n) = max(f(i) * f(n - i)), i = 1...n-1
	int cutRope(int number) {
		if (number < 2) return 0;
		if (number == 2) return 1;
		if (number == 3) return 2;
		vector<int> dp(number + 1, 1);
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;
		for (int i = 4; i <= number; ++i) {
			int Max = 0;
			for (int j = 1; j < i / 2 + 1; ++j) {
				Max = max(Max, dp[j] * dp[i - j]);
			}
			dp[i] = Max;
		}
		return dp[number];
	}
};