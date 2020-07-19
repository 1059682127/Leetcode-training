/*
题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
输入描述:
题目保证输入的数组中没有的相同的数字
数据范围：
	对于%50的数据,size<=10^4
	对于%75的数据,size<=10^5
	对于%100的数据,size<=2*10^5
*/

class Solution {
public:
	//思路：归并排序，统计逆序对数
	int num;
	void merge(vector<int> &data, int first, int mid, int second) {
		if (first > second) return;
		int len = second - first + 1;
		vector<int> copyArr(len);
		//三指针
		int index = 0, p1 = first, p2 = mid + 1;
		//统计逆序对数，同时进行交换
		while (p1 <= mid && p2 <= second) {
			if (data[p1] <= data[p2]) copyArr[index++] = data[p1++];
			else {
				//如果A数组中a1>B数组中b1，则a1后面的元素也大于b1
				copyArr[index++] = data[p2++];
				num = (num + mid - p1 + 1) % 1000000007;
			}
		}
		while (p1 <= mid) {
			copyArr[index++] = data[p1++];

		}
		while (p2 <= second) copyArr[index++] = data[p2++];
		for (int i = 0; i < len; ++i) data[first + i] = copyArr[i];
	}
	void mergeSort(vector<int> &data, int first, int second) {
		if (first == second) return;
		int mid = (first + second) / 2;
		mergeSort(data, first, mid);
		mergeSort(data, mid + 1, second);
		merge(data, first, mid, second);
	}
	int InversePairs(vector<int> data) {
		num = 0;
		int len = data.size();
		mergeSort(data, 0, len - 1);
		return num % 1000000007;
	}
};