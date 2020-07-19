/*
��Ŀ����
��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� ���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2��
*/

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	//��ϣ��
	bool duplicate(int numbers[], int length, int* duplication) {
		unordered_map<int, int> map;
		for (int i = 0; i < length; ++i) {
			map[numbers[i]]++;
			if (map[numbers[i]] > 1) {
				duplication[0] = numbers[i];
				return true;
			}
		}
		return false;
	}
};

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	//��ϣ��
	//˼·����valueת�Ƶ���Ӧindex����nums[i] == nums[nums[i]]
	bool duplicate(int numbers[], int length, int* duplication) {
		if (length == 0) return false;
		for (int i = 0; i < length; ++i) {
			//ֱ��ֵ������ƥ��
			while (numbers[i] != i) {
				if (numbers[i] == numbers[numbers[i]]) {
					duplication[0] = numbers[i];
					return true;
				}
				swap(numbers, i, numbers[i]);
			}
		}
		return false;
	}
	void swap(int numbers[], int i, int j) {
		int temp = numbers[i];
		numbers[i] = numbers[j];
		numbers[j] = temp;
	}
};