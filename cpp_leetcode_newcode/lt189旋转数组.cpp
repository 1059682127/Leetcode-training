//lt189

/*
旋转数组

给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
示例 1:
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:
输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释:
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:
尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法。

//思路1：循环移位算子p，移动n步，p^n*x:O(N)/O(1)
//思路2：new vector,根据对应0~k%len,i~(k+i)%len O(1)/O(N)
////思路3：环状替代，借鉴大神众人都是孤独的思路：环状替代和我的思路一致，不过我觉得这样解释可能更容易理解。
把元素看做同学，把下标看做座位，大家换座位。第一个同学离开座位去第k+1个座位，第k+1个座位的同学被挤出去了，
他就去坐他后k个座位，如此反复。但是会出现一种情况，就是其中一个同学被挤开之后，坐到了第一个同学的位置（空位置，
没人被挤出来），但是此时还有人没有调换位置，这样就顺着让第二个同学换位置。 那么什么时候就可以保证每个同学都换完了呢？
n个同学，换n次，所以用一个count来计数即可。
//环状替换的例外情况并不仅仅在n%k==0时发生, 而是当k和n的最大公约数不为1时出现, 比如n=24, k=14时, 
其最大公约数为2, 每次环状替换会替换12个数字, 所以需要遍历两次.24 与 14的最小公倍数出现在7*2*12

//思路4:三次反转（最清晰）O(N)/O(1)
*/


//思路2：new vector,根据对应0~k%len,i~(k+i)%len
//执行用时:8 ms, 在所有 C++ 提交中击败了83.95%的用户
//内存消耗 :10.2 MB, 在所有 C++ 提交中击败了5.01%的用户
class Solution {
public:

	
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		vector<int> temp(len);
		for (int i = 0; i < len; i++) {
			temp[(k + i) % len] = nums[i];
		}
		nums = temp;
		return;
	}
};


class Solution {
public:

	//思路3：环状替代，借鉴大神众人都是孤独的思路：环状替代和我的思路一致，不过我觉得这样解释可能更容易理解。把元素看做同学，把下标看做座位，大家换座位。第一个同学离开座位去第k+1个座位，第k+1个座位的同学被挤出去了，他就去坐他后k个座位，如此反复。但是会出现一种情况，就是其中一个同学被挤开之后，坐到了第一个同学的位置（空位置，没人被挤出来），但是此时还有人没有调换位置，这样就顺着让第二个同学换位置。 那么什么时候就可以保证每个同学都换完了呢？n个同学，换n次，所以用一个count来计数即可。
	//环状替换的例外情况并不仅仅在n%k==0时发生, 而是当k和n的最大公约数不为1时出现, 比如n=24, k=14时, 其最大公约数为2, 每次环状替换会替换12个数字, 所以需要遍历两次.24 与 14的最小公倍数出现在7*2*12
	//知识点：do{}while(condition); 条件至少会被执行一次
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		k = k % len;
		int count = 0;//计数器，记住换的次数
		for (int start = 0; count < len; start++) {
			int current = start;
			int pre = nums[current];
			do {
				//进行移位知道current = start
				int next = (current + k) % len; //计算被替换的位置
				int temp = nums[next];
				nums[next] = pre;
				pre = temp;
				current = next;
				count++; //计数
			} while (current != start);
		}
	}
};

class Solution {
public:
	//思路4:三次反转（最清晰）O(N)/O(1)
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		k = k % len;
		reserve(nums, 0, len - 1);
		reserve(nums, 0, k - 1);
		reserve(nums, k, len - 1);
		return;
	}
	void reserve(vector<int>& nums, int lo, int hi) {
		while (lo < hi) {
			int temp = nums[lo];
			nums[lo++] = nums[hi];
			nums[hi--] = temp;
		}
		return;
	}
};
