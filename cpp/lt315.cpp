//lt315

/*
�����Ҳ�С�ڵ�ǰԪ�صĸ���

����һ���������� nums����Ҫ�󷵻�һ�������� counts������ counts �и����ʣ� counts[i] ��ֵ��  nums[i] �Ҳ�С�� nums[i] ��Ԫ�ص�������
ʾ��:
����: [5,2,6,1]
���: [2,1,1,0]
����:
5 ���Ҳ��� 2 ����С��Ԫ�� (2 �� 1).
2 ���Ҳ���� 1 ����С��Ԫ�� (1).
6 ���Ҳ��� 1 ����С��Ԫ�� (1).
1 ���Ҳ��� 0 ����С��Ԫ��.

//˼·1��ѭ������0(N^2)/O(1)
//˼·2���鲢����+��������O(NlogN)/O(N)
*/




class Solution {
public:
	//˼·1��ѭ������0(N^2)/O(1)
	//˼·2���鲢����+��������
	//�ο�������ԡ�ʵ��˼·���鲢�������֮��ԭ�����������Ҳ�ͳ�����
	//ǰ�������飬���������飬��ǰ���������Ԫ�ص��ұ��ж���Ԫ�ر��Լ�С����ôӦ��ͳ�Ƹ�Ԫ�س���֮ǰ�������������Ѿ����еĸ�������Ϊ��Щ�Ѿ����е�Ԫ�ض�С�ڵ��ڵ�ǰԪ�أ�
	//��ʵ������ǹ鲢����Ĺ��̣����ǹ鲢��������ǰ����������е�ʱ��Ҫ�ۼ�����

	//�鲢������ɺ�ԭ�����λ���Ѿ������仯����ζ�λԪ���ǹؼ�������
	//Trick1:ʹ���������飬�ô����ڡ�����������й鲢��ʱ�򡱣����������ֱ�����Ԫ����ԭ����������Ƕ���
	//Trick2:ʹ���������鳤�ȵ���ʱ���飬�����������ֵ���ƹ�ȥ��˫ָ��������֮��͸��ƻ�ȥ
	//Trick3:���ηֻ��ֺͽ�����ڽ����ʱ��ǰ����������е�ʱ�����Ͽ���ͳ���ұ߱��Լ�С��Ԫ�ظ���
	//Trick4:���ǰ������������Ԫ��С���ұߵ���СԪ�أ����ù鲢

	vector<int> count;  //������
	vector<int> index;  //��������
	vector<int> helper; //��ʱ���飬���ڸ��Ʋ���
	vector<int> countSmaller(vector<int>& nums) {
		//�߽�����
		int len = nums.size();
		if (len == 0) return {};
		count.resize(len);  //������
		index.resize(len);  //��������
		helper.resize(len); //��ʱ���飬���ڸ��Ʋ���

		//���������ʼ��
		for (int i = 0; i < len; ++i) {
			index[i] = i;
			count[i] = 0;
		}

		mergeSort(nums, 0, len - 1);

		return count;
	}
	//���ֲ���
	void mergeSort(vector<int>& nums, int low, int high) {
		if (low < high) {
			int mid = (low + high) / 2;
			mergeSort(nums, low, mid);
			mergeSort(nums, mid + 1, high);
			merge(nums, low, mid, high);
		}
	}
	//�鲢����
	void merge(vector<int>& nums, int low, int mid, int high) {
		int left = low, right = mid + 1, copyIndex = low;
		while (left <= mid && right <= high) {
			//����ָ���ƶ�
			if (nums[index[left]] <= nums[index[right]]) {
				//���Ԫ�س��У�Ҫ����
				count[index[left]] += right - (mid + 1);  //��+=�ۼƼ���
				helper[copyIndex++] = index[left++];
			}
			else {
				helper[copyIndex++] = index[right++];
			}
		}
		while (left <= mid) {
			count[index[left]] += right - (mid + 1);
			helper[copyIndex++] = index[left++];
		}
		while (right <= high) helper[copyIndex++] = index[right++];

		for (int i = low; i <= high; ++i) index[i] = helper[i];
	}
};


