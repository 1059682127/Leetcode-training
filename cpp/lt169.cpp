//lt169

/*
��Ŀ������
����һ����СΪ n �����飬�ҵ����еĶ���Ԫ�ء�����Ԫ����ָ�������г��ִ������� ? n/2 ? ��Ԫ�ء�
����Լ��������Ƿǿյģ����Ҹ������������Ǵ��ڶ���Ԫ�ء�
ʾ�� 1:
����: [3,2,3]
���: 3
ʾ�� 2:
����: [2,2,1,1,1,2,2]
���: 2

˼·��
1������nums,ʹ��hash_table,��¼��ͬԪ�س��ֵĴ���������value>? n/2 ?��key, O(N)/O(N)
2��sortһ�㣬ȡ�м�Ԫ�أ�O(nlog2n)/O(1)

�ٷ���
1��������ⷨ��������һ���±꣬�������ֵ�Ƿ�Ϊ����
2�����Σ����϶��ֻ����ٽ����Ե��������ϻ�ϣ�0(nlogn)/O(logn)
3��Boyer-Moore ͶƱ�㷨��ά��һ��������������Ϊ1��������Ϊ-1��
ѡ��һ����ѡ���������������Ϊ0���Ͱ�ǰ����ʵ���������ȥ����ͬ�������ͷ�����������ȥ������ķ���������
����һ����׺����������Ǵ��� 0 �ģ���ʱ�����׺�������������������������


֪ʶ�㣺
1������ȡ��, �����Ϊ ceil������ѧ���� ??  ��������ֹ���������£���ʾ������ȡ��, �����Ϊ floor������ѧ���� ?? ��������ֹ���������ϣ���ʾ��
2��unordered_map��map����������Ҫ���ǵײ�ṹ��ͬ��ʹ�ó������ݣ�
�����Ҫ�õ�һ���������У�ʹ�ú����ϵ�еĹ���ʽ����map�������Ҫ���ߵĲ�ѯЧ�ʣ�ʹ���Թ�ϣ��Ϊ�ײ�Ĺ���ʽ����unordered_map
3�����β�ÿ�����ֶν���һ������ɨ���ʱ�临�Ӷ�Ϊ0(nlogn)��
4�����ڵݹ�����ƽ��ģ����ԴӸ���ÿ��Ҷ�ӽڵ�ĳ��ȶ��� O(lgn)�����ڵݹ�����������ȵģ��ռ临�Ӷȵ������һ��·����Ҳ���� O(lgn)

*/

class Solution {
public:
	//sort��ȡ�м�Ԫ��
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];  //������������������±�Ϊ? n/2 ?����ע�����±꣬���ǵ�? n/2 ?��
	}

	//��ϣ��ͳ�ƴ�������ȡ��������len_half��
	int majorityElement(vector<int>& nums) {
		int len = nums.size();
		int len_half = len / 2;
		int cur;
		map<int, int>a;
		for (int i = 0; i < len; i++) {
			cur = nums[i];
			a[cur]++;
			if (a[cur] > len_half) {
				return cur;
			}
		}
		return -1;
	}
};


//����
class Solution {
public:
	//���÷��ε�˼��
	int majorityElement(vector<int>& nums) {
		return majorityElemence(nums, 0, nums.size() - 1);
	}
	int majorityElemence(vector<int>& nums, int lower, int upper) {
		//����ǵ������򷵻�
		if (lower == upper) {
			return nums[lower];
		}
		//������������������
		int mid = (upper - lower) / 2 + lower;
		int left = majorityElemence(nums, lower, mid);
		int right = majorityElemence(nums, mid + 1, upper);
		//�������������ͬ
		if (left == right) {
			return left;
		}
		//�����������ͬ���������������������Ӧ������
		int leftNum = countNum(nums, lower, mid, left);
		int rightNum = countNum(nums, mid + 1, upper, right);
		return leftNum > rightNum ? left : right;
	}
	int countNum(vector<int>& nums, int lower, int upper, int Number) {
		int Num = 0;
		for (int i = lower; i <= upper; i++) {
			if (nums[i] == Number) Num++;
		}
		return Num;
	}
};

class Solution {
public:
	//����ͶƱ�㷨
	int majorityElement(vector<int>& nums) {
		int candidate;
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (count == 0) {   //���Ϊ0������ǰ�����
				count = 0;     //���ü������ͺ�ѡ����
				candidate = nums[i];
			}
			count += (nums[i] == candidate ? 1 : -1);  //���¼�������ֵ

		}
		return candidate;
	}

};