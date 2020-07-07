//lt887

/*
题目描述
你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。
每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。
你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。
每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。
你的目标是确切地知道 F 的值是多少。
无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？


示例 1：
输入：K = 1, N = 2
输出：2
解释：
鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
如果它没碎，那么我们肯定知道 F = 2 。
因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。
示例 2：
输入：K = 2, N = 6
输出：3
示例 3：
输入：K = 3, N = 14
输出：4

提示：
1 <= K <= 100
1 <= N <= 10000

思路：
1、最直接的是线性扫描：O(N)
2、如果鸡蛋不限，最优肯定是二分法:O(logN)
3、如果鸡蛋限制，可以考虑用二分法加线性扫描，或者五分法线性扫描
4、动态规划：O(KN^2)/O(KN)
作者：labuladong
链接：https://leetcode-cn.com/problems/super-egg-drop/solution/ji-ben-dong-tai-gui-hua-jie-fa-by-labuladong/
（1）状态：很明显，就是当前拥有的鸡蛋数 K 和需要测试的楼层数 N
（2）选择：其实就是去选择哪层楼扔鸡蛋i。
所以算法框架:
# 当前状态为 K 个鸡蛋，面对 N 层楼
# 返回这个状态下的最优结果
def dp(K, N):
	int res
	for 1 <= i <= N:
		res = min(res, 这次在第 i 层楼扔鸡蛋)
	return res

（3）状态转移:
如果鸡蛋碎了，那么鸡蛋的个数 K 应该减一，搜索的楼层区间应该从 [1..N] 变为 [1..i-1] 共 i-1 层楼；
如果鸡蛋没碎，那么鸡蛋的个数 K 不变，搜索的楼层区间应该从  [1..N] 变为 [i+1..N] 共 N-i 层楼。
要求的是最坏情况下扔鸡蛋的次数，所以鸡蛋在第 i 层楼碎没碎，取决于那种情况的结果更大：

（4）递归的 base case 很容易理解：当楼层数 N 等于 0 时，显然不需要扔鸡蛋；当鸡蛋数 K 为 1 时，显然只能线性扫描所有楼层：

5、二分查找优化:0(K*N*logN)/O(K*N)
参考labuladong的说法：其实状态转移方程min(max(f1,f2))f1递增，f2递减，其实就是求山谷值,可以用二分搜索
6、重新定义状态转移



知识点：
1、动态规划：
（1）基本思路：有什么「状态」，有什么「选择」，然后穷举。
（2）时间复杂度：动态规划算法的时间复杂度就是子问题个数 × 函数本身的复杂度。
函数本身的复杂度是忽略递归部分；子问题就是不同状态组合的总数



*/


//动态规划，会超过时间限制
class Solution {
public:
	int superEggDrop(int K, int N) {
		int res = INT_MAX;

		//base case
		if (N == 0) return 0;
		if (K == 1) return N;
		//状态转移
		for (int i = 1; i <= N; i++) {
			res = min(res,
				max(superEggDrop(K, N - i), superEggDrop(K - 1, i - 1)) + 1);  //最后情况去两边大值，加上i层摔一次
		}
		return res;
	}
};


//动态规划+备忘录，同样会超出时间
class Solution {
public:
	

	int superEggDrop(int K, int N) {
		vector<vector<int>> matrix(K + 1, vector<int>(N + 1));
		return helper2(K, N, matrix);
	}
	int helper2(int K, int N, vector<vector<int>>& matrix) {
		int res = INT_MAX;
		if (matrix[K][N] != 0) return matrix[K][N];  //备忘录避免重复计算
		//base case
		if (N == 0) return 0;
		if (K == 1) return N;
		//状态转移
		for (int i = 1; i <= N; i++) {
			res = min(res,
				max(helper2(K, N - i,matrix ), helper2(K - 1, i - 1, matrix)) + 1);  //最后情况去两边大值，加上i层摔一次
		}
		matrix[K][N] = res; //更新备忘录
		return res;
	}
};

//动态规划+备忘录+二分搜索
class Solution {
public:
	int superEggDrop(int K, int N) {
		vector<vector<int>> matrix(K + 1, vector<int>(N + 1));
		return helperBinarySearch(K, N, matrix);
	}
	int helperBinarySearch(int K, int N, vector<vector<int>>& matrix) {
		int res = INT_MAX;
		if (matrix[K][N] != 0) return matrix[K][N];  //备忘录避免重复计算
		//base case
		if (N == 0) return 0;
		if (K == 1) return N;
		//二分搜索找到最小值
		int lo = 1, hi = N;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			int notBroken = helperBinarySearch(K, N - mid, matrix);
			int broken = helperBinarySearch(K - 1, mid - 1, matrix);
			if (notBroken >= broken) {
				lo = mid + 1;
				res = min(res, notBroken + 1);
			}
			else {
				hi = mid - 1;
				res = min(res, broken + 1);
			}
		}
		matrix[K][N] = res; //更新备忘录
		return res;
	}
};