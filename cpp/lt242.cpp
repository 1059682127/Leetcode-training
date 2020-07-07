//lt242

/*
��Ч����ĸ��λ��

���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�
ʾ�� 1:
����: s = "anagram", t = "nagaram"
���: true
ʾ�� 2:
����: s = "rat", t = "car"
���: false
˵��:
����Լ����ַ���ֻ����Сд��ĸ��
����:
��������ַ������� unicode �ַ���ô�죿���ܷ������Ľⷨ��Ӧ�����������

˼·��
1��sort��Ȼ���ж��Ƿ����O(nlogn)/O(1)
2����ϣ��,�ù�ϣ���¼s����ĸ���ֵĴ�������t���ٹ�ϣ������ĸ�Ĵ������������Ϊ0����Ϊtrue;O(n)/O(1)
*/



//˼·1��sort+�ж�
class Solution {
public:
	//˼·��
	//1����������Ӵ���ͬ��true���������sort,�ж��Ƿ���ͬO(nlogn)/O(n)
	//֪ʶ�㣺ĸ��λ����ָ����ͬ����ĸ���ղ�ͬ��˳����ɵĵ���
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		vector<char> sTemp(s.begin(), s.end());
		vector<char> tTemp(t.begin(), t.end());
		sort(sTemp.begin(), sTemp.end());
		sort(tTemp.begin(), tTemp.end());
		return sTemp == tTemp;
	}
};

//�Լ�д�Ŀ���
class Solution {
public:
	//˼·2������
	//1��������s����������������������ͬ��������ĸ��λ��
	//2���߽�������������߳��Ȳ��ȣ�������ǰ����
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		quickSort(s, 0, s.size() - 1);
		quickSort(t, 0, t.size() - 1);
		return s == t;
	}
	void quickSort(string& s, int low, int high) {
		if (low < high) {
			//����
			int mid = partition(s, low, high);
			quickSort(s, low, mid - 1);
			quickSort(s, mid + 1, high);
		}
	}
	int partition(string& s, int low, int high) {
		int p = s[low];
		int m = low;
		for (int k = low + 1; k <= high; ++k) {
			if (s[k] < p) {
				++m;
				swap(s, m, k);
			}
		}
		swap(s, low, m);
		return m;
	}
	void swap(string& s, int i, int j) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
};

class Solution {
public:
	//˼·����ϣ��
	//1���ù�ϣ���¼s����ĸ���ֵĴ�������t���ٹ�ϣ������ĸ�Ĵ������������Ϊ0����Ϊtrue
	//֪ʶ�㣺ĸ��λ����ָ����ͬ����ĸ���ղ�ͬ��˳����ɵĵ���
	//��ʼ����СΪ26��vector  vector<int> a(26);
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		vector<int> a(26);
		for (int i = 0; i < s.size(); i++) {
			a[s[i] - 'a']++;
			a[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (a[i] != 0) return false;
		}
		return true;
	}
};