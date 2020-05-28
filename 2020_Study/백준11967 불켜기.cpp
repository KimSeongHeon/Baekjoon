#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
#include<set>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> v[101][101];
	int possible[101][101];
	set<pair<int, int>> on;
	bool visited[101][101];
	memset(possible, 0, sizeof(possible));
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < m; i++) {
		int start_x, start_y, dest_x, dest_y;
		cin >> start_x >> start_y >> dest_x >> dest_y;
		v[start_x][start_y].push_back({ dest_x,dest_y });
	}
	queue<pair<int, int>> q;
	q.push({1,1});
	possible[1][1] = 1;
	on.insert({ 1, 1 });
	visited[1][1] = true;
	while (!q.empty()) {
		int pre = on.size();
		pair<int, int> temp = q.front(); q.pop();
		int x = temp.first;
		int y = temp.second;
		for (int i = 0; i < v[x][y].size(); i++) {
			possible[v[x][y][i].first][v[x][y][i].second] = 1;
			on.insert({ v[x][y][i].first,v[x][y][i].second });
			if (pre != on.size()) memset(visited, false, sizeof(visited));
		}
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 1 && next_x <= n && next_y >= 1 && next_y <= n) {
				if (!visited[next_x][next_y] && possible[next_x][next_y] == 1) {
					q.push({ next_x,next_y });
					visited[next_x][next_y] = true;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (possible[i][j] == 1) {
				//cout << i << " " << j << endl;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}