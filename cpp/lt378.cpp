//lt378

/*
��������е�KС��Ԫ��

����һ�� n x n ��������ÿ�к�ÿ��Ԫ�ؾ������������ҵ������е�kС��Ԫ�ء�
��ע�⣬���������ĵ�kСԪ�أ������ǵ�k��Ԫ�ء�
ʾ��:
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

���� 13��
˵��:
����Լ��� k ��ֵ��Զ����Ч��, 1 �� k �� n2 ��

//˼·1�����Ƽ������ѣ������������еĵ�K�����Ԫ��O(n^2logk)/O(k)
//˼·2������������=�ţ����ֲ��ң�����mid,left,right,
*/


//ִ����ʱ:96 ms, ������ C++ �ύ�л�����12.03%���û�
//�ڴ����� :13.5 MB, ������ C++ �ύ�л�����13.08%���û�
class Solution {
public:
	//˼·1�����ѣ������������еĵ�K�����Ԫ��O(n^2logk)/O(k)
	//���ֶѵĳ���Ϊk����󷵻ضѶ�
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

//ִ����ʱ:36 ms, ������ C++ �ύ�л�����80.25%���û�
//�ڴ����� :12.1 MB, ������ C++ �ύ�л�����52.46%���û�
class Solution {
public:
	//˼·2:���ֲ��ң�����mid,left,right,
	//���С�ڵ���mid�ĸ���count < k, ��left = mid + 1; right = right;
	//������ڵ���mid�ĸ���count >= k, ��left = left; right = mid;(���ܰ���mid)
	//ÿ��ѭ���ж���֤�˵�kС������left~right֮�䣬��left==rightʱ����kС���������ҳ�������right
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
		//���в���
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (matrix[i][j] <= mid) count++;
				else break;
			}
		}
		return count;
	}
};