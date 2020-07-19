/*
��Ŀ����
����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]������ʹ�ó�������ע�⣺�涨B[0] = A[1] * A[2] * ... * A[n-1]��B[n-1] = A[0] * A[1] * ... * A[n-2];��
*/

class Solution {
public:
	//��̬�滮
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