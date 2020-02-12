#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
vector<pair<int, int>> edge[100001];
bool checked[100001];
int answer = -99999999;
int u;
void dfs(int x, int weight) {
	checked[x] = true;
	bool haveSon = false;
	for (int i = 0; i < edge[x].size(); i++) {
		if (!checked[edge[x][i].first]) {
			dfs(edge[x][i].first, weight + edge[x][i].second);
			haveSon = true;
		}
	}
	if (!haveSon) {
		answer = max(answer, weight);
		if (answer == weight) u = x;
	}
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int current;
		cin >> current;
		while (1) {
			int node, dist;
			cin >> node;
			if (node == -1) break;
			else {
				cin >> dist;
				edge[current].push_back(make_pair(node, dist));
				edge[node].push_back(make_pair(current, dist));
			}
		}
	}
	dfs(1, 0);
	memset(checked, false, sizeof(checked));
	dfs(u, 0);
	cout << answer;
	return 0;
}