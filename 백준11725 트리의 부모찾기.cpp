#include<iostream>
#include<vector>
using namespace std;

vector<int> edge[100001];
bool checked[100001];
int parent[100001];
void dfs(int x) {
	checked[x] = true;
	for (int i = 0; i < edge[x].size(); i++) {
		if (!checked[edge[x][i]]) {
			parent[edge[x][i]] = x;
			dfs(edge[x][i]);
		}
	}
}
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		edge[node1].push_back(node2);
		edge[node2].push_back(node1);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) {
		printf("%d\n", parent[i]);
	}
}