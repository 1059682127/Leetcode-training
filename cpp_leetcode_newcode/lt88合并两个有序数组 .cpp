//lt89

/*
题目：
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:


	初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
	你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。


示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

思路：
1、三指针，从右往前：统计个数m+n，三指针，从后往前遍历，将两者较大的数往nums1[m+n-1放]。。。O(m+n)/O(1)
2、合并后sort:O((m+n)log(m+n))/O(1)
3、双指针，从前往后：O(m+n)/O(m+n)

*/

//三指针法
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		//统计个数m+n，三指针，从后往前遍历，将两者较大的数往nums1[m+n-1放]。。。
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