#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
#include<queue>
using namespace std;
int n; //노드 개수
bool checked[100002];
int v_depth[100002];
int v_parent[100002];
int v_index[100002];
vector<int> edge[100002];

void dfs(int x, int depth, int parent) {
	//cout << "dfs : " << x << " depth : " << depth << endl;
	v_depth[x] = depth;
	v_parent[x] = parent;
	checked[x] = true;
	for (int i = 0; i < edge[x].size(); i++) {
		if (!checked[edge[x][i]]) {
			dfs(edge[x][i], depth + 1, x);
		}

	}

}
int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		edge[node1].push_back(node2);
		edge[node2].push_back(node1);
	}
	vector<int> sub;
	for (int i = 0; i < n; i++) {
		int element;
		cin >> element;
		sub.push_back(element);
		v_index[element] = i + 1;
	}
	if (sub.front() != 1) { cout << 0; return 0; }
	
	dfs(sub.front(), 0, 0);
	v_parent[sub.front()] = 0;
	v_index[0] = 0;
	/*for (int i = 0; i < n; i++) {
		cout << v_index[v_parent[sub[i]]] << endl;
	}*/
	for (int i = 1; i < sub.size(); i++) {
		int previous = sub[i - 1];
		int now = sub[i];
		if (v_depth[previous] != v_depth[now] && v_depth[previous] + 1 != v_depth[now]) {
			cout << 0;
			return 0;
		}
		if (v_index[v_parent[now]] < v_index[v_parent[previous]]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}