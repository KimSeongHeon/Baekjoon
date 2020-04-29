#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>
#include<string>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m, k;
int map[1001][1001];
int depth[1000][1000][11];
queue<pair<pair<int, int>,int>> q;
void bfs() {
	while (!q.empty()) {
		pair<pair<int, int>, int> temp = q.front(); q.pop();
		int x = temp.first.first;
		int y = temp.first.second;
		int crush = temp.second;
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
				if (map[next_x][next_y] == 0
					&& depth[next_x][next_y][crush] == -1) {
					q.push(make_pair(make_pair(next_x, next_y), crush));
					depth[next_x][next_y][crush] = depth[x][y][crush] + 1;
				}
				else if (map[next_x][next_y] == 1 && crush < k) {
					if (depth[next_x][next_y][crush + 1] == -1) {
						q.push(make_pair(make_pair(next_x, next_y), crush+1));
						depth[next_x][next_y][crush + 1] = depth[x][y][crush] + 1;
					}
				}
			}
			
		}
	}
}
int main() {
	memset(depth, -1, sizeof(depth));
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = (int)s[j] - 48;
		}
	}
	q.push(make_pair(make_pair(0, 0),0));
	depth[0][0][0] = 1;
	bfs();
	int ans = 987654321;
	for (int i = 0; i <= k; i++) {
		if (depth[n - 1][m - 1][i] != -1) {
			ans = min(ans, depth[n - 1][m - 1][i]);
		}
	}
	if (ans == 987654321) cout << -1;
	else cout << ans;
	return 0;
}