//lt509

/*
斐波那契数
斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.


给定 N，计算 F(N)。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fibonacci-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
	//使用递归
	int fib(int N) {
		if (N < 2) {
			return N == 0 ? 0 : 1;
		}
		return fib(N - 1) + fib(N - 2);
	}
};


class Solution {
public:
	//使用带备忘录的递归
	//O(N)/O(N):子问题个数N，求解子问题O(1)
	int dfs(int i, vector<int> &memo) {
		if (memo[i] != 0) return memo[i];
		if (i == 0) return 0;
		if (i == 1) return 1;
		memo[i] = dfs(i - 1, memo) + dfs(i - 2, memo);
		return memo[i];
	}
	int fib(int N) {
		if (N < 1) return 0;
		vector<int> memo(N + 1, 0);
		return dfs(N, memo);
	}
};

class Solution {
public:
	//dp
	int fib(int N) {
		if (N < 1) return 0;
		vector<int> dp(N + 1, 0);
		dp[0] = 0, dp[1] = 1;
		//从小到大：
		for (int i = 2; i <= N; ++i) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[N];
	}
};