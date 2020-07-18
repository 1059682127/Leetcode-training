///lt28

/*
28. ʵ�� strStr()

ʵ�� strStr() ������
����һ�� haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻�  -1��
ʾ�� 1:
����: haystack = "hello", needle = "ll"
���: 2
ʾ�� 2:
����: haystack = "aaaaa", needle = "bba"
���: -1

//˼·1����������O(M-N+1)*N
*/

class Solution {
public:
	//˼·1������
	int strStr(string haystack, string needle) {
		int len1 = haystack.size();
		int len2 = needle.size();
		if (len1 < len2) return -1;
		if (len1 == 0 || len2 == 0) return 0;
		bool match;
		for (int i = 0; i + len2 - 1 < len1; ++i) {
			match = true;
			for (int j = 0; j < len2; ++j) {
				if (haystack[i + j] != needle[j]) {
					match = false;
					break;
				}

			}
			if (match) return i;
		}
		return -1;
	}
};