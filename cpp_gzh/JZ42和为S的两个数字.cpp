/*
��Ŀ����
����һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
�������:
��Ӧÿ�����԰����������������С���������
*/

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		if (array.empty()) return vector<int>();
		int tmp = INT_MAX;
		pair<int, int> ret;
		unordered_map<int, int> mp;
		for (int i = 0; i < array.size(); ++i) {
			mp[array[i]] = i;
		}
		for (int i = 0; i < array.size(); ++i) {
			if (mp.find(sum - array[i]) != mp.end()) {
				int j = mp[sum - array[i]];
				if (j > i && array[i] * array[j] < tmp) {
					tmp = array[i] * array[j];
					ret = { i, j };
				}
			}
		}
		if (ret.first == ret.second) return vector<int>();
		return vector<int>({ array[ret.first], array[ret.second] });

	}
};