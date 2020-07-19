/*
��Ŀ����
����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
*/

class Solution {
public:
	//��
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (k == 0 || k > input.size()) return {};
		vector<int> heap(input.begin(), input.begin() + k);
		make_heap(heap.begin(), heap.end());  //����
		for (int i = k; i < input.size(); ++i) {
			if (input[i] < heap[0]) {
				pop_heap(heap.begin(), heap.end());  //�����Ԫ�ص�����ĩβ��������˳��
				heap.pop_back();
				heap.push_back(input[i]);
				push_heap(heap.begin(), heap.end());
			}
		}
		sort_heap(heap.begin(), heap.end());
		return heap;
	}
};