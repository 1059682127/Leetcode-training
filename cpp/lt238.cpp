//lt238

/*
��������������ĳ˻�

��������Ϊ n ���������� nums������ n > 1������������� output ������ output[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻���
ʾ��:
����: [1,2,3,4]
���: [24,12,8,6]
˵��: �벻Ҫʹ�ó��������� O(n) ʱ�临�Ӷ�����ɴ��⡣
���ף�
������ڳ����ռ临�Ӷ�����������Ŀ�𣿣� ���ڶԿռ临�Ӷȷ�����Ŀ�ģ�������鲻����Ϊ����ռ䡣��

//˼·1�������α�������һ�μ�������Ԫ�صĳ˻����ڶ��α��������ܳ˻����Ե�ǰԪ��(�������в�����0)
//Trick1:��0������0����������˼·����1����0��Ϊ����Ԫ�س˻�����0�����Ϊ0��������1������Ϊ0��

//˼·2�������ó��������ҳ˻��б�O(N)/O(N)

//˼·3�������ö���ռ䣩���ҳ˻��б�O(N)/O(1)
*/

class Solution {
public:
	//˼·1�������α�������һ�μ�������Ԫ�صĳ˻����ڶ��α��������ܳ˻����Ե�ǰԪ��(�������в�����0)
	//Trick1:��0������0����������˼·����1����0��Ϊ����Ԫ�س˻�����0�����Ϊ0��������1������Ϊ0��
	vector<int> productExceptSelf(vector<int>& nums) {
		int all = 1;
		vector<int> vZero;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) vZero.push_back(i);
			else all *= nums[i];
		}
		int zeroNum = vZero.size();
		if (zeroNum == 0) {
			for (int i = 0; i < nums.size(); i++) {
				nums[i] = all / nums[i];
			}
			return nums;
		}
		else if (zeroNum == 1) {
			for (int i = 0; i < nums.size(); i++) {
				nums[i] = (i == vZero[0]) ? all : 0;
			}
			return nums;
		}
		else {
			return vector(nums.size(), 0);
		}


	}
};


//ִ����ʱ:8 ms, ������ C++ �ύ�л�����99.45%���û�
//�ڴ����� :14.9 MB, ������ C++ �ύ�л�����5.06%���û�
class Solution {
public:
	//˼·2�������ó��������ҳ˻��б�O(N)/O(N)
	//������L[i],R[i],L[i]��¼i���Ԫ�صĳ˻���R[i]��¼i�ұ�Ԫ�صĳ˻�
	//��̬�滮��L[i] = L[i - 1]*nums[i - 1]; R[i] = R[i + 1]* nums[i + 1];base sample: L[0] = 1; R[len - 1] = 1;
	//������nums,��¼nums[i] = L[i] * R[i]
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> L(len, 1), R(len, 1);
		for (int i = 1; i < len; i++) {
			L[i] = L[i - 1] * nums[i - 1];
		}
		for (int i = len - 2; i >= 0; i--) {
			R[i] = R[i + 1] * nums[i + 1];
		}
		for (int i = 0; i < len; i++) {
			nums[i] = L[i] * R[i];
		}
		return nums;
	}
};

//ִ����ʱ:12 ms, ������ C++ �ύ�л�����94.77%���û�
//�ڴ����� :14.4 MB, ������ C++ �ύ�л�����5.06%���û�


class Solution {
public:
	//˼·3�������ö���ռ䣩���ҳ˻��б�O(N)/O(1)
	//����������鲻���ڿռ临�Ӷ��ڣ����Կ�����L[i]��������⶯̬����R[i]
	//����һ�飬��¼L[i](��answer[i]),Ȼ��������󣬼����ұ�Ԫ�صĳ˻�R������answer[i] = answer[i] * R;
	//Ȼ��R = R * nums[i]
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> L(len, 1);
		for (int i = 1; i < len; i++) {
			L[i] = L[i - 1] * nums[i - 1];
		}
		int R = 1;
		for (int i = len - 1; i >= 0; i--) {
			L[i] = L[i] * R;
			R = R * nums[i];
		}

		return L;
	}
};