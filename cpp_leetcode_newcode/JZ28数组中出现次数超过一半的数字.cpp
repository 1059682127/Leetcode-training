/*
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/

class Solution {
public:
	//思路1:排序，取中间值
	//思路2：设置prevalue,相同值count++,不同值count--,count == 0时更换preValue;最后的preValue为res
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int len = numbers.size();
		if (len == 0) return -1;
		int preValue = numbers[0];

		int count = 1;
		for (int i = 1; i < len; ++i) {
			if (count == 0) {
				preValue = numbers[i];
				count = 1;
			}
			else {
				if (numbers[i] == preValue) ++count;
				else --count;
			}
		}
		//判断该数是否真的超过一半
		int num = 0;
		for (auto z : numbers) {
			if (z == preValue) ++num;
		}
		return (num > len / 2) ? preValue : 0;
	}
};