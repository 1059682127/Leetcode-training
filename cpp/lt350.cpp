//lt350

/*
两个数组的交集 II

给定两个数组，编写一个函数来计算它们的交集。
示例 1:
输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:
输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
说明：
输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。
进阶:
如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

//思路1：双哈希表O(N+M)/O(min(N,M))
//技巧1：将结果保存在nums1上，不用开辟另外的空间
//技巧2：选择较短的子串开始记录哈希表，可以节省哈希表的空间


改进思路2：单哈希表O(M+N)/O(MIN(M,N))
//先在 HashMap 记录一个数组中的存在的数字和对应出现的次数。然后，我们遍历第二个数组，检查数字在 HashMap 中是否存在，
如果存在且计数为正，则将该数字添加到答案并减少 HashMap 中的计数。

思路3：sort+双指针O(NlogN + MlogM)/O(1)
*/


class Solution {
public:
	//思路：双哈希表
	//技巧1：将结果保存在nums1上，不用开辟另外的空间
	//技巧2：选择较短的子串开始记录哈希表，可以节省哈希表的空间
	//知识点：map操作
	//确定元素是否存在：map.count(key)
	//访问元素：map[key]/map<int, int>::iterator->first,不能map[1]
	//map基于红黑树，自动排序过了
	//返回vector下标为0到k的范围：return vector(nums1.begin(), nums1.begin() + k);
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		map<int, int> a;
		int len1 = nums1.size();
		int len2 = nums2.size();
		//哈希表a记录nums1中字符出现字数
		for (int i = 0; i < len1; i++) {
			a[nums1[i]]++;
		}
		//用另外一个哈希表b，如果nums2中字符在nums1中出现，-1
		map<int, int> b(a.begin(), a.end());
		for (int i = 0; i < len2; i++) {
			if (b.count(nums2[i])) b[nums2[i]]--;
		}
		//统计两个哈希表之间的差距，即为交集
		int k = 0;//记录交集个数
		int size1, size2;
		for (auto it = a.begin(); it != a.end(); it++) {
			size1 = it->second;
			size2 = b[it->first];
			if (size1 > size2) {
				int diff = (size2 >= 0) ? size1 - size2 : size1;
				for (int j = 0; j < diff; j++) {
					nums1[k] = it->first;   //将结果保存在nums1上，不用开辟另外的空间
					k++;
				}
			}
		}
		return vector(nums1.begin(), nums1.begin() + k);
	}
};

class Solution {
public:
	//思路2：单哈希表（先在 HashMap 记录一个数组中的存在的数字和对应出现的次数。然后，我们遍历第二个数组，检查数字在 HashMap 中是否存在，
	//如果存在且计数为正，则将该数字添加到答案并减少 HashMap 中的计数。）
	//选择长度较短的建立哈希表
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size(), len2 = nums2.size();
		if (len1 > len2) return intersect(nums2, nums1);  //交换数组
		map<int, int>a;
		//哈希表a记录nums1中字符出现字数
		for (int i = 0; i < len1; i++) {
			a[nums1[i]]++;
		}
		int k = 0; //记录交集个数
		for (int i = 0; i < len2; i++) {
			//如果在哈希表中存在且计数为正
			if (a.count(nums2[i]) && a[nums2[i]]-- > 0) {
				nums1[k++] = nums2[i];
			}
		}
		return vector(nums1.begin(), nums1.begin() + k);
	}
};