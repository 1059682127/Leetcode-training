/*
�������ڵ����ֵ
��Ŀ����
����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ�����磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ����ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}�� �������{2,3,4,2,6,2,5,1}�Ļ�������������6���� {[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}�� {2,3,4,[2,6,2],5,1}�� {2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��
*/

class Solution {
public:
	//�������У�˫�˶��У����ױ������Ԫ��
	vector<int> maxInWindows(const vector<int>& num, int size)
	{
		int len = num.size();
		if (len == 0 || size < 1 || size > len) return {};
		vector<int> res;
		deque<int> windows; //���Index
		//��ʼ��windows
		for (int i = 0; i < min(size, len); ++i) {
			//�ȵ�ǰֵС�Ķ�������
			while (!windows.empty() && num[windows.back()] <= num[i]) windows.pop_back();
			windows.push_back(i);
		}
		res.push_back(num[windows.front()]);
		for (int i = size; i < len; ++i) {
			//�ж϶���Ԫ���Ƿ��ڻ�����Χ�ڣ������򵯳�
			if (!windows.empty() && windows.front() < i - size + 1) windows.pop_front();
			while (!windows.empty() && num[windows.back()] <= num[i]) windows.pop_back();
			windows.push_back(i);
			res.push_back(num[windows.front()]);
		}
		return res;
	}
};