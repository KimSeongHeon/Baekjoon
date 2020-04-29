#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int map[1001][1001];
int depth[1001][1001][2];
bool visited[1001][1001];
queue<pair<pair<int,int>,int>> q;
void bfs() {
	while (!q.empty()) {
		pair<pair<int, int>,int> temp = q.front(); q.pop();
		int x = temp.first.first;
		int y = temp.first.second;
		int k = temp.second;
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
				if (k == 1) {
					if (map[next_x][next_y] == 0 && depth[next_x][next_y][1] == -1) {
						q.push(make_pair(make_pair(next_x, next_y), 1));
						depth[next_x][next_y][1] = depth[x][y][1] + 1;
					}
				}
				else if (k == 0) {
					if (map[next_x][next_y] == 1 && depth[next_x][next_y][1] == -1) {
						q.push(make_pair(make_pair(next_x, next_y), 1));
						depth[next_x][next_y][1] = depth[x][y][0] + 1;
					}
					else if (map[next_x][next_y] == 0 && depth[next_x][next_y][0] == -1) {
						q.push(make_pair(make_pair(next_x, next_y), 0));
						depth[next_x][next_y][0] = depth[x][y][0] + 1;
					}
				}
			}
			
		}
	}
}
int main() {
	memset(depth, -1, sizeof(depth));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = (int)s[j] - 48;
		}
	}
	q.push(make_pair(make_pair(0,0),0));
	depth[0][0][0] = 1;
	depth[0][0][1] = 1;
	bfs();
	int ans0 = depth[n - 1][m - 1][0];
	int ans1 = depth[n - 1][m - 1][1];
	if (ans0 == -1 && ans1 == -1) cout << -1;
	else if (ans0 == -1 && ans1 != -1) cout << ans1;
	else if (ans0 != -1 && ans1 == -1) cout << ans0;
	else cout << min(ans0, ans1);
	return 0;
}