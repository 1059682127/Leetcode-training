//lt350

/*
��������Ľ��� II

�����������飬��дһ���������������ǵĽ�����
ʾ�� 1:
����: nums1 = [1,2,2,1], nums2 = [2,2]
���: [2,2]
ʾ�� 2:
����: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
���: [4,9]
˵����
��������ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������г��ֵĴ���һ�¡�
���ǿ��Բ�������������˳��
����:
��������������Ѿ��ź����أ��㽫����Ż�����㷨��
��� nums1 �Ĵ�С�� nums2 С�ܶ࣬���ַ������ţ�
��� nums2 ��Ԫ�ش洢�ڴ����ϣ������ڴ������޵ģ������㲻��һ�μ������е�Ԫ�ص��ڴ��У������ô�죿

//˼·1��˫��ϣ��O(N+M)/O(min(N,M))
//����1�������������nums1�ϣ����ÿ�������Ŀռ�
//����2��ѡ��϶̵��Ӵ���ʼ��¼��ϣ�����Խ�ʡ��ϣ��Ŀռ�


�Ľ�˼·2������ϣ��O(M+N)/O(MIN(M,N))
//���� HashMap ��¼һ�������еĴ��ڵ����ֺͶ�Ӧ���ֵĴ�����Ȼ�����Ǳ����ڶ������飬��������� HashMap ���Ƿ���ڣ�
��������Ҽ���Ϊ�����򽫸�������ӵ��𰸲����� HashMap �еļ�����

˼·3��sort+˫ָ��O(NlogN + MlogM)/O(1)
*/


class Solution {
public:
	//˼·��˫��ϣ��
	//����1�������������nums1�ϣ����ÿ�������Ŀռ�
	//����2��ѡ��϶̵��Ӵ���ʼ��¼��ϣ�����Խ�ʡ��ϣ��Ŀռ�
	//֪ʶ�㣺map����
	//ȷ��Ԫ���Ƿ���ڣ�map.count(key)
	//����Ԫ�أ�map[key]/map<int, int>::iterator->first,����map[1]
	//map���ں�������Զ��������
	//����vector�±�Ϊ0��k�ķ�Χ��return vector(nums1.begin(), nums1.begin() + k);
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		map<int, int> a;
		int len1 = nums1.size();
		int len2 = nums2.size();
		//��ϣ��a��¼nums1���ַ���������
		for (int i = 0; i < len1; i++) {
			a[nums1[i]]++;
		}
		//������һ����ϣ��b�����nums2���ַ���nums1�г��֣�-1
		map<int, int> b(a.begin(), a.end());
		for (int i = 0; i < len2; i++) {
			if (b.count(nums2[i])) b[nums2[i]]--;
		}
		//ͳ��������ϣ��֮��Ĳ�࣬��Ϊ����
		int k = 0;//��¼��������
		int size1, size2;
		for (auto it = a.begin(); it != a.end(); it++) {
			size1 = it->second;
			size2 = b[it->first];
			if (size1 > size2) {
				int diff = (size2 >= 0) ? size1 - size2 : size1;
				for (int j = 0; j < diff; j++) {
					nums1[k] = it->first;   //�����������nums1�ϣ����ÿ�������Ŀռ�
					k++;
				}
			}
		}
		return vector(nums1.begin(), nums1.begin() + k);
	}
};

class Solution {
public:
	//˼·2������ϣ������ HashMap ��¼һ�������еĴ��ڵ����ֺͶ�Ӧ���ֵĴ�����Ȼ�����Ǳ����ڶ������飬��������� HashMap ���Ƿ���ڣ�
	//��������Ҽ���Ϊ�����򽫸�������ӵ��𰸲����� HashMap �еļ�������
	//ѡ�񳤶Ƚ϶̵Ľ�����ϣ��
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size(), len2 = nums2.size();
		if (len1 > len2) return intersect(nums2, nums1);  //��������
		map<int, int>a;
		//��ϣ��a��¼nums1���ַ���������
		for (int i = 0; i < len1; i++) {
			a[nums1[i]]++;
		}
		int k = 0; //��¼��������
		for (int i = 0; i < len2; i++) {
			//����ڹ�ϣ���д����Ҽ���Ϊ��
			if (a.count(nums2[i]) && a[nums2[i]]-- > 0) {
				nums1[k++] = nums2[i];
			}
		}
		return vector(nums1.begin(), nums1.begin() + k);
	}
};