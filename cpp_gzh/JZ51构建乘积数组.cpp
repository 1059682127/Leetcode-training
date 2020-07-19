/*
题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）
*/

class Solution {
public:
	//动态规划
	//left[i] = A[0]*A[1]*...*A[i-1], right[i] = A[i+1]*...*A[n-1]
	//B[i] = left[i] * right[i]
	//left[i + 1] = left[i] * A[i], right[i] = right[i + 1] * A[i + 1]
	//left[0] = 1, right[n - 1] = 1
	vector<int> multiply(const vector<int>& A) {
		int len = A.size();
		vector<int> left(len, 1);
		for (int i = 1; i < len; ++i) {
			left[i] = left[i - 1] * A[i - 1];
		}
		vector<int> right(len, 1);
		for (int i = len - 2; i >= 0; --i) {
			right[i] = right[i + 1] * A[i + 1];
			left[i] *= right[i];
		}
		return left;
	}
};