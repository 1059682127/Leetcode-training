/*
��Ŀ����
�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ������,�����������е�����Ե�����P������P��1000000007ȡģ�Ľ������� �����P%1000000007
��������:
��Ŀ��֤�����������û�е���ͬ������
���ݷ�Χ��
	����%50������,size<=10^4
	����%75������,size<=10^5
	����%100������,size<=2*10^5
*/

class Solution {
public:
	//˼·���鲢����ͳ���������
	int num;
	void merge(vector<int> &data, int first, int mid, int second) {
		if (first > second) return;
		int len = second - first + 1;
		vector<int> copyArr(len);
		//��ָ��
		int index = 0, p1 = first, p2 = mid + 1;
		//ͳ�����������ͬʱ���н���
		while (p1 <= mid && p2 <= second) {
			if (data[p1] <= data[p2]) copyArr[index++] = data[p1++];
			else {
				//���A������a1>B������b1����a1�����Ԫ��Ҳ����b1
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