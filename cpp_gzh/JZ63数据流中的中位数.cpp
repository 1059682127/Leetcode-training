/*
数据流中的中位数

题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
*/

class Solution {
public:
	//双堆（大顶堆+小顶堆），保持大顶堆个数 == 小顶堆个数（偶数，取两堆顶平均）  或者 == 小顶堆个数 + 1（奇数，取大顶堆堆顶）
	//本来是偶数(两堆个数相等)：将元素插入小顶堆，然后小顶堆堆顶到大顶堆
	//本来是奇数（大顶堆个数多1个）：将元素插入大顶堆，然后大顶堆堆顶到小顶堆
	priority_queue<int> bq;
	priority_queue<int, vector<int>, greater<int>> sq;  //小顶堆
	int number = 0;
	void Insert(int num)
	{
		//边界条件
		if (number % 2 == 0) {
			sq.push(num);
			bq.push(sq.top());
			sq.pop();
		}
		else {
			bq.push(num);
			sq.push(bq.top());
			bq.pop();
		}
		++number;
	}

	double GetMedian()
	{
		if (number % 2 == 0) return (double)(bq.top() + sq.top()) / 2;
		else return (double)bq.top();
	}

};