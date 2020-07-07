//lt179

/*
�����

����һ��Ǹ������������������ǵ�˳��ʹ֮���һ������������
ʾ�� 1:
����: [10,2]
���: 210
ʾ�� 2:
����: [3,30,34,5,9]
���: 9534330
*/


class Solution {
public:
	//˼·��1���Զ���ȽϷ�ʽ���ٵ���sort������
	//����ıȽ��㷨Ӧ���Ƕ���Ϻ�����ֽ��бȽ�,���磺4��30��430 > 304������4��ǰ��
	//����������ķ�ʽ�������������� (a * (b ��λ��) + b) ��ʵ�ֽ�����������ϵ�һ��

	//֪ʶ�㣺intת�ַ���to_string(int)
	//����int��Χ������long long 
	//f_sort2���ַ����ȽϹ�ܷ�Χ����
	string largestNumber(vector<int>& nums) {
		auto f_sort = [](const int &a, const int &b) {
			long long n_a = 10, n_b = 10;
			while (a / n_a) n_a *= 10;
			while (b / n_b) n_b *= 10;
			long long l_a = (long long)a * n_b + (long long)b;
			long long l_b = (long long)b * n_a + (long long)a;
			return l_a > l_b;
		};

		auto f_sort2 = [](const int &a, const int &b) {
			string sa = to_string(a);
			string sb = to_string(b);
			return sa + sb > sb + sa;
		};
		sort(nums.begin(), nums.end(), f_sort);
		string res;
		for (int i = 0; i < nums.size(); ++i) {
			res = (res == "0") ? to_string(nums[i]) : res += to_string(nums[i]);  //��Ҫ����["0", "0"]�������
		}
		return res;
	}

};