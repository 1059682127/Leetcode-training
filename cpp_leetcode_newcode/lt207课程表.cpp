//lt207
/*
�γ̱�

�������ܹ��� n �ſ���Ҫѡ����Ϊ 0 �� n-1��

��ѡ��ĳЩ�γ�֮ǰ��ҪһЩ���޿γ̡� ���磬��Ҫѧϰ�γ� 0 ������Ҫ����ɿγ� 1 ��������һ��ƥ������ʾ����: [0,1]

�����γ������Լ����ǵ��Ⱦ��������ж��Ƿ����������пγ̵�ѧϰ��

ʾ�� 1:

����: 2, [[1,0]]
���: true
����: �ܹ��� 2 �ſγ̡�ѧϰ�γ� 1 ֮ǰ������Ҫ��ɿγ� 0���������ǿ��ܵġ�

//˼·1����������+�����������+��ȱ�
//˼·2�������������0(N+M)/O(N)
*/
class Solution {
public:
	//˼·1����������+�����������+��ȱ�
	//�����Լ��Ϊ���γ̰���ͼ�Ƿ��� �����޻�ͼ(DAG)�����γ̼�涨��ǰ�������������ܹ����κλ�·������γ�ǰ����������������

	//˼·��ͨ�� �������� �жϴ˿γ̰���ͼ�Ƿ��� �����޻�ͼ(DAG)�� 
	//���������Ƕ� DAG �Ķ����������ʹ�ö�ÿһ�������(u,v)������u��v�ȳ��֣��������¼�У�

	//ͨ���γ�ǰ�������б� prerequisites ���Եõ��γ̰���ͼ�� �ڽӾ��� adjacency

	//�㷨���裺
	//1��ͳ����ȱ�indegrees
	//2�����Ϊ0�������
	//3����Ԫ�س����У���ɾ���ýڵ�pre���������ڽӽڵ�����-1�����ڽӽڵ�����Ϊ0��˵�����ڽӽڵ��ǰ�����Ѿ���ɾ������������У�
	//4��������ʱ��numCourses--�� ����������޻�ͼ�����еĽڵ㶼��ӳ��ӹ��������������

	//ʱ��:O(N+M),����ͼ��Ҫ�������еĽڵ���ڱ�
	//�ռ�:O(N),��Ҫͳ�������
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> indegrees(numCourses, 0);
		for (int i = 0; i < prerequisites.size(); ++i) indegrees[prerequisites[i][0]]++;
		queue<int> q;
		for (int i = 0; i < numCourses; ++i) {
			if (indegrees[i] == 0) q.push(i);
		}
		while (!q.empty()) {
			int pre = q.front();
			q.pop();
			--numCourses;
			for (int i = 0; i < prerequisites.size(); ++i) {
				if (prerequisites[i][1] == pre) {
					if (--indegrees[prerequisites[i][0]] == 0) q.push(prerequisites[i][0]);
				}

			}
		}
		return numCourses == 0;
	}
};

class Solution {
public:
	//˼·2�������������0(N+M)/O(N)

	//�������
	//flag��ǣ�δ���ʹ���0���������ڵ��DFS���ʹ���-1�������ڵ��DFS���ʹ���1

	//DFS���̣�
	//��ֹ������
	//(1)���flag = -1�����ʾ�������ڵ��������������ظ�������return true��
	//(2)���flag = 1, ���ʾ�����ڵ��DFS���ʹ���return false;
	//����ǰ���ʽڵ� i ��Ӧ flag[i] ��1��������䱻���� DFS ���ʹ���
	//�ݹ���ʵ�ǰ�ڵ� i �������ڽӽڵ� j�������ֻ�ֱ�ӷ���false;
	//��ǰ�ڵ������ڽӽڵ��ѱ���������û�з��ֻ����򽫵�ǰ�ڵ� flag ��Ϊ-1��������true

	//Trick1:�����ڽӾ���
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> isVisited(numCourses, 0);
		vector<vector<int>> adjacency(numCourses, vector<int>(numCourses));
		for (auto& req : prerequisites) adjacency[req[1]][req[0]] = 1;
		for (int i = 0; i < numCourses; ++i) {
			if (isVisited[i] == 0 && !DFS(i, adjacency, isVisited)) return false;
		}
		return true;
	}
	bool DFS(int u, vector<vector<int>>& adjacency, vector<int>& isVisited) {
		if (isVisited[u] == -1) return true;
		if (isVisited[u] == 1) return false;
		isVisited[u] = 1;  //�ڱ��ַ��ʹ�
		for (int v = 0; v < adjacency[u].size(); ++v) {
			if (adjacency[u][v] && !DFS(v, adjacency, isVisited)) return false;
		}
		isVisited[u] = -1;  //���ַ������
		return true;
	}
};