//lt89

/*
��Ŀ��
�������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣

˵��:


	��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n��
	����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�


ʾ��:

����:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

���: [1,2,2,3,5,6]

˼·��
1����ָ�룬������ǰ��ͳ�Ƹ���m+n����ָ�룬�Ӻ���ǰ�����������߽ϴ������nums1[m+n-1��]������O(m+n)/O(1)
2���ϲ���sort:O((m+n)log(m+n))/O(1)
3��˫ָ�룬��ǰ����O(m+n)/O(m+n)

*/

//��ָ�뷨
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		//ͳ�Ƹ���m+n����ָ�룬�Ӻ���ǰ�����������߽ϴ������nums1[m+n-1��]������
		if (m == 0) nums1 = nums2;
		if (n == 0) return;
		int first = m - 1;
		int second = n - 1;
		int third = m + n - 1;
		while (first >= 0 && second >= 0) {
			nums1[third--] = (nums1[first] > nums2[second]) ? nums1[first--] : nums2[second--];
		}
		for (int i = 0; i <= second; i++) {
			nums1[i] = nums2[i];
		}
	}
};