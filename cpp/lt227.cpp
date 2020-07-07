//lt227

/*
���������� II

ʵ��һ�������ļ�����������һ���򵥵��ַ������ʽ��ֵ��
�ַ������ʽ�������Ǹ�������+�� - ��*��/ ����������Ϳո�  �� ���������������������֡�
ʾ�� 1:
����: "3+2*2"
���: 7
ʾ�� 2:
����: " 3/2 "
���: 1
ʾ�� 3:
����: " 3+5 / 2 "
���: 5
˵����
����Լ����������ı��ʽ������Ч�ġ�
�벻Ҫʹ�����õĿ⺯�� eval��

˼·��ջ
*/

class Solution {
public:
	//˼·1��ջ
	//�ο���https://leetcode-cn.com/problems/basic-calculator-ii/solution/chai-jie-fu-za-wen-ti-shi-xian-yi-ge-wan-zheng-ji-/
	//Ҫ��
	//1���˷��ӷ������� 2����������
	//����ֽ⣺
	//1���ַ���ת���� n = 10 * n + (s[i] - '0')
	//2������Ӽ���  eg:1-12+3 ��ջ�����α���+1, -12, +3, ��ջ��Ԫ�����
	//3������˳���  eg:2-3*4+5 �˳��������ڼӼ��������ڣ��˳������Ժ�ջ������(����)��ϣ����Ӽ���ֻ�ܰ��Լ�����ջ��
	//4����������    eg:3*(4-5/2)-6 ���ž��еݹ�����,����(�ݹ鿪ʼ������)�ݹ����,���仰˵�����Ű�������ʽ������ֱ����Ϊһ�����־����ˡ�

	//֪ʶ�㣺
	//1���Ƿ������֣�bool isdigit(char);
	//2��stack����
	//empty() ��ջΪ���򷵻���
	//pop() �Ƴ�ջ��Ԫ��
	//push() ��ջ������Ԫ��
	//size() ����ջ��Ԫ����Ŀ
	//top() ����ջ��Ԫ��
	//3��switch(sign){case(condition): expr; break;}

	//ִ����ʱ :12 ms, ������ C++ �ύ�л�����89.25%���û�
	//�ڴ����� :11.3 MB, ������ C++ �ύ�л�����36.30%���û�
	//�������������棨�ַ������Ӽ��˳������ţ�
	//�ݹ飬������(���ݹ鿪ʼ��������)���ݹ���������ŵ���һ����num��ÿһ��ļ��㰴��֮ǰ�ĳ˳��ӷ�����
	int calculate(string s) {
		return helper(s, 0);  //��������
		//return calculate2(s);  //����������
	}

	int helper(string s, int start) {
		stack<int> data;
		int num = 0;  //���浱ǰ����
		char sign = '+';
		//�����ַ���
		for (int i = start; i < s.size(); i++) {
			char c = s[i];

			if (isdigit(c)) {
				num = 10 * num + (c - '0');
			}
			//�ж��Ƿ���������
			if (c == '(') num = helper(s, i + 1);
			//�����ֻ��������հ׷���ȥ���ո�����
			if (!isdigit(c) && c != ' ' || i == s.size() - 1) {
				//�жϷ��ţ�����sign��num
				int pre;
				switch (sign) {
					case '+':
						data.push(num);
						break;
					case '-':
						data.push(-num);
						break;
						//�汾��������
					case '*':
						//����ջ��Ԫ�ؽ��н�ϣ�����Ͻ������ջ
						pre = data.top();
						data.pop();
						data.push(pre * num);
						break;
					case '/':
						pre = data.top();
						data.pop();
						data.push(pre / num);
						break;
				}
				//����sign��num
				sign = c;
				num = 0;
			}
			//����')'�����ô�������ֵ����
			if (c == ')') break;
		}
		//������
		int res = 0;
		while (!data.empty()) {
			res += data.top();
			data.pop();
		}
		return res;
	}

	//���ַ�ת��Ϊ����
	int stringToInt(string s) {
		int n = 0;
		for (int i = 0; i < s.size(); i++) {
			n = 10 * n + (s[i] - '0');
		}
		return n;
	}
	//����Ӽ����汾
	//�����ַ��������������ֻ����ַ�����β��������sign������numһͬ���浽ջdata��
	int calculate1(string s) {
		stack<int> data;
		int num = 0;  //���浱ǰ����
		char sign = '+';
		//�����ַ���
		for (int i = 0; i < s.size(); ++i) {
			char c = s[i];
			if (isdigit(c)) {
				num = 10 * num + (c - '0');
			}
			//�����ֻ��������հ׷�
			if (!isdigit(c) && c != ' ' || i == s.size() - 1) {
				//�жϷ��ţ�����sign��num
				switch (sign) {
				case '+':
					data.push(num);
					break;
				case '-':
					data.push(-num);
					break;
				}
				//����sign��num
				sign = c;
				num = 0;
			}
		}
		//������
		int res = 0;
		while (!data.empty()) {
			res += data.top();
			data.pop();
		}
		return res;
	}
	//����˳����汾
	//˼·��Ӽ������ƣ��Ӽ����Լ���ջ�����ǳ˳�����ջ��Ԫ�ص������
	//ִ����ʱ :20 ms, ������ C++ �ύ�л�����45.50%���û�
	//�ڴ����� :11.5 MB, ������ C++ �ύ�л�����27.63%���û�
	int calculate2(string s) {
		stack<int> data;
		int num = 0;  //���浱ǰ����
		char sign = '+';

		//�����ַ���
		for (int i = 0; i < s.size(); ++i) {
			char c = s[i];
			if (isdigit(c)) {
				num = 10 * num + (c - '0');
			}
			//�����ֻ��������հ׷���ȥ���ո�����
			if (!isdigit(c) && c != ' ' || i == s.size() - 1) {
				//�жϷ��ţ�����sign��num
				int pre;
				switch (sign) {
				case '+':
					data.push(num);
					break;
				case '-':
					data.push(-num);
					break;
					//�汾��������
				case '*':
					//����ջ��Ԫ�ؽ��н�ϣ�����Ͻ������ջ
					pre = data.top();
					data.pop();
					data.push(pre * num);
					break;
				case '/':
					pre = data.top();
					data.pop();
					data.push(pre / num);
					break;
				}
				//����sign��num
				sign = c;
				num = 0;
			}
		}
		//������
		int res = 0;
		while (!data.empty()) {
			res += data.top();
			data.pop();
		}
		return res;
	}

};