/*
题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

class Solution {
public:
	//后序遍历，根节点在vector最后，分治，判断左子树是否都小于根节点，右子树是否都大于根节点
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