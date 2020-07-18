/*
��Ŀ����
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
��������:
����һ���ַ���,���Ȳ�����9(�������ַ��ظ�),�ַ�ֻ������Сд��ĸ��
*/

class Solution {
public:
	//��ȱ���
	set<string> res;
	vector<string> Permutation(string str) {
		for (int i = 0; i < str.size(); ++i) {
			vector<bool> isVisited(str.size(), false);
			dfs(str, i, isVisited, "");
		}
		vector<string> resV(res.begin(), res.end());
		sort(resV.begin(), resV.end());
		return resV;
	}
	void dfs(string &str, int cur, vector<bool> isVisited, string temp) {
		if (temp.size() == str.size() - 1) {
			temp.push_back(str[cur]);
			res.insert(temp);
			return;
		}
		temp.push_back(str[cur]);
		isVisited[cur] = true;
		//�����ھ�
		for (int i = 0; i < str.size(); ++i) {
			if (!isVisited[i]) {
				dfs(str, i, isVisited, temp);
			}
		}
	}
};