/*
��Ŀ����
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No���������������������������ֶ�������ͬ��
*/

class Solution {
public:
	//������������ڵ���vector��󣬷��Σ��ж��������Ƿ�С�ڸ��ڵ㣬�������Ƿ񶼴��ڸ��ڵ�
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 0) return false;
		return helper(sequence, 0, sequence.size() - 1);
	}
	bool helper(vector<int> &sequence, int left, int right) {
		if (left >= right) return true;
		int rootValue = sequence[right];
		int rootIndex = left;
		for (; rootIndex < right; ++rootIndex) {
			if (sequence[rootIndex] > rootValue) break;
		}
		for (int j = rootIndex; j < right; ++j) {
			if (sequence[j] < rootValue) return false;
		}
		return helper(sequence, left, rootIndex - 1) && helper(sequence, rootIndex, right - 1);
	}
};