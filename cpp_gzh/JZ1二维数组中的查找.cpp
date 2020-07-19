/*
��Ŀ����
��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
*/

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int rowCount = array.size();
		int colCount = array[0].size();
		for (int i = rowCount - 1, j = 0; i >= 0 && j < colCount;) {
			if (array[i][j] == target) {
				return true;
			}
			if (array[i][j] > target) {
				i--;
				continue;
			}
			if (array[i][j] < target) {
				j++;
				continue;
			}
		}
		return false;
	}
};