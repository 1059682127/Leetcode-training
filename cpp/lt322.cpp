//lt322

/*
322. ��Ǯ�һ�
�Ѷ�
�е�

������ͬ����Ӳ�� coins ��һ���ܽ�� amount����дһ��������������Դճ��ܽ����������ٵ�Ӳ�Ҹ��������û���κ�һ��Ӳ�����������ܽ����� -1��

ʾ�� 1:
����: coins = [1, 2, 5], amount = 11
���: 3
����: 11 = 5 + 5 + 1
ʾ�� 2:
����: coins = [2], amount = 3
���: -1
*/

class Solution {
public:
	//dp:O(kn)/O(N)
	int coinChange(vector<int>& coins, int amount) {
		//memo����ʼ��Ϊamount + 1,�൱�������
		vector<int> dp(amount + 1, amount + 1);
		//base case
		dp[0] = 0;
		for (int i = 1; i <= amount; ++i) {
			//���������,״̬ת�Ʒ���
			for (auto coin : coins) {
				if (i - coin < 0) continue; //������
				dp[i] = min(dp[i], 1 + dp[i - coin]);
			}
		}
		return dp[amount] == amount + 1 ? -1 : dp[amount];
	}
};