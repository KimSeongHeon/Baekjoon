#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<queue>
using namespace std;

int n, m, v;
vector<int> node[1001];
bool checked[1001];
queue<int> q;
void dfs(int v) {
	cout << v << " ";
	checked[v] = true;
	for (int i = 0; i < node[v].size(); i++) {
		if(!checked[node[v][i]]) dfs(node[v][i]);
	}
}
void bfs(int v) {
	cout << v << " ";
	checked[v] = true; q.push(v);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < node[x].size(); i++) {
			if (!checked[node[x][i]]) {
				checked[node[x][i]] = true;
				cout << node[x][i] << " ";
				q.push(node[x][i]);
			}
		}
	}
}
int main() {
	memset(checked, false, sizeof(checked));
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int pre, pos;
		cin >> pre >> pos;
		node[pre].push_back(pos);
		node[pos].push_back(pre);
	}
	for (int i = 0; i < n; i++) {
		sort(node[i].begin(), node[i].end());
	}
	dfs(v);
	cout << endl;
	memset(checked, false, sizeof(checked));
	bfs(v);
}