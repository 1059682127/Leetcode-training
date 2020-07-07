//lt349

/*
349. ��������Ľ���

�����������飬��дһ���������������ǵĽ�����
ʾ�� 1:
����: nums1 = [1,2,2,1], nums2 = [2,2]
���: [2]
ʾ�� 2:
����: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
���: [9,4]

//˼·1����ϣO(N)/O(N)
//˼·2������+˫ָ��+setȥ��0(N)/O(N)
//˼·2������+˫ָ��(����set),ÿ�ΰ�ָ���ƶ����ظ�Ԫ�ص����һ��
*/



class Solution {
public:
	//˼·1����ϣ���ù�ϣ���¼nums1�г��ֵ�Ԫ�أ�Ȼ�����nums2��hash_table[nums2[i]] && find(res.begin(), res.end(), nums[i]) == res.end()
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		map<int, bool> hash_table;
		//�߽�����
		for (int i = 0; i < nums1.size(); ++i) {
			hash_table[nums1[i]] = true;
		}
		vector<int> res;
		for (int i = 0; i < nums2.size(); ++i) {
			if (hash_table[nums2[i]] && find(res.begin(), res.end(), nums2[i]) == res.end()) {
				res.push_back(nums2[i]);
			}
		}
		return res;
	}
};

class Solution {
public:
	//˼·2������+˫ָ��+setȥ��

	//֪ʶ�㣺
	//set
	//���룺s.insert(1);
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		auto first = nums1.begin(), second = nums2.begin();
		set<int> s;
		while (first < nums1.end() && second < nums2.end()) {
			//�����ƶ��������˫ָ����У�������ֵС��ָ��ǰ��
			if (*first == *second) {
				s.insert(*second);
				++first;
				++second;

			}
			else if (*first < *second) {
				++first;
			}
			else {
				++second;
			}
		}
		vector<int> res(s.begin(), s.end());
		return res;
	}
};


class Solution {
public:
	//˼·2������+˫ָ��

	//֪ʶ�㣺
	//set
	//���룺s.insert(1);
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		auto first = nums1.begin(), second = nums2.begin();
		vector<int> res;
		while (first < nums1.end() && second < nums2.end()) {
			//�����ƶ��������˫ָ����У�������ֵС��ָ��ǰ��
			int cur1 = *first;
			int cur2 = *second;
			//������ں�һ��Ԫ�أ����ظ�����ָ��ѭ���ƶ�
			while (first + 1 < nums1.end()) {
				if (*(first + 1) == cur1) ++first;
				else break;
			}
			while (second + 1 < nums2.end()) {
				if (*(second + 1) == cur2) ++second;
				else break;
			}
			if (*first == *second) {
				res.push_back(*second);
				++first;
				++second;
			}
			else if (*first < *second) {
				++first;
			}
			else {
				++second;
			}
		}
		return res;
	}
};