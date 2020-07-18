/*
167. ����֮�� II - ������������
�Ѷ�
��

326





����һ���Ѱ����������� ���������飬�ҵ�������ʹ���������֮�͵���Ŀ������
����Ӧ�÷����������±�ֵ index1 �� index2������ index1 ����С�� index2��
˵��:
���ص��±�ֵ��index1 �� index2�����Ǵ��㿪ʼ�ġ�
����Լ���ÿ������ֻ��ӦΨһ�Ĵ𰸣������㲻�����ظ�ʹ����ͬ��Ԫ�ء�
ʾ��:
����: numbers = [2, 7, 11, 15], target = 9
���: [1,2]
����: 2 �� 7 ֮�͵���Ŀ���� 9 ����� index1 = 1, index2 = 2 ��

*/



class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		//�߽�
		int len = nums.size();
		if (len == 0) return {};
		int l = 0, r = len - 1;
		while (l <= r) {
			int sum = nums[l] + nums[r];
			if (sum == target) return { l + 1, r + 1 };
			else if (sum < target) ++l;
			else --r;
		}
		return {};
	}
};