/*
题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
*/

class Solution {
public:
	//滑动窗口法（左闭右开）
	//窗口扩大：++i, 窗口缩小:++j
	//初始化i = j == 1
	//当窗口内和<sum,窗口扩大；>sum,窗口缩小，==sum，保存，缩小窗口
	//终止：当i <= sum/2时
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> res;
		int l = 1, r = 1;
		int tmp = 0;
		while (l <= sum / 2) {
			if (tmp < sum) {
				tmp += r;
				++r;
			}
			else if (tmp > sum) {
				tmp -= l;
				++l;
			}
			else {
				//保存结果
				vector<int> ans;
				for (int i = l; i < r; ++i) {
					ans.push_back(i);
				}
				res.push_back(ans);
				tmp -= l;
				++l;

			}
		}
		return res;
	}
};