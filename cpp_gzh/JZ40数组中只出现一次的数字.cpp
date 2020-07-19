/*
��Ŀ����
һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
*/

class Solution {
public:
	//˼·������һ�飬���õ�num1^num2
	//�ҵ�num1^num2��һ��Ϊ1��λA
	//��Aλ�������Ϊ���飬��ͬ��������ͬһ�飬��ͬ�����ڲ�ͬ��
	//��������������ֱ�õ�num1,num2
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