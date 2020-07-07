


//lt279

/*
完全平方数

给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
示例 1:
输入: n = 12
输出: 3
解释: 12 = 4 + 4 + 4.
示例 2:
输入: n = 13
输出: 2
解释: 13 = 4 + 9.
//思路1：BFS
//顺利2：动态规划
*/

//执行用时:36 ms, 在所有 C++ 提交中击败了90.08%的用户
//内存消耗 :10.7 MB, 在所有 C++ 提交中击败了80.39%的用户
class Solution {
public:
	//思路1：BFS：第一层结点13，第二层12，9，4，第三层11，8，3.。。。
	//BFS图可参考：https://leetcode-cn.com/problems/perfect-squares/solution/yan-du-you-xian-sou-suo-java-by-eiletxie/
	//Trick1:如何知道当前层数，第一层进栈13，第二层进栈12，9，4，进入下一层遍历之前先记录改层个数q.size()

	//当每一次都可以判断出多种情况，有多次的时候就适合用BFS-广度优先遍历
	//使用BFS应注意：
	//队列：用来存储每一轮遍历得到的节点；
	//标记：对于遍历过的节点（剩余值），应该将它标记，防止重复遍历。(第二次遍历到，该节点的路径长度肯定不小于第一次遍历的长度)


	int numSquares(int n) {
		queue<int> q;
		q.push(n);
		int step = 0;
		vector<bool> isVisited(n, false);
		while (!q.empty()) {
			int size = q.size();
			++step;
			while (size > 0) {   //当size == 0, 表示改成遍历完
				int cur = q.front();
				q.pop();
				--size;
				for (int i = 1; i <= sqrt(cur); i++) {
					int nextVal = cur - i * i;
					if (nextVal == 0) return step;
					if (!isVisited[nextVal]) {
						q.push(nextVal);
						isVisited[nextVal] = true;
					}

				}
			}

		}
		return -1;
	}
};

//执行用时:248 ms, 在所有 C++ 提交中击败了14.96%的用户
//内存消耗 :11.4 MB, 在所有 C++ 提交中击败了43.64%的用户
class Solution {
public:
	//思路2：动态规划
	//状态dp[i],记录每个需要的最少完全平方数
	//base：dp[i] = i,最坏的情况就是一直+1
	//状态转移：dp[i] = min(dp[i], dp[i - j^2] + 1)

	int numSquares(int n) {
		vector<int> dp(n + 1);
		for (int i = 1; i <= n; i++) {
			dp[i] = i;  //初值
			for (int j = 1; j <= sqrt(i); j++) {
				dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
		}
		return dp[n];
	}
};