
/*
��Ŀ����
��ʵ�������������ֱ��������л��ͷ����л�������

�����������л���ָ����һ�ö���������ĳ�ֱ�����ʽ�Ľ����ĳ�ָ�ʽ����Ϊ�ַ������Ӷ�ʹ���ڴ��н��������Ķ��������Գ־ñ��档���л����Ի����������򡢺��򡢲���Ķ�����������ʽ�������޸ģ����л��Ľ����һ���ַ��������л�ʱͨ�� ĳ�ַ��ű�ʾ�սڵ㣨#������ �� ��ʾһ�����ֵ�Ľ�����value!����

�������ķ����л���ָ������ĳ�ֱ���˳��õ������л��ַ������str���ع���������

���磬���ǿ��԰�һ��ֻ�и��ڵ�Ϊ1�Ķ��������л�Ϊ"1,"��Ȼ��ͨ���Լ��ĺ��������������������
*/


/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/

class Solution {
public:
	//ʹ���������
	//����NULL�����#��������ģ����val!
	int index = 0;
	string s;
	char* Serialize(TreeNode *root) {
		s = "";
		help(root);
		return (char*)s.data();  //stringתchar*
	}
	void help(TreeNode *root) {
		if (root == NULL) {
			s += "#!";
			return;
		}
		s += to_string(root->val);
		s += '!';
		help(root->left);
		help(root->right);
	}
	TreeNode* Deserialize(char *str) {
		return help2(str, strlen(str));
	}
	TreeNode* help2(char *str, int len) {
		if (index >= len) return NULL;
		if (str[index] == '!') {
			++index;
			if (index >= len) return NULL;
		}
		if (str[index] == '#') {
			++index;
			return NULL;
		}
		//���㵱ǰ��
		int num = 0;
		while (str[index] >= '0' && str[index] <= '9') {
			num = num * 10 + str[index++] - '0';
		}
		TreeNode* cur = new TreeNode(num);
		cur->left = help2(str, len);
		cur->right = help2(str, len);
		return cur;
	}
};