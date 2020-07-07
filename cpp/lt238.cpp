//lt238

/*
除自身以外数组的乘积

给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
示例:
输入: [1,2,3,4]
输出: [24,12,8,6]
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

//思路1：做两次遍历，第一次计算所有元素的乘积，第二次遍历，用总乘积除以当前元素(当数组中不存在0)
//Trick1:数0个数，0个（用如上思路）；1个（0除为其它元素乘积，非0处结果为0）；多于1个（都为0）

//思路2：（不用除法）左右乘积列表O(N)/O(N)

//思路3：（不用额外空间）左右乘积列表O(N)/O(1)
*/

class Solution {
public:
	//思路1：做两次遍历，第一次计算所有元素的乘积，第二次遍历，用总乘积除以当前元素(当数组中不存在0)
	//Trick1:数0个数，0个（用如上思路）；1个（0除为其它元素乘积，非0处结果为0）；多于1个（都为0）
	vector<int> productExceptSelf(vector<int>& nums) {
		int all = 1;
		vector<int> vZero;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) vZero.push_back(i);
			else all *= nums[i];
		}
		int zeroNum = vZero.size();
		if (zeroNum == 0) {
			for (int i = 0; i < nums.size(); i++) {
				nums[i] = all / nums[i];
			}
			return nums;
		}
		else if (zeroNum == 1) {
			for (int i = 0; i < nums.size(); i++) {
				nums[i] = (i == vZero[0]) ? all : 0;
			}
			return nums;
		}
		else {
			return vector(nums.size(), 0);
		}


	}
};


//执行用时:8 ms, 在所有 C++ 提交中击败了99.45%的用户
//内存消耗 :14.9 MB, 在所有 C++ 提交中击败了5.06%的用户
class Solution {
public:
	//思路2：（不用除法）左右乘积列表O(N)/O(N)
	//两组数L[i],R[i],L[i]记录i左边元素的乘积，R[i]记录i右边元素的乘积
	//动态规划，L[i] = L[i - 1]*nums[i - 1]; R[i] = R[i + 1]* nums[i + 1];base sample: L[0] = 1; R[len - 1] = 1;
	//最后遍历nums,记录nums[i] = L[i] * R[i]
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> L(len, 1), R(len, 1);
		for (int i = 1; i < len; i++) {
			L[i] = L[i - 1] * nums[i - 1];
		}
		for (int i = len - 2; i >= 0; i--) {
			R[i] = R[i + 1] * nums[i + 1];
		}
		for (int i = 0; i < len; i++) {
			nums[i] = L[i] * R[i];
		}
		return nums;
	}
};

//执行用时:12 ms, 在所有 C++ 提交中击败了94.77%的用户
//内存消耗 :14.4 MB, 在所有 C++ 提交中击败了5.06%的用户


class Solution {
public:
	//思路3：（不用额外空间）左右乘积列表O(N)/O(1)
	//由于输出数组不算在空间复杂度内，所以可以用L[i]输出，另外动态构造R[i]
	//遍历一遍，记录L[i](即answer[i]),然后从右往左，计算右边元素的乘积R，更新answer[i] = answer[i] * R;
	//然后R = R * nums[i]
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> L(len, 1);
		for (int i = 1; i < len; i++) {
			L[i] = L[i - 1] * nums[i - 1];
		}
		int R = 1;
		for (int i = len - 1; i >= 0; i--) {
			L[i] = L[i] * R;
			R = R * nums[i];
		}

		return L;
	}
};