/*
��Ŀ����
ͳ��һ�����������������г��ֵĴ�����
*/

class Solution {
public:
	//���ַ�
	int lower_bound(vector<int> &data, int k) {
		int lo = 0, hi = data.size() - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			//>k, ��߼����� = k�� ��߼����� < k ,�ұ�
			if (data[mid] < k) lo = mid + 1;
			else hi = mid - 1;
		}
		return lo;
	}
	int higher_bound(vector<int> &data, int k) {
		int lo = 0, hi = data.size() - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			//>k, ��߼����� = k�� �ұ߼����� < k ,�ұ�
			if (data[mid] <= k) lo = mid + 1;
			else hi = mid - 1;
		}
		return lo;
	}
	int GetNumberOfK(vector<int> data, int k) {
		//���ַ��ҵ���˵�
		int l = lower_bound(data, k);
		int r = higher_bound(data, k);
		return r - l;
	}
};