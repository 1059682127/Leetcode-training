/*
��Ŀ����
����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
*/

class Solution {
public:
	//���򣬴�С����Ȼ����һ��
	//�ȽϺ�����s1 + s2 < s2 + s1, ��s1 < s2
	static bool comp(string s1, string s2) {
		string temp1 = s1 + s2;
		string temp2 = s2 + s1;
		return temp1.compare(temp2) < 0;
	}
	string PrintMinNumber(vector<int> numbers) {
		int len = numbers.size();
		stringstream sst;
		vector<string> ss(len);
		for (int i = 0; i < len; ++i) {
			sst << numbers[i];
			sst >> ss[i];
			sst.clear();
		}
		sort(ss.begin(), ss.end(), comp);
		string res;
		for (auto s : ss) res += s;
		return res;
	}
};