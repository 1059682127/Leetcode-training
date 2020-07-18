//lt35

/*
35. ��������λ��

����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�

����Լ������������ظ�Ԫ�ء�

ʾ�� 1:

����: [1,3,5,6], 5
���: 2


ʾ�� 2:

����: [1,3,5,6], 2
���: 1


ʾ�� 3:

����: [1,3,5,6], 7
���: 4

//˼·1�����ֲ���O(logN)/O(logN)
//˼·2�����ֲ���(�Ż��߽�����)
//˼·3�����ֲ��ң�ѭ����

//Trick��һֱ���Σ��п��ܳ���lo > hi���������ʱreturn lo;
*/

class Solution {
public:
	//˼·1�����ֲ���

	int searchInsert(vector<int>& nums, int target) {
		return helper(nums, 0, nums.size() - 1, target);
	}
	int helper(vector<int>& nums, int lo, int hi, int target) {
		//�߽�����
	//    if(lo > hi) return hi;
		int mid = (lo + hi) / 2;
		if (nums[mid] == target) return mid;
		//�����Ŀ�꣬�������
		else if (nums[mid] > target) {
			if (mid - 1 < lo) return mid;
			else return helper(nums, lo, mid - 1, target);
		}
		else {
			if (mid + 1 > hi) return mid + 1;
			return helper(nums, mid + 1, hi, target);
		}
	}
};

class Solution {
public:
	//˼·2�����ֲ���(�Ż��߽�����)

	int searchInsert(vector<int>& nums, int target) {
		return helper(nums, 0, nums.size() - 1, target);
	}
	int helper(vector<int>& nums, int lo, int hi, int target) {
		//�߽�����
		if (lo > hi) return lo;
		int mid = (lo + hi) / 2;
		if (nums[mid] == target) return mid;
		//�����Ŀ�꣬�������
		else if (nums[mid] > target) {
			return helper(nums, lo, mid - 1, target);
		}
		else {
			return helper(nums, mid + 1, hi, target);
		}
	}
};


class Solution {
public:
	//˼·3�����ֲ��ң�ѭ����
	//O(logN)/O(1)

	int searchInsert(vector<int>& nums, int target) {
		int lo = 0;
		int hi = nums.size() - 1;
		//�߽�����
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (nums[mid] == target) return mid;
			//�����Ŀ�꣬�������
			else if (nums[mid] > target) {
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
		return lo;   //�������lo > hi,����lo
	}
};