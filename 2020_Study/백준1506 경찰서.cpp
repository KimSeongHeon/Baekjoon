#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<memory.h>
#include<set>
using namespace std;

vector<pair<int, int>> cost;
vector<int> node[101];
int check[101];
bool visited[101];
int parent[101];
int ans = 0;
int meet = -1;
void dfs(int n, int start) {
	for (int i = 0; i < node[n].size(); i++) {
		if (!visited[node[n][i]]) {
			visited[node[n][i]] = true;
			parent[node[n][i]] = n;
			if (check[node[n][i]] != -1) {
				if (meet == -1) {
					meet = check[node[n][i]];
				}
				else {
					if (cost[check[node[n][i]]] < cost[meet]) meet = check[node[n][i]];
				}	
			}
			dfs(node[n][i], start);
		}
		if (node[n][i] == start) {
			int temp = start;
			while (1) {
				if(meet == -1) check[temp] = start;
				else check[temp] = meet;
				temp = parent[temp];
				if (temp == start) break;
			}
		}
	}
}
int main() {
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int element;
		cin >> element;
		cost.push_back(make_pair(element, i));
	}
	sort(cost.begin(), cost.end());
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '1') {
				node[i].push_back(j);
			}
		}
	}
	memset(check, -1, sizeof(check));
	for (int i = 0; i < cost.size(); i++) {
		memset(parent, 0, sizeof(parent));
		memset(visited, false, sizeof(visited));
		if (check[i] == -1) {
			dfs(cost[i].second, cost[i].second);
		}
		meet = -1;
	}
	set<int> s;
	for (int i = 0; i < n; i++) {
		if (check[i] != -1) s.insert(check[i]);
		else ans = ans + cost[i].first;
	}
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		ans = ans + cost[*iter].first;
	}
	cout << ans;
	return 0;
}