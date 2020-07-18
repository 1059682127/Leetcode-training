//lt150

/*
逆波兰表达式求值

根据逆波兰表示法，求表达式的值。
有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
说明：
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
示例 1：
输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9
示例 2：
输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6
示例 3：
输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
解释:
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

思路：辅助栈，遇到操作数，直接入栈；遇到运算符，弹出两个操作数计算，计算结果再弹入；
*/


class Solution {
public:
	//思路：辅助栈，遇到操作数，直接入栈；遇到运算符，弹出两个操作数计算，计算结果再弹入；
	//结果：返回栈顶元素

	//Trick1:输入是string，需要转为int

	//知识点：
	//1、switch之后括号内的表达式只能是整数（byte，short，char和int）或字符型表达式，不能是长整型或其它任何类型；
	//2、if语句有大括号的时候，大括号里面所有的 都归if管。没有大括号时，只有下面一句归if管!!!
	//3、string转Int，用stringstream
	int evalRPN(vector<string>& tokens) {
		//建栈
		stack<int> data;
		for (auto token : tokens) {
			//如果是运算符，弹出，运算后将结果弹入
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
				//    data.push(stringToInt(token));//如果都没有匹配上，就执行这里的代码
				data.push(str2num(token));
			}
		}
		return data.top();
	}
	//string转Int方法一：
	int stringToInt(string s) {
		int num = 0;
		bool sign = true; //'正'
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
	//string转Int方法二：
	int str2num(string s) {
		int num;
		stringstream ss;
		//string转stringstream对象
		ss << s;
		//stringstream对象转Int
		ss >> num;
		return num;
	}
};