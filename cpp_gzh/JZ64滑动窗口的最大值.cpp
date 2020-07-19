/*
滑动窗口的最大值
题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/

class Solution {
public:
	//单调队列，双端队列，队首保持最大元素
	vector<int> maxInWindows(const vector<int>& num, int size)
	{
		int len = num.size();
		if (len == 0 || size < 1 || size > len) return {};
		vector<int> res;
		deque<int> windows; //存放Index
		//初始化windows
		for (int i = 0; i < min(size, len); ++i) {
			//比当前值小的都舍弃掉
			while (!windows.empty() && num[windows.back()] <= num[i]) windows.pop_back();
			windows.push_back(i);
		}
		res.push_back(num[windows.front()]);
		for (int i = size; i < len; ++i) {
			//判断队首元素是否在滑窗范围内，不在则弹出
			if (!windows.empty() && windows.front() < i - size + 1) windows.pop_front();
			while (!windows.empty() && num[windows.back()] <= num[i]) windows.pop_back();
			windows.push_back(i);
			res.push_back(num[windows.front()]);
		}
		return res;
	}
};