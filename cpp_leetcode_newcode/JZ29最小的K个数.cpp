/*
题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

class Solution {
public:
	//堆
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (k == 0 || k > input.size()) return {};
		vector<int> heap(input.begin(), input.begin() + k);
		make_heap(heap.begin(), heap.end());  //建堆
		for (int i = k; i < input.size(); ++i) {
			if (input[i] < heap[0]) {
				pop_heap(heap.begin(), heap.end());  //将最大元素调整至末尾，并调整顺序
				heap.pop_back();
				heap.push_back(input[i]);
				push_heap(heap.begin(), heap.end());
			}
		}
		sort_heap(heap.begin(), heap.end());
		return heap;
	}
};