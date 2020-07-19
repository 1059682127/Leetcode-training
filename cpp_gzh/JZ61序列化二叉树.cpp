
/*
题目描述
请实现两个函数，分别用来序列化和反序列化二叉树

二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。

二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。

例如，我们可以把一个只有根节点为1的二叉树序列化为"1,"，然后通过自己的函数来解析回这个二叉树
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
	//使用先序遍历
	//遇到NULL，添加#，遇到别的，添加val!
	int index = 0;
	string s;
	char* Serialize(TreeNode *root) {
		s = "";
		help(root);
		return (char*)s.data();  //string转char*
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
		//计算当前数
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