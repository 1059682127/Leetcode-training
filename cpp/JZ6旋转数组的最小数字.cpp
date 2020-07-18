/*
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

class Solution {
public:
	//遍历
	int minNumberInRotateArray(vector<int> rotateArray) {
		int len = rotateArray.size();
		if (len == 0) return 0;
		if (len == 1) return rotateArray[0];
		int index = 0;
		for (; index < len - 1; ++index) {
			if (rotateArray[index] > rotateArray[index + 1]) return rotateArray[index + 1];
		}
		return rotateArray[0];
	}
};