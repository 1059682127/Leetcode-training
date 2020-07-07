//lt378

/*
有序矩阵中第K小的元素

给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
请注意，它是排序后的第k小元素，而不是第k个元素。
示例:
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
说明:
你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n2 。

//思路1：（推荐）最大堆，类似于数组中的第K个最大元素O(n^2logk)/O(k)
//思路2：（容器混淆=号）二分查找，定义mid,left,right,
*/


//执行用时:96 ms, 在所有 C++ 提交中击败了12.03%的用户
//内存消耗 :13.5 MB, 在所有 C++ 提交中击败了13.08%的用户
class Solution {
public:
	//思路1：最大堆，类似于数组中的第K个最大元素O(n^2logk)/O(k)
	//保持堆的长度为k，最后返回堆顶
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<int> data;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				data.push(matrix[i][j]);
				if (data.size() > k) {
					data.pop();
				}
			}
		}
		return data.top();
	}
};

//执行用时:36 ms, 在所有 C++ 提交中击败了80.25%的用户
//内存消耗 :12.1 MB, 在所有 C++ 提交中击败了52.46%的用户
class Solution {
public:
	//思路2:二分查找，定义mid,left,right,
	//如果小于等于mid的个数count < k, 则left = mid + 1; right = right;
	//如果大于等于mid的个数count >= k, 则left = left; right = mid;(可能包括mid)
	//每次循环中都保证了第k小的数在left~right之间，当left==right时，第k小的数即被找出，等于right
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int row = matrix.size();
		int col = matrix[0].size();
		int left = matrix[0][0], right = matrix[row - 1][col - 1];

		while (left < right) {
			int mid = (left + right) / 2;
			int count = findNotBiggerThanMid(matrix, row, col, mid);
			if (count < k) {
				left = mid + 1;
				right = right;
			}
			else {
				left = left;
				right = mid;
			}
		}
		return right;
	}
	int findNotBiggerThanMid(vector<vector<int>>& matrix, int row, int col, int mid) {
		int count = 0;
		//以行查找
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (matrix[i][j] <= mid) count++;
				else break;
			}
		}
		return count;
	}
};