#include<iostream>
#include<vector>
using namespace std;

bool checked[1001];
vector<int> edge[1001];
void dfs(int v) {
	checked[v] = true;
	for (int i = 0; i < edge[v].size(); i++) {
		if (!checked[edge[v][i]]) dfs(edge[v][i]);
	}
}

int main(){
	int n, m;
	int count = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!checked[i]) {
			dfs(i);
			count++;
		}
	}
	cout << count;

}