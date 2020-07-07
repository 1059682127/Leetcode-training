//lt334

/*
 ��������Ԫ������

����һ��δ��������飬�ж�����������Ƿ���ڳ���Ϊ 3 �ĵ��������С�
��ѧ���ʽ����:
������������� i, j, k,  ������ 0 �� i < j < k �� n-1��
ʹ�� arr[i] < arr[j] < arr[k] ������ true ; ���򷵻� false ��
˵��: Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(n)���ռ临�Ӷ�Ϊ O(1) ��
ʾ�� 1:
����: [1,2,3,4,5]
���: true
ʾ�� 2:
����: [5,4,3,2,1]
���: false

//˼·1��������O(N^3))/O(1)
//���Ƽ���˼·2��˫ָ�룬�趨small,mid,�������飬����small,mid,�ҵ���mid��ķ�true O(N)/O(1)
//˼·3:��̬�滮O(N^2)/O(N)
//˼·4:ǰ�����O(N)/O(N)
*/


//ִ����ʱ:320 ms, ������ C++ �ύ�л�����6.00%���û�
//�ڴ����� :9.2 MB, ������ C++ �ύ�л�����5.34%���û�
class Solution {
public:
	//˼·1��������O(N^3))/O(1),������O(N)
	bool increasingTriplet(vector<int>& nums) {
		int len = nums.size();
		for (int i = 0; i <= len - 3; i++) {
			for (int j = i + 1; j <= len - 2; j++) {
				if (nums[i] < nums[j]) {
					for (int k = j + 1; k <= len - 1; k++) {
						if (nums[j] < nums[k]) return true;
					}
				}
			}
		}
		return false;
	}
};


class Solution {
public:
	//˼·2��˫ָ�룬�趨small,mid,�������飬����small,mid,�ҵ���mid��ķ�true
	//Trick1:������smallС��Ҫ���£�[3,5]����1,2��Ҫ����small,��ֹ���[1,2,3]
	//Trick2:������small�󣬱�midС�ģ�����mid����Ϊ�����С���м�ֵ���ò����⣬��ô����false��
	//Trick3:����֮��small��mid���������ܱ�֤��������������mid֮ǰ�б�small���midС�ĳ��֣�ֻҪ�����ҵ���mid��ļ���
	//�ο���https://leetcode-cn.com/problems/increasing-triplet-subsequence/solution/c-xian-xing-shi-jian-fu-za-du-xiang-xi-jie-xi-da-b/
	bool increasingTriplet(vector<int>& nums) {
		int len = nums.size();
		if (len < 3) return false;
		int small = INT_MAX, mid = INT_MAX;
		for (auto num : nums) {
			if (num <= small) {
				small = num;
			}
			else if (num <= mid) {
				mid = num;
			}
			else {
				return true;   //�ҵ�����mid����true
			}
		}
		return false;
	}
};

//ִ����ʱ:456 ms, ������ C++ �ύ�л�����5.18%���û�
//�ڴ����� :9.2 MB, ������ C++ �ύ�л�����5.34%���û�
class Solution {
public:
	//˼·3:��̬�滮O(N^2)/O(N)
	//״̬��dp[i],��¼0~i-1�ȵ�ǰԪ��С�ĸ���,��ʼ��Ϊ0
	//base sample dp[0] = 0
	//ת��������j��if(nums[j] < nums[i]) dp[i] = max(dp[i] + 1, dp[i])
	bool increasingTriplet(vector<int>& nums) {
		int len = nums.size();
		vector<int> dp(len, 0);
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[j] < nums[i]) {
					dp[i] = max(dp[j] + 1, dp[i]);
				}
				if (dp[i] >= 2) return true;
			}
		}
		return false;
	}
};

class Solution {
public:
	//˼·4:ǰ�����O(N)/O(N)
	//����forwards[i]��¼��[0,i]����СԪ��(��̬�滮)
	//����backwwards[i]��¼��[i,len-1]�����Ԫ��
	//����nums[i]���ҵ�forwards[i] < nums[i] < backwards[i]Ԫ��


	//���ɣ�(forwards[j] < nums[j] && nums[j] < backwards[j])����ͬ��(forwards[j] < nums[j] < backwards[j])
	bool increasingTriplet(vector<int>& nums) {
		int len = nums.size();
		if (len < 3) return false;
		vector<int> forwards(len);
		vector<int> backwards(len);
		forwards[0] = nums[0];
		backwards[len - 1] = nums[len - 1];
		for (int i = 1; i < len; i++) {
			forwards[i] = min(nums[i], forwards[i - 1]);
		}
		for (int j = len - 2; j >= 0; j--) {
			backwards[j] = max(nums[j], backwards[j + 1]);
			if (forwards[j] < nums[j] && nums[j] < backwards[j]) return true;
		}
		return false;
	}
};