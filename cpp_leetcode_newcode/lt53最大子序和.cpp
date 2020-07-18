
/*
53. ��������



����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
ʾ��:
����: [-2,1,-3,4,-1,2,1,-5,4],
���: 6
����: ���������� [4,-1,2,1] �ĺ����Ϊ 6��
����:
������Ѿ�ʵ�ָ��Ӷ�Ϊ O(n) �Ľⷨ������ʹ�ø�Ϊ����ķ��η���⡣
*/

class Solution {
public:
	//һ�α���������ֵ����
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		if (len <= 0) return 0;
		int sumCur = nums[0];
		int Max = nums[0];
		for (int i = 1; i < len; ++i) {
			sumCur = sumCur > 0 ? sumCur + nums[i] : nums[i];  //����֮ǰ���ܺ�
			Max = max(Max, sumCur);
		}
		return Max;
	}
};