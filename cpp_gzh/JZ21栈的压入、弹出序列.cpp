/*
 �㷨֪ʶ��Ƶ����
��Ŀ����
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�
*/

class Solution {
public:
	//˼·���½�һ��ջ����A��Ԫ��������ջ����ջ��Ԫ��=B������Ԫ��ʱ����ջ��������ջ������ж�ջ�Ƿ�Ϊ��
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() == 0 || popV.size() == 0 || pushV.size() != popV.size()) return false;
		int index = 0;
		stack<int> data;
		for (int i = 0; i < pushV.size(); ++i) {
			data.push(pushV[i]);
			while (data.size() != 0 && data.top() == popV[index] && index < popV.size()) {
				data.pop();
				++index;
			}
		}
		return data.empty();
	}
};