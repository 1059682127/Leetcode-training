//lt785
/*
�ж϶���ͼ

����һ������ͼgraph�������ͼΪ����ͼʱ����true��

��������ܽ�һ��ͼ�Ľڵ㼯�Ϸָ�������������Ӽ�A��B����ʹͼ�е�ÿһ���ߵ������ڵ�һ������A���ϣ�һ������B���ϣ����Ǿͽ����ͼ��Ϊ����ͼ��

graph�������ڽӱ�ʽ������graph[i]��ʾͼ����ڵ�i���������нڵ㡣ÿ���ڵ㶼��һ����0��graph.length-1֮�����������ͼ��û���Ի���ƽ�бߣ� graph[i] �в�����i������graph[i]��û���ظ���ֵ��


ʾ�� 1:
����: [[1,3], [0,2], [1,3], [0,2]]
���: true
����:
����ͼ����:
0----1
|    |
|    |
3----2
���ǿ��Խ��ڵ�ֳ�����: {0, 2} �� {1, 3}��

//˼·1���ݹ飨Ⱦɫ����
//˼·2��������Ⱦɫ��/̰��˼�룩
*/

class Solution {
public:
	//˼·1���ݹ飨Ⱦɫ����
	//�������㣬��ÿ��δ���ʵĶ���u��Ⱦɫһ����ɫ�� DFS(u)
	//����u��ÿ������v�����vδ������,��u,v�ò�ͬɫ�������DFS(v)�����u,vͬɫ����return false;

	//Trick1:�����Ƿ���ͨͼ�����Ҫ���ж��dfs��ֱ�������������ж���
	//Trick2:�ù�ϣ��û���ʵ���bool�����ɫ��true�����ɫ
	map<int, bool> isVisited;   //bool�����ɫ��true�����ɫ
	bool isBipartite(vector<vector<int>>& graph) {
		int N = graph.size();
		for (int i = 0; i < N; ++i) {
			if (!isVisited.count(i)) {
				isVisited[i] = true;
				if (!DFS(i, graph)) return false;
			}
		}
		return true;
	}
	bool DFS(int u, vector<vector<int>>& graph) {
		//�߽�����
		for (auto v : graph[u]) {
			if (!isVisited.count(v)) {
				isVisited[v] = !isVisited[u];
				if (!DFS(v, graph)) return false;
			}
			else {
				if (isVisited[u] == isVisited[v]) return false;
			}
		}
		return true;
	}

};


class Solution {
public:
	//˼·2���ݹ飨Ⱦɫ��/̰��˼�룩
	//�������㣬��ÿ��δ���ʵĶ���u��Ⱦɫһ����ɫ�� DFS(u)
	//����u��ÿ������v�����vδ������,��u,v�ò�ͬɫ�������DFS(v)�����u,vͬɫ����return false;
	//̰��˼�룺����ʹ��̰��˼���ͼ��ɫ��һ���ڵ�Ϊ��ɫ��˵�����������ڽӵ�Ϊ��ɫ�������ڽӵ�������ڽӵ�Ϊ��ɫ

	//Trick1:�����Ƿ���ͨͼ�����Ҫ���ж��dfs��ֱ�������������ж���
	//Trick2:�ù�ϣ��û���ʵ���bool�����ɫ��true�����ɫ
	map<int, bool> isVisited;   //bool�����ɫ��true�����ɫ
	bool isBipartite(vector<vector<int>>& graph) {
		int N = graph.size();
		for (int start = 0; start < N; ++start) {
			if (!isVisited.count(start)) {
				isVisited[start] = true;
				stack<int> data;
				data.push(start);
				while (!data.empty()) {
					int cur = data.top();
					data.pop();
					//̰���㷨����ÿ���ھӶ�������ɫ
					for (auto nei : graph[cur]) {
						if (!isVisited.count(nei)) {
							isVisited[nei] = !isVisited[cur];
							data.push(nei);
						}
						else {
							if (isVisited[cur] == isVisited[nei]) return false;
						}
					}
				}
			}
		}
		return true;
	}
};