//lt239

/*
�����������ֵ

����һ������ nums����һ����СΪ k �Ļ������ڴ������������ƶ�����������Ҳࡣ��ֻ���Կ����ڻ��������ڵ� k �����֡���������ÿ��ֻ�����ƶ�һλ��
���ػ��������е����ֵ��

ʾ��:
����: nums = [1,3,-1,-3,5,3,6,7], �� k = 3
���: [3,3,5,5,6,7]
����:

  �������ڵ�λ��                ���ֵ
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


 //˼·1:������������0~i-k 0(nk)/O(n - k + 1)
 //˼·2:˫�˶���/��������


*/

//ִ����ʱ:156 ms, ������ C++ �ύ�л�����10.58%���û�
//�ڴ����� :14 MB, ������ C++ �ύ�л�����15.61%���û�
class Solution {
public:
	//˼·1:������������0~i-k 0(nk)/O(n - k + 1)
	//˼·2��
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int len = nums.size();
		if (len == 0) return nums;
		vector<int> res;
		for (int i = 0; i <= len - k; i++) {
			int Max = nums[i];
			for (int j = 1; j < k; j++) {
				Max = (nums[i + j] > Max) ? nums[i + j] : Max;
			}
			res.push_back(Max);
		}
		return res;
	}
};

//ִ����ʱ:28 ms, ������ C++ �ύ�л�����79.28%���û�
//�ڴ����� :14.1 MB, ������ C++ �ύ�л�����14.97%���û�
class Solution {
public:
	//˼·2:˫�˶���/��������
	//����ʹ�öѱ������ֵ��������ôȥ�����ڻ������ڷ�Χ�ڵ�Ԫ�أ�����ʹ��˫�˶���
	//https://leetcode-cn.com/problems/sliding-window-maximum/solution/shuang-xiang-dui-lie-jie-jue-hua-dong-chuang-kou-z/
	//��˫�˶��п�������ʵ�ֶ���Ԫ�ص�O(1)���ʣ�����Ԫ�ر��洰�����Ԫ�ص��±꣬���б��ֵ����ݼ�
	//����Ԫ�أ�ÿ�������Ԫ��ʱ��ȥ����β��nums[i]С�ģ�ֱ����β��nums[i],�����num[i]
	//���Ԫ�أ�ÿ�δ����ƶ�,�ȼ�����Ԫ���Ƿ��ڴ��ڷ�Χ�ڣ�������window.pop_front();����������������ֵ��window.front()
	//O(N)/O(N)ÿ��Ԫ�ر��������Σ������ɾ�������������ʹ��O(N - K + 1),˫�����ʹ��O(K)

	//֪ʶ�㣺
	//���룺window.push_back()
	//������Ԫ�أ�window.pop_front();
	//����βԪ�أ�window.pop_back()
	//ȡ����Ԫ�ص�ֵ��window.front();
	//ȡ��βԪ�ص�ֵ��window.back()
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int len = nums.size();
		if (len == 0) return nums;
		vector<int> res;
		deque<int> window;
		//��ʼ��deque
		for (int i = 0; i < k; i++) {
			while (!window.empty() && nums[window.back()] <= nums[i]) window.pop_back();
			window.push_back(i);
		}
		res.push_back(nums[window.front()]);
		//���л�������(iΪ��ǰԪ��)
		for (int i = k; i < len; i++) {
			if (!window.empty() && window.front() < i - k + 1) window.pop_front();
			while (!window.empty() && nums[window.back()] <= nums[i]) window.pop_back();

			window.push_back(i);
			res.push_back(nums[window.front()]);
		}
		return res;
	}
};