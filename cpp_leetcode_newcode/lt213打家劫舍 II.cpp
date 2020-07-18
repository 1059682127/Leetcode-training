
/*

213. ��ҽ��� II


����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݣ�ÿ�䷿�ڶ�����һ�����ֽ�����ط����еķ��ݶ�Χ��һȦ������ζ�ŵ�һ�����ݺ����һ�������ǽ����ŵġ�ͬʱ�����ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������
����һ������ÿ�����ݴ�Ž��ķǸ��������飬�������ڲ���������װ�õ�����£��ܹ�͵�Ե�����߽�
ʾ�� 1:
����: [2,3,2]
���: 3
����: �㲻����͵�� 1 �ŷ��ݣ���� = 2����Ȼ��͵�� 3 �ŷ��ݣ���� = 2��, ��Ϊ���������ڵġ�
*/


class Solution {
public:
	//��̬�滮
	//���εĻ���nums[0]ѡ�У���num[i - 1]����ѡ
	int rob(vector<int>& nums) {
		int len = nums.size();
		if (len <= 0) return 0;
		if (len == 1) return nums[0];
		return max(rob(nums, 0, len - 2), rob(nums, 1, len - 1));
	}
	int rob(vector<int>& nums, int l, int r) {
		int pre = 0, prepre = 0;
		for (int i = l; i <= r; ++i) {
			int cur = max(prepre + nums[i], pre);
			prepre = pre;
			pre = cur;
		}
		return pre;
	}
};