/*
��Ŀ����
��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
*/

class Solution {
public:
	//�õݹ�
	//f(n) = f(n - 1) + n
	//f(1) = 1
	//����A&&B,���A==0,��B����ִ��
	int Sum_Solution(int n) {
		int sum = n;
		n && (sum += Sum_Solution(n - 1));
		return sum;
	}
};