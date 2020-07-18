//lt131

/*
��Ŀ�������ָ���Ĵ�
����һ���ַ��� s���� s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����ǻ��Ĵ���
���� s ���п��ܵķָ����
ʾ��:
����: "aab"
���:
[
  ["aa","b"],
  ["a","a","b"]
]

*/

//���ݷ���O(N*N*N)
//�ݹ�������֧�ǽ�ȡ��ǰ׺���ڵ��ǽ�ȡ����Ӵ�
//ͨ������ǰ׺��֧�Ƿ��ǻ��ģ����м�֦
//���ݣ����Բ���ջ���ҵ�һ���֮�󣬴�ջ���������˻���һ�������
class Solution {
	//֪ʶ�㣺
	//1��string��ȡ�Ӵ���s.substr(start, len);
	//2���� string �к��п��ַ���\0����ʹ�� strlen() ��ȡ string �ĳ���ʱ�ᱻ�ضϣ�ʹ�ó�Ա���� length() �� size() ���Է��� string����ʵ���ȡ�
	//3��������ȱ������ҵ�һ���֮�󣬰�ջ�������������ԣ����˵���һ�㣬������һ��֧
public:
	//����
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> cur;
		int len = s.size();
		backtracking(s, res, cur, 0, len);
		return res;
	}
	void backtracking(string& s, vector<vector<string>>& res, vector<string>& cur, int start, int len) {
		//���˿��ַ���
		if (start == len) {
			res.push_back(cur);
			return;
		}
		//���м�֦
		for (int i = start; i < len; i++) {
			if (!isPalindrome(s, start, i)) continue;
			cur.push_back(s.substr(start, i - start + 1));  //��ȡ�Ӵ���ע���Ӵ��ĳ���
			backtracking(s, res, cur, i + 1, len);
			cur.pop_back();   //���˵���һ��
		}
	}
	bool isPalindrome(string& s, int left, int right) {
		while (left < right) {
			if (s[left] != s[right]) return false;
			left++;
			right--;
		}
		return true;
	}
};


////����+��̬�Ż�,�ÿռ任ʱ�䣬�������ݵ�ʱ�򽫻��ļ���O(N)����O(1)
class Solution {


public:
	
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> cur;
		//Ԥ������̬�滮
		int len = s.size();
		// ״̬��dp[i][j] ��ʾ s[i][j] �Ƿ��ǻ���
		// ״̬ת�Ʒ��̣��� s[i] == s[j] ��ʱ��dp[i][j] �ο� dp[i + 1][j - 1]
		vector<vector<bool>> isPalindrome(len, vector<bool>(len));
		for (int right = 0; right < len; right++) {
			for (int left = 0; left <= right; left++) {
				if (s[left] == s[right] && (right - left <= 2 || isPalindrome[left + 1][right - 1])) isPalindrome[left][right] = true;
			}
		}
		backtracking(s, res, cur, 0, len, isPalindrome);
		return res;
	}
	void backtracking(string& s, vector<vector<string>>& res, vector<string>& cur, int start, int len, vector<vector<bool>>& isPalindrome) {
		//���˿��ַ���
		if (start == len) {
			res.push_back(cur);
			return;
		}
		//���м�֦
		for (int i = start; i < len; i++) {
			if (!isPalindrome[start][i]) continue;
			cur.push_back(s.substr(start, i - start + 1));  //��ȡ�Ӵ���ע���Ӵ��ĳ���
			backtracking(s, res, cur, i + 1, len, isPalindrome);
			cur.pop_back();   //���˵���һ��
		}
	}

};