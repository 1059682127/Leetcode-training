/*
��Ŀ����
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
*/

class Solution {
public:
	//����
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