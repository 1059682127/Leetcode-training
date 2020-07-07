//lt384

/*
��������

����һ��û���ظ�Ԫ�ص����顣
ʾ��:
// �����ּ��� 1, 2 �� 3 ��ʼ�����顣
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// �������� [1,2,3] �����ؽ�����κ� [1,2,3]�����з��صĸ���Ӧ����ͬ��
solution.shuffle();

// �������鵽���ĳ�ʼ״̬[1,2,3]��
solution.reset();

// �����������[1,2,3]���Һ�Ľ����
solution.shuffle();


//˼·1����������㷨/Fisher-Yates ϴ���㷨ϴ���㷨:O(N)/O(N)
��ÿ�ε����У�����һ����Χ�ڵ�ǰ�±굽����ĩβԪ���±�֮������������
������������ǰԪ�غ����ѡ�����±���ָ��Ԫ�ػ��ཻ����ģ���ñ��ȡ��ķ���


//֪ʶ�㣺
//1������������� a+rand()%len eg:[a,b] a + rand()%(b - a + 1) (a, b] a + 1 + rand()&(b - a)
//2������vector��std��swap�� vector��swap��v1.swap(v2); 
//std::swap swap(_Tp& __a, _Tp& __b),����swap����ͨ������������a��b��ֵ
*/

class Solution {
private:
	vector<int>& oldNum, cur;
public:
	//˼·1����������㷨/ϴ���㷨
	//�ο���labuladong
	//֪ʶ�㣺����������� a+rand()%len eg:[a,b] a + rand()%(b - a + 1) (a, b] a + 1 + rand()&(b - a)
	Solution(vector<int>& nums) :oldNum(nums), cur(nums) {

	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return oldNum;
	}
	//���������
	int randInt(int Min, int Max) {
		return Min + rand() % (Max - Min + 1);
	}
	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		int len = cur.size();
		for (int i = 0; i < len; i++) {
			int rand = randInt(i, len - 1); //���ѡһ����
			swap(cur[i], cur[rand]);  //������ǰ��
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