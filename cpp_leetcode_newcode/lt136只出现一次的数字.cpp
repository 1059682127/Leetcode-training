//lt136

/*题目描述
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
示例 1:
输入: [2, 2, 1]
	输出 : 1
	示例 2 :
	输入 : [4, 1, 2, 1, 2]
	输出 : 4

思路:
1、暴力法，遍历O(n2)/O(1)，不考虑
2、哈希表：遍历nums(O(n))，查看hash_table中是否有当前元素的键（O(1)），没有的话将当前元素作为键插入，最后获取值为1的键，O(n)/O(n),不符合
3、sort+遍历：O(nlog2n)/0(1)，可通过

官方题解：
1、数学知识：2∗(a+b+c)−(a+a+b+b+c)=c，遍历一遍，用hash_table记录不同的元素（O(N)），再遍历其求和(O(N)),再遍历nums求和，O(N)/O(1)
2、位操作：a XOR 0 = a, a XOR a = 0, 且 XOR 满足交换律和结合律，只要将遍历一遍，将所有元素进行XOR运算，O(N)/O(1)

知识点：
1、异或符号^
2、map操作，提供了key-value的插入和查找功能，
插入        map[key]=value;
查找        if (map.find(key)!=map.end());
迭代器删除  map.erase(it);
元素删除    int n = map.erase(key);   //删除了返回1，否则返回0
用迭代器范围删除 map.erase(map.begin(), map.end());
*/



class Solution {
public:
	//采用sort排序，然后进行遍历，直到找到第一个不重复的元素
	int singleNumber(vector<int>& nums) {
		int len = nums.size();
		int cur;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < len; i += 2) {
			cur = nums[i];
			if (i == len - 1) {
				return cur;
			}
			if (cur != nums[i + 1]) {
				return cur;
			}
		}
		return -1; //最后找不到
	}

	//采用哈希列表
	int singleNumber(vector<int>& nums) {
		map<int, int> a;
		for (int i = 0; i < nums.size(); i++) {
			//如果已经在map中，从Map中删掉
			if (a[nums[i]] == 1) {   //if(a.find(nums[i]) != a.end()){
				a.erase(nums[i]);
			}
			else {
				a[nums[i]]++;
			}
		}
		return a.begin()->first;
	}

	//采用异或操作
	int singleNumber(vector<int>& nums) {
		int a = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			a ^= nums[i];
		}
		return a;
	}

};
