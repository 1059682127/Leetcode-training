//lt295

/*
数据流的中位数

中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
例如，
[2,3,4] 的中位数是 3
[2,3] 的中位数是 (2 + 3) / 2 = 2.5
设计一个支持以下两种操作的数据结构：
void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例：
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2

//顾及插入效率
//思路1：用vector记录，插入后sort O(NlogN)/O(N)
//思路2：插入排序，数组保持排序，每插入一个元素，就进行二分查找找到适当的位置插入O(N)/O(N)
//思路3：（双堆）插入要自动排序，可以使用堆（或优先级队列）O(logN)/O(1)
//思路4：自平衡二叉搜索树，自动排序，插入时间为O(logN),跟踪中值用lo_medium,hi_medium双指针
*/

class MedianFinder {
public:
	/** initialize your data structure here. */
	//顾及插入效率
	//思路1：用vector记录，插入后sort O(NlogN)/O(N)
	vector<int> a;
	MedianFinder() {

	}
	void addNum(int num) {
		a.push_back(num);
	}
	double findMedian() {
		int len = a.size();
		sort(a.begin(), a.end());
		if (len % 2 != 0) return a[len / 2];
		else return double(a[(len / 2) - 1] + a[len / 2]) / 2;
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


//执行用时:292 ms, 在所有 C++ 提交中击败了21.05%的用户
//内存消耗 :42.1 MB, 在所有 C++ 提交中击败了98.89%的用户
class MedianFinder {
public:
	/** initialize your data structure here. */
	//顾及插入效率
	//思路2：插入排序，数组保持排序，每插入一个元素，就进行二分查找找到适当的位置插入O(N)/O(N)
	//二分搜索需要花费 O(log⁡n) 时间才能找到正确的插入位置。
	//插入可能需要花费 O(n 的时间，因为必须在容器中移动元素为新元素腾出空间。

	//知识点：
	//1、lower_bound()来自algorithm,返回值是一个迭代器,返回指向大于等于key的第一个值的位置
	//2、ForwardIter upper_bound(ForwardIter first, ForwardIter last, const _Tp& val)算法返回一个非递减序列[first, last)中的第一个大于值val的位置。
	//3、iterator insert( iterator loc, const TYPE &val ); vector成员函数，在指定位置loc前插入值为val的元素,返回指向这个元素的迭代器
	//4、STL中关于二分查找的函数有三个：lower_bound 、upper_bound 、binary_search  —— 这三个函数都运用于有序区间
	vector<int> a;
	MedianFinder() {

	}
	void addNum(int num) {
		if (a.empty()) a.push_back(num);
		else a.insert(lower_bound(a.begin(), a.end(), num), num);
	}
	double findMedian() {
		int n = a.size();
		return n & 1 ? a[n / 2] : (a[n / 2 - 1] + a[n / 2]) * 0.5;

	}
};


//执行用时:184 ms, 在所有 C++ 提交中击败了57.49%的用户
//内存消耗 :42.6 MB, 在所有 C++ 提交中击败了26.48%的用户
class MedianFinder {
public:
	/** initialize your data structure here. */
	//顾及插入效率
	//思路3：（双堆）插入要自动排序，可以使用堆（或优先级队列）
	//大顶堆lo存较小的一半，小顶堆hi存较大的一半
	//满足条件：（1）两个堆接近平衡（允许大顶堆lo数目比小顶堆hi多一个）
	//中值：（1）大顶堆所有元素小于等于堆顶元素x,大顶堆所有元素大于等于y（2）当两堆数量相同，mid = (x + y) * 0.5; 当lo = hi + 1 mid = x;
	//插入：nums先插入lo, 然后hi.push(lo.top()),lo.po(),如果导致lo.size() < hi.size(); 则 lo.push(hi.top()),lo.pop()
	priority_queue<int> lo; //大顶堆
	priority_queue<int, vector<int>, greater<int>> hi;
	MedianFinder() {

	}
	void addNum(int num) {
		lo.push(num);
		hi.push(lo.top());
		lo.pop();
		if (lo.size() < hi.size()) {
			lo.push(hi.top());
			hi.pop();
		}
	}
	double findMedian() {
		if (lo.size() == hi.size()) return (lo.top() + hi.top()) * 0.5;
		else return lo.top();

	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


//执行用时:144 ms, 在所有 C++ 提交中击败了90.69%的用户
//内存消耗 :44.9 MB, 在所有 C++ 提交中击败了7.22%的用户

class MedianFinder {
public:
	/** initialize your data structure here. */
	//顾及插入效率
	//思路4：自平衡二叉搜索树，自动排序，插入时间为O(logN),跟踪中值用lo_medium,hi_medium双指针
	//指针：当奇数时，都指向中值，偶数时，指向两个连续的元素
	//添加元素：当n = 0，push(num),都指向第一个元素。。。。

	//知识点：
	//1、multiset插入元素：data.insert(num);注意=号，如是相同元素，插入后面相同元素后面
	multiset<int> data;
	multiset<int>::iterator lo_medium, hi_medium;
	MedianFinder() :lo_medium(data.begin()), hi_medium(data.end()) {

	}
	void addNum(int num) {
		int n = data.size();  //统计插入之前的个数
		data.insert(num);

		if (n == 0) {
			lo_medium = hi_medium = data.begin();
		}
		else if (n & 1) {
			if (num < *lo_medium) lo_medium--; //注意=号，如是相同元素，插入后面
			else hi_medium++;
		}
		else {
			if (num > *lo_medium && num < *hi_medium) {
				lo_medium++;
				hi_medium--;
			}
			else if (num <= *lo_medium) lo_medium = --hi_medium;
			else lo_medium++;
		}
	}
	double findMedian() {
		return (*lo_medium + *hi_medium) * 0.5;
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */