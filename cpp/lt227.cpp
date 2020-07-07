//lt227

/*
基本计算器 II

实现一个基本的计算器来计算一个简单的字符串表达式的值。
字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。
示例 1:
输入: "3+2*2"
输出: 7
示例 2:
输入: " 3/2 "
输出: 1
示例 3:
输入: " 3+5 / 2 "
输出: 5
说明：
你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。

思路：栈
*/

class Solution {
public:
	//思路1：栈
	//参考：https://leetcode-cn.com/problems/basic-calculator-ii/solution/chai-jie-fu-za-wen-ti-shi-xian-yi-ge-wan-zheng-ji-/
	//要求：
	//1、乘法加法优先律 2、括号优先
	//问题分解：
	//1、字符串转整数 n = 10 * n + (s[i] - '0')
	//2、处理加减法  eg:1-12+3 用栈，依次保存+1, -12, +3, 将栈中元素求和
	//3、处理乘除法  eg:2-3*4+5 乘除法优先于加减法体现在，乘除法可以和栈顶的数(弹出)结合，而加减法只能把自己放入栈。
	//4、处理括号    eg:3*(4-5/2)-6 括号具有递归性质,遇到(递归开始，遇到)递归结束,换句话说，括号包含的算式，我们直接视为一个数字就行了。

	//知识点：
	//1、是否是数字：bool isdigit(char);
	//2、stack操作
	//empty() 堆栈为空则返回真
	//pop() 移除栈顶元素
	//push() 在栈顶增加元素
	//size() 返回栈中元素数目
	//top() 返回栈顶元素
	//3、switch(sign){case(condition): expr; break;}

	//执行用时 :12 ms, 在所有 C++ 提交中击败了89.25%的用户
	//内存消耗 :11.3 MB, 在所有 C++ 提交中击败了36.30%的用户
	//计算器的完整版（字符处理、加减乘除、括号）
	//递归，遇到‘(’递归开始，遇到‘)’递归结束，括号当做一个数num，每一层的计算按照之前的乘除加法方法
	int calculate(string s) {
		return helper(s, 0);  //考虑括号
		//return calculate2(s);  //不考虑括号
	}

	int helper(string s, int start) {
		stack<int> data;
		int num = 0;  //保存当前数字
		char sign = '+';
		//遍历字符串
		for (int i = start; i < s.size(); i++) {
			char c = s[i];

			if (isdigit(c)) {
				num = 10 * num + (c - '0');
			}
			//判断是否遇到括号
			if (c == '(') num = helper(s, i + 1);
			//非数字或者遇到空白符，去掉空格的情况
			if (!isdigit(c) && c != ' ' || i == s.size() - 1) {
				//判断符号，保存sign和num
				int pre;
				switch (sign) {
					case '+':
						data.push(num);
						break;
					case '-':
						data.push(-num);
						break;
						//版本二的区别
					case '*':
						//弹出栈顶元素进行结合，将结合结果弹入栈
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
				//重置sign和num
				sign = c;
				num = 0;
			}
			//遇到')'结束该次括号数值计算
			if (c == ')') break;
		}
		//输出结果
		int res = 0;
		while (!data.empty()) {
			res += data.top();
			data.pop();
		}
		return res;
	}

	//将字符转化为整数
	int stringToInt(string s) {
		int n = 0;
		for (int i = 0; i < s.size(); i++) {
			n = 10 * n + (s[i] - '0');
		}
		return n;
	}
	//处理加减法版本
	//遍历字符串，遇到非数字或者字符串结尾，将符号sign和数字num一同保存到栈data中
	int calculate1(string s) {
		stack<int> data;
		int num = 0;  //保存当前数字
		char sign = '+';
		//遍历字符串
		for (int i = 0; i < s.size(); ++i) {
			char c = s[i];
			if (isdigit(c)) {
				num = 10 * num + (c - '0');
			}
			//非数字或者遇到空白符
			if (!isdigit(c) && c != ' ' || i == s.size() - 1) {
				//判断符号，保存sign和num
				switch (sign) {
				case '+':
					data.push(num);
					break;
				case '-':
					data.push(-num);
					break;
				}
				//重置sign和num
				sign = c;
				num = 0;
			}
		}
		//输出结果
		int res = 0;
		while (!data.empty()) {
			res += data.top();
			data.pop();
		}
		return res;
	}
	//处理乘除法版本
	//思路与加减法类似，加减法自己入栈，但是乘除法将栈顶元素弹出结合
	//执行用时 :20 ms, 在所有 C++ 提交中击败了45.50%的用户
	//内存消耗 :11.5 MB, 在所有 C++ 提交中击败了27.63%的用户
	int calculate2(string s) {
		stack<int> data;
		int num = 0;  //保存当前数字
		char sign = '+';

		//遍历字符串
		for (int i = 0; i < s.size(); ++i) {
			char c = s[i];
			if (isdigit(c)) {
				num = 10 * num + (c - '0');
			}
			//非数字或者遇到空白符，去掉空格的情况
			if (!isdigit(c) && c != ' ' || i == s.size() - 1) {
				//判断符号，保存sign和num
				int pre;
				switch (sign) {
				case '+':
					data.push(num);
					break;
				case '-':
					data.push(-num);
					break;
					//版本二的区别
				case '*':
					//弹出栈顶元素进行结合，将结合结果弹入栈
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
				//重置sign和num
				sign = c;
				num = 0;
			}
		}
		//输出结果
		int res = 0;
		while (!data.empty()) {
			res += data.top();
			data.pop();
		}
		return res;
	}

};