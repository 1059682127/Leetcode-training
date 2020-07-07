//lt384

/*
打乱数组

打乱一个没有重复元素的数组。
示例:
// 以数字集合 1, 2 和 3 初始化数组。
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
solution.shuffle();

// 重设数组到它的初始状态[1,2,3]。
solution.reset();

// 随机返回数组[1,2,3]打乱后的结果。
solution.shuffle();


//思路1：随机乱置算法/Fisher-Yates 洗牌算法洗牌算法:O(N)/O(N)
在每次迭代中，生成一个范围在当前下标到数组末尾元素下标之间的随机整数。
接下来，将当前元素和随机选出的下标所指的元素互相交换，模拟从帽子取球的方法


//知识点：
//1、产生随机整数 a+rand()%len eg:[a,b] a + rand()%(b - a + 1) (a, b] a + 1 + rand()&(b - a)
//2、区别vector和std的swap： vector的swap：v1.swap(v2); 
//std::swap swap(_Tp& __a, _Tp& __b),看出swap就是通过引用来交换a，b的值
*/

class Solution {
private:
	vector<int>& oldNum, cur;
public:
	//思路1：随机乱置算法/洗牌算法
	//参考：labuladong
	//知识点：产生随机整数 a+rand()%len eg:[a,b] a + rand()%(b - a + 1) (a, b] a + 1 + rand()&(b - a)
	Solution(vector<int>& nums) :oldNum(nums), cur(nums) {

	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return oldNum;
	}
	//产生随机数
	int randInt(int Min, int Max) {
		return Min + rand() % (Max - Min + 1);
	}
	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		int len = cur.size();
		for (int i = 0; i < len; i++) {
			int rand = randInt(i, len - 1); //随机选一个数
			swap(cur[i], cur[rand]);  //交换到前面
		}
		return cur;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */