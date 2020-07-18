/*
64. ��С·����



����һ�������Ǹ������� m x n �������ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
˵����ÿ��ֻ�����»��������ƶ�һ����
ʾ��:
����:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
���: 7
����: ��Ϊ·�� 1��3��1��1��1 ���ܺ���С��
*/


class Solution {
public:
	//��̬�滮����һ�ж�Ϊ1����һ�ж�Ϊ1��
	//dp[j] = min(dp[j], dp[j - 1]);
	//return dp[j]
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0) return 0;
		int m = grid.size();
		int n = grid[0].size();
		vector<int> dp(n);
		//base case
		dp[0] = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				//��j, �������dp[-1]
				if (j == 0) dp[j] = dp[j];
				else if (i == 0) dp[j] = dp[j - 1];
				else dp[j] = min(dp[j], dp[j - 1]);
				dp[j] += grid[i][j];
			}
		}
		return dp[n - 1];
	}
};