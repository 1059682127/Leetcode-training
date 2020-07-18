//lt150

/*
�沨�����ʽ��ֵ

�����沨����ʾ��������ʽ��ֵ��
��Ч����������� +, -, *, / ��ÿ��������������������Ҳ��������һ���沨�����ʽ��
˵����
��������ֻ�����������֡�
�����沨�����ʽ������Ч�ġ����仰˵�����ʽ�ܻ�ó���Ч��ֵ�Ҳ����ڳ���Ϊ 0 �������
ʾ�� 1��
����: ["2", "1", "+", "3", "*"]
���: 9
����: ((2 + 1) * 3) = 9
ʾ�� 2��
����: ["4", "13", "5", "/", "+"]
���: 6
����: (4 + (13 / 5)) = 6
ʾ�� 3��
����: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
���: 22
����:
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

˼·������ջ��������������ֱ����ջ������������������������������㣬�������ٵ��룻
*/


class Solution {
public:
	//˼·������ջ��������������ֱ����ջ������������������������������㣬�������ٵ��룻
	//���������ջ��Ԫ��

	//Trick1:������string����ҪתΪint

	//֪ʶ�㣺
	//1��switch֮�������ڵı��ʽֻ����������byte��short��char��int�����ַ��ͱ��ʽ�������ǳ����ͻ������κ����ͣ�
	//2��if����д����ŵ�ʱ�򣬴������������е� ����if�ܡ�û�д�����ʱ��ֻ������һ���if��!!!
	//3��stringתInt����stringstream
	int evalRPN(vector<string>& tokens) {
		//��ջ
		stack<int> data;
		for (auto token : tokens) {
			//����������������������󽫽������
			if (token == "+") {
				int right = data.top();
				data.pop();
				int left = data.top();
				data.pop();
				data.push(left + right);
			}
			else if (token == "-") {
				int right = data.top();
				data.pop();
				int left = data.top();
				data.pop();
				data.push(left - right);
			}
			else if (token == "*") {
				int right = data.top();
				data.pop();
				int left = data.top();
				data.pop();
				data.push(left * right);
			}
			else if (token == "/") {
				int right = data.top();
				data.pop();
				int left = data.top();
				data.pop();
				data.push(left / right);
			}
			else {
				//    data.push(stringToInt(token));//�����û��ƥ���ϣ���ִ������Ĵ���
				data.push(str2num(token));
			}
		}
		return data.top();
	}
	//stringתInt����һ��
	int stringToInt(string s) {
		int num = 0;
		bool sign = true; //'��'
		if (s[0] == '-') sign = false; //'-'
		if (sign) {
			for (auto c : s) {
				num = num * 10 + (c - '0');
			}
			return num;
		}
		else {
			for (int i = 1; i < s.size(); i++) {
				num = num * 10 + (s[i] - '0');
			}
			return -num;
		}
	}
	//stringתInt��������
	int str2num(string s) {
		int num;
		stringstream ss;
		//stringתstringstream����
		ss << s;
		//stringstream����תInt
		ss >> num;
		return num;
	}
};