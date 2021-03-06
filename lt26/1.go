package lt26

// 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

// 可能的解法：
// 1. 暴力遍历。
	// [0,0,1,1,1,2,2,3,3,4],
	// 用一个变量index存储前缀的有序不重复子数组最后元素下标，例如第一次扫到0， 所以index=0,
	// 继续扫当前为0，若下一个仍为0，index置之不理；
	// 接着得到1，与0不同（这里不作大小比较，题给排序数组），把1和index后一位交换，并更新index = 1
	// 如此往复， 当数组遍历至最后一个为止。 返回num和nums[:item+1]

func Sol_1_1(nums []int) int {

	// 这里不检查排序数组为空的情况，为空还叫啥排序数组

	var index int
	for i:=0; i<len(nums); i++ {
		if nums[i] > nums[index] {	//默认从小到大排好序的数组，所以i一定比index大，除了少数情况会等于
			if i > index + 1 {  // 说明中间有重复数字，只要所有数字有一个数字被重复了，都需要这样判断。这可以是下一版本的优化点，
								// 可以用一个标志标志是否前边出现了重复，一旦出现，后边所有，必然需要这样操作
				nums[index+1] = nums[i]	// 后边的数字懒得管
				index++
				continue	// 跳出该次循环
			}
			// 如果中间没有隔位的话，就直接将index加1
			index++
		}
		// 若现在的数没有比前缀不重复子数组最大值大，那说明重复了，啥也不干
	}

	return index+1
}

// 在解法1基础上引入一个标志位标记是否出现过重复，出现过则后边不需要检查下标是否隔1以上，直接换值
// 该解法在test文件基准测试中没表现出提升，原因在于执行次数和输入数组不够多样复杂。在leetcode平台提交结果确实优于解法1
func Sol_1_2(nums []int) int {

	var index int
	var repeated bool
	for i:=0; i<len(nums); i++ {
		if nums[i] > nums[index] {
			// 从前向后遍历，开始repeated一定为false
			if repeated {
				nums[index+1] = nums[i]
				index++
				continue
			}

			// 第一次出现重复后将repeated至true
			if i > index + 1 {
				repeated = true
				nums[index+1] = nums[i]
				index++
				continue
			}
			index++
		}
		// 若现在的数没有比前缀不重复子数组最大值大，那说明重复了，啥也不干
	}

	return index+1
}

// 在解法1基础上简化
func Sol_1_3(nums []int) int {

	// 这里不检查排序数组为空的情况，为空还叫啥排序数组

	var index int
	for i:=1; i<len(nums); i++ {
		if nums[i] > nums[i-1] {
			index++
			nums[index] = nums[i]
		}
		// 若现在的数没有比前缀不重复子数组最大值大，那说明重复了，啥也不干
	}

	return index+1
}

// 倒序遍历，数组前缩
func Sol_1_4(nums []int) int {
	// 倒序遍历，遇同则将数组前缩
	for i:=len(nums)-1; i>0; i-- {      // l-1, l-2, ..., 2, 1, (0)

		if nums[i] == nums[i-1] {
			nums = append(nums[:i], nums[i+1:]...)
		}
	}
	return len(nums)
}