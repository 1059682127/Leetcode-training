/*
题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/

class Solution {
public:
	//思路：遍历一遍，异或得到num1^num2
	//找到num1^num2第一个为1的位A
	//按A位将数组分为两组，相同的数必在同一组，不同的数在不同组
	//对两个组进行异或分别得到num1,num2
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		//0^a = 1, a ^ a = 0 
		int xor1 = 0;
		for (int i = 0; i < data.size(); ++i) {
			xor1 ^= data[i];
		}
		int index = 1;
		while ((index & xor1) == 0) index = index << 1;
		int result1 = 0, result2 = 0;
		for (int i = 0; i < data.size(); ++i) {
			if ((data[i] & index) == 0) result1 ^= data[i];
			else result2 ^= data[i];
		}
		cout << result1 << result2 << endl;
		num1[0] = result1;
		num2[0] = result2;
	}
};