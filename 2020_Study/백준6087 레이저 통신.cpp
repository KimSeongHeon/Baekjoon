#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
int n, m;
int map[101][101];
int depth[101][101];
vector<pair<int, int>> v;
queue<pair<int, int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'C') v.push_back(make_pair(i,j));
		}
	}
	memset(depth, -1, sizeof(depth));
	q.push(v[0]);
	depth[v[0].first][v[0].second] = 0;
	while (!q.empty()) {
		pair<int, int> temp = q.front(); q.pop();
		int x = temp.first;
		int y = temp.second;
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			while (1) {
				if (!(next_x >= 0 && next_x < m && next_y >= 0 && next_y < n)) {
					break;
				}
				if (map[next_x][next_y] == '*') {
					break;
				}
				if ((depth[next_x][next_y] == -1)) {
					q.push(make_pair(next_x, next_y));
					depth[next_x][next_y] = depth[x][y] + 1;
				}
				next_x = next_x + dx[i];
				next_y = next_y + dy[i];
			}
		}
	}
	cout << depth[v[1].first][v[1].second]-1;

}