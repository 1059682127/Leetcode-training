//lt240

/*
题目描述
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：


	每行的元素从左到右升序排列。
	每列的元素从上到下升序排列。


示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]


给定 target = 5，返回 true。

给定 target = 20，返回 false。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：
1、暴力法：O(mn)/O(1)
2、二分法搜索：沿着对折线，迭代min(row,col)，每次迭代进行行列二分搜索，O(lg(n!))/O(1)
3、缩减空间的思想：沿着索引行的矩阵中间列 ，matrix[row−1][mid]<target<matrix[row][mid],分为4个矩阵，删减掉左上和右下矩阵
调用递归；0(nlgn)/O(lgn)
4、修剪元素：从左下角元素开始，优先向上，不行向右O(m+n)/O(1)
这里是对“方法四”的“如何选出发点”的补充：
选左上角，往右走和往下走都增大，不能选
选右下角，往上走和往左走都减小，不能选
选左下角，往右走增大，往上走减小，可选
选右上角，往下走增大，往左走减小，可选
*/

//错误思路：先向右走到底，再向下或者向左，会漏掉情况，还有边界条件
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//先向右走到底
		int current_r = 0;
		int current_c = 0;
		int row = matrix.size();
		if (row == 0) return false;
		int col = matrix[0].size();
		if (col == 0) return false;
		if (matrix[0][0] > target) return false;
		if (matrix[0][0] == target) return true;
		for (int i = 1; i < col; i++) {
			if (matrix[0][i] < target) {
				current_c++;
			}
			else if (matrix[0][i] == target) return true;
			else {
				break;
			}
		}
		//判断能不能向下走
		while (current_r <= row - 2 && current_c > 0) {
			if (matrix[current_r + 1][current_c] < target) current_r++;
			else if (matrix[current_r + 1][current_c] == target) return true;
			else {
				//向左走
				if (matrix[current_r][current_c - 1] < target) current_c--;
				else if (matrix[current_r][current_c - 1] == target) return true;
				else return false;
			}
		}
		if
			return false;

	}
};

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//暴力求解
		int row = matrix.size();
		if (row == 0) return false;
		int col = matrix[0].size();
		if (col == 0) return false;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (matrix[i][j] == target) return true;
			}
		}
		return false;

	}
};

//二分法搜索
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//二分法搜索
		int rowNum = matrix.size();
		if (rowNum == 0 || matrix[0].size() == 0) return false;  //判断矩阵维度
		int colNum = matrix[0].size();
		int iterateNum = (rowNum > colNum ? colNum : rowNum);  //迭代次数
		for (int i = 0; i < iterateNum; i++) {
			bool vertical = binarySearch(matrix, target, i, true);  //对两个方向进行二分搜索
			bool horizontal = binarySearch(matrix, target, i, false);
			if (vertical || horizontal) return true;
		}
		return false;
	}
	bool binarySearch(vector<vector<int>>& matrix, int target, int start, bool vertical) {
		//确定搜索范围
		int lo = start;
		int hi = vertical ? matrix.size() - 1 : matrix[0].size() - 1;
		//进行二分查找
		while (lo <= hi) {
			int mid = (hi + lo) / 2;
			if (vertical) {
				if (matrix[mid][start] > target) hi = mid - 1;
				else if (matrix[mid][start] < target) lo = mid + 1;
				else {
					return true;
				}
			}
			else {
				if (matrix[start][mid] > target) hi = mid - 1;
				else if (matrix[start][mid] < target) lo = mid + 1;
				else {
					return true;
				}
			}
		}
		return false;
	}
};

//缩减空间的思想
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//缩减空间的思想
		//判断矩阵维度
		if (matrix.size() == 0 || matrix[0].size() == 0) return false;
		return searchRec(0, matrix[0].size() - 1, 0, matrix.size() - 1, matrix, target);
	}
	bool searchRec(int left, int right, int up, int down, vector<vector<int>>& matrix, int target) {
		//两种可能不存在目标：
		//1、子矩阵维度为0
		//2、目标小于数组的最小值或大于数组的最大值
		if (left > right || up > down) return false;
		if (target < matrix[up][left] || target > matrix[down][right]) return false;
		//分割矩阵
		int mid = (right + left) / 2;
		int row = up;
		while (row <= down && target >= matrix[row][mid]) {
			if (target == matrix[row][mid]) return true;
			row++;
		}
		return searchRec(left, mid - 1, row, down, matrix, target) || searchRec(mid + 1, right, up, row - 1, matrix, target);
	}

};

class Solution {
public:
	//修剪元素
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return false;
		int row = matrix.size() - 1;
		int col = 0;
		while (row >= 0 && col <= matrix[0].size() - 1) {
			if (target < matrix[row][col]) row--;   //如果当前值大于目标值，向上
			else if (target == matrix[row][col]) return true;
			else col++;  //如果当前值小于目标值，向右
		}
		return false;
	}

};