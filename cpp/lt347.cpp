//lt347

/*
 ǰ K ����ƵԪ��

����һ���ǿյ��������飬�������г���Ƶ��ǰ k �ߵ�Ԫ�ء�
ʾ�� 1:
����: nums = [1,1,1,2,2,3], k = 2
���: [1,2]
ʾ�� 2:
����: nums = [1], k = 1
���: [1]
˵����
����Լ�������� k ���Ǻ���ģ��� 1 �� k �� �����в���ͬ��Ԫ�صĸ�����
����㷨��ʱ�临�Ӷȱ������� O(n log n) , n ������Ĵ�С��

//˼·1���ù�ϣ���¼�������ô󶥶Ѽ�¼Ƶ��,
*/


//ִ����ʱ:20 ms, ������ C++ �ύ�л�����86.03%���û�
//�ڴ����� :11.6 MB, ������ C++ �ύ�л�����13.19%���û�
class Solution {
public:
	//˼·1���ù�ϣ���¼�������ô󶥶Ѽ�¼Ƶ��,

	//Trick1:����ô�ȼ�¼Ƶ�ʣ��ּ�¼��Ӧ������ʹ����ż�ṹ<x,y>
	//Trick2:���ж���ȽϺ���comp
	//֪ʶ�㣺
	//1������ʹ��pair��vector:vector<pair<int, int>> ivec_p;
	//2�����vector����pair:ivec_p.push_back(make_pair<int, int>(x, y));
	//3������Ԫ�ص�ֵ��vector<pair<int, int>>::iterator it; it->first;
	//4��pop_heap() ��������һ��Ԫ���Ƶ���󣬲���֤ʣ�µ�Ԫ����Ȼ��һ���ѡ������������Ƴ�
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> hash_table;
		for (auto& num : nums) {
			hash_table[num]++;
		}
		using value_v = pair<int, int>;
		vector<value_v> container(hash_table.begin(), hash_table.end());
		auto comp = [](const value_v& v1, const value_v& v2) {return v1.second < v2.second; };
		make_heap(container.begin(), container.end(), comp);

		vector<int> res;
		for (int i = 0; i < k; i++) {
			res.push_back(container.begin()->first);
			pop_heap(container.begin(), container.end() - i, comp);  //��Ҫ����ͬ�ıȽϺ���
		}

		return res;
	}
};