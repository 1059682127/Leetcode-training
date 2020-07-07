//lt152

/*
�˻����������

����һ���������� nums ���ҳ�һ�������г˻��������������У����������ٰ���һ��������
ʾ�� 1:
����: [2,3,-2,4]
���: 6
����: ������ [2,3] �����˻� 6��
ʾ�� 2:
����: [-2,0,-1]
���: 0
����: �������Ϊ 2, ��Ϊ [-2,-1] ���������顣

˼·��
1����̬�滮O(N)/O(N)
2��ֱ������������ˣ����Ǹ����ĸ�����ż��������ֱ����ˣ������������֣���������һ��������������/���������һ�������������飩
�μӣ�https://leetcode-cn.com/problems/maximum-product-subarray/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--36/
*/

//˼·1����̬�滮
class Solution {
public:
	//˼·����̬�滮
	//�������鲻�ϸ��������
	//��ǰ���ֵimax = max(imax*nums[i], imax);
	//���ڸ����Ĵ��ڣ���ʹ��С�ı�Ϊ���ģ����ı�Ϊ��С�ģ���˻�Ҫά��imin��imin = min(imin*nums[i], imin);
	//�����ָ���ʱ��imax,imin����������һ������
	int maxProduct(vector<int>& nums) {
		int Max = INT_MIN, imax = 1, imin = 1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] < 0) {
				int temp = imax;
				imax = imin;
				imin = temp;

			}
			//����ֵ
			imax = max(imax * nums[i], nums[i]);
			imin = min(imin * nums[i], nums[i]);
			Max = max(imax, Max);
		}
		return Max;
	}

};

//˼·2��ֱ�����
class Solution {
public:
	//˼·��ֱ�����,�ֱ��ͷ�ʹ�β��һ��
	int maxProduct(vector<int>& nums) {
		int res = INT_MIN;
		//��ͷ��һ��
		int MaxL = 1;
		for (int i = 0; i < nums.size(); i++) {
			MaxL = MaxL * nums[i];
			res = max(res, MaxL);
			//����0�����
			if (MaxL == 0) MaxL = 1;
		}
		int MaxR = 1;
		for (int i = nums.size() - 1; i >= 0; i--) {
			MaxR = MaxR * nums[i];
			res = max(res, MaxR);
			if (MaxR == 0) MaxR = 1;
		}
		return res;
	}

};