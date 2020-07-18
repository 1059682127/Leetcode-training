//lt128
/*
128. ���������

����һ��δ������������飬�ҳ���������еĳ��ȡ�

Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(n)��

ʾ��:

����: [100, 4, 200, 1, 3, 2]
���: 4
����: ����������� [1, 2, 3, 4]�����ĳ���Ϊ 4��

//˼·1����������ö�ٷ���
//˼·2������+����
//˼·3����ϣ������Կռ�Ĺ���
//˼·4����̬�滮
//˼·5��DFS

*/

class Solution {
public:
	//˼·1����������ö�ٷ���
	//���п����� nums ���������һ�����ֿ�ʼ�����ǿ���ö��ÿ��������Ϊ���еĵ�һ�����֣��������еĿ����ԡ�
	//�� nums �����е�ÿһ�����֣���Ϊ���е�һ������(��1)��ö�ٺ�������֣�2��3��4����ֱ����������ԭ������û���ֹ���5����������󳤶�Ϊ4��
	//O(N^3)/O(1):����ѭ�������������õ�һ�����֣�ö�ٺ���������ж��Ƿ���ԭ�����г���

	//˼·3����ϣ������Կռ�Ĺ���
	//���˼·1���������Ż���
	//1���ù�ϣ��洢nums�����е�Ԫ�أ�����ʵ��O(1)ʱ�����
	//2��ֻ��num[i] - 1���ڹ�ϣ���У�num[i]����Ϊ���е�һ�����ֽ���ö�٣������Ԫ�ؿ϶������ڱ��Ԫ��num[i] - 1��ͷ��������
	//ʱ��:O(N)��������Ƕ�ף�����ֻ��num[i] - 1���ڹ�ϣ���У��Ž���ö��
	//�ռ�:O(N)��ϣ����������Կռ�

	int longestConsecutive(vector<int>& nums) {
		//˼·3����ϣ������Կռ�Ĺ���
		//unordered_setʱ����룬����ʱ��ΪO(1)
		int len = nums.size();
		int maxL = 0;
		if (len <= 1) return len;
		unordered_set<int> s(nums.begin(), nums.end());
		for (auto num : s) {   //���ܴ�����
			if (!s.count(num - 1)) {
				//��numΪ���п�ͷ
				int size = 1;
				while (s.count(++num)) {
					++size;
				}
				if (size > maxL) maxL = size;
			}
		}
		return maxL;
	}
};

class Solution {
public:
	//˼·2������+����
	//�����������Ȼ���ͷ��������¼��ǰ���������ȣ�����������жϣ���Ƚ��Ƿ�Ϊ��ǰ������������Ұѵ�ǰ��������0
	//�����������������е���������������ǰ����������<maxL, ����ӣ����>maxL,��clear����ӣ�==maxL,����Ӹ����
	//0(nlog)/O(1):����ʱ��0(nlog)+����ʱ��O(n)
	//Trick1:(�ظ�������)�����ǰ���ֺ�ǰһ��������ȣ���ô���ǵ�ǰ�����мȲ�������Ҳ�����жϣ�����ֻ��Ҫ����������һ�����֡�
	int longestConsecutive(vector<int>& nums) {
		//˼·2������+����
		int len = nums.size();
		if (len <= 1) return len;
		sort(nums.begin(), nums.end());
		int maxL = 0;
		int size = 1;
		for (int i = 0; i < len - 1; ++i) {
			if (nums[i] + 1 == nums[i + 1]) {
				++size;
				continue;
			}
			if (nums[i] == nums[i + 1]) continue;
			else {
				//��ĩβ��
				if (size > maxL) maxL = size;
				size = 1;
			}
		}
		if (size > maxL) maxL = size;
		return maxL;
	}
};


class Solution {
public:

	//˼·4����̬�滮
	//�����Ͼ��ǰ����������н��кϲ���˼·���ǿ��������Ƚ����С���⣬Ȼ���������ô�����
	//��һ�� HashMap ���洢�Ե�ǰ key Ϊ�߽���������еĳ��ȣ�����֪123��56���У��洢(1,3),(3,3),(5,2)(6,3)
	//�����һ����Ԫ��4��������ڹ�ϣ���У�����������Ԫ��2,3(��2����������У���3��ͷ�������)��������г���Ϊ2+1+3 = 6�����±߽���������г���(2,6),(6,6);��������Ԫ�ز��ڹ�ϣ���У������������ 0
	//Trick1:����ǰ���ַŵ� map �У���ֹ�ظ��������֣�value ��������һ��ֵ

	int longestConsecutive(vector<int>& nums) {
		//˼·4����̬�滮
		//unordered_setʱ����룬����ʱ��ΪO(1)
		int len = nums.size();
		int maxL = 0;
		if (len <= 1) return len;
		unordered_map<int, int> hash_table;
		for (auto num : nums) {
			if (!hash_table.count(num)) {
				int left = (hash_table.count(num - 1)) ? hash_table[num - 1] : 0;
				int right = (hash_table.count(num + 1)) ? hash_table[num + 1] : 0;
				int size = left + 1 + right;
				//ע����µ��Ⱥ�˳��
				hash_table[num] = -1;  //���м䣬�϶�������ģ������ٷ�����
				hash_table[num + right] = size;
				hash_table[num - left] = size;

				if (size > maxL) maxL = size;
			}
		}
		return maxL;

	}
};

class Solution {
public:
	//˼·5��DFS
	//����������ͼ�����·��������������·����������maxL��

	//��ʵ���������ڶ������е����·����
	//����ĳ������·������ = ��·������ + 1 + ��·������
	//��ĳ���㿪ʼ���·�����ȣ����������㣩:�ݹ�ֱ�����ҷ�֧������(�����������������ȣ��Ե����ϵݹ�)

	//Trick1:���ù������ִӼ������Ƴ�����Ϊ�����Ĺ�ϵ��һ�����ֲ���������������У����Ƚϵ�ǰ���ǲ��Ǳȵ�ǰ���Ҫ����������¡����DFSֱ������Ϊ�ա�
	//Trick2:��unoredered_set�洢���֣��ȿ���ȥ�أ��ֿ��Գ���ʱ�����
	int maxL;
	int longestConsecutive(vector<int>& nums) {
		int len = nums.size();
		maxL = 0;
		if (len <= 1) return len;
		unordered_set<int> s(nums.begin(), nums.end());
		//���ж��DFS��ֱ��ͼ�������
		while (!s.empty()) {
			//ȡ��һ��Ԫ����ΪDFS���
			int start = *s.begin();
			DFS(start, s);
		}
		return maxL;

	}
	//����ĳ������·������ = ��·������ + 1 + ��·������
	//��ĳ���㿪ʼ���·�����ȣ����������㣩:�ݹ�ֱ�����ҷ�֧������(�����������������ȣ��Ե����ϵݹ�)
	int DFS(int start, unordered_set<int>& s) {
		if (!s.count(start)) return 0;
		s.erase(start);
		int left = DFS(start - 1, s);
		int right = DFS(start + 1, s);
		//�������·����
		int size = left + right + 1;
		maxL = size > maxL ? size : maxL;
		return max(left, right) + 1;

	}
};