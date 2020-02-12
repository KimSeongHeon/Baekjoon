#include<iostream>
#include<queue>
#include<deque>
#include<string>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int miro[101][101];
bool checked[101][101];
int depth[101][101];
int n, m;
int num = 0;
deque<pair<int,int>> q;
void bfs() {
	q.push_back(make_pair(1, 1)); checked[1][1] = true;
	while (!q.empty()) {
		pair<int, int> x = q.front(); q.pop_front();
		//cout << x.first << " " << x.second << endl;
		for (int i = 0; i < 4; i++) {
			int next_x = x.first + dx[i];
			int next_y = x.second + dy[i];
			if (next_x <= 0 || next_y <= 0 || next_x > n || next_y > m) continue;
			if (!checked[next_x][next_y]) {
				if (miro[next_x][next_y] == 0) {
					checked[next_x][next_y] = true;
					depth[next_x][next_y] = depth[x.first][x.second];
					q.push_front(make_pair(next_x, next_y));
				}
			}
			if (!checked[next_x][next_y]) {
				if (miro[next_x][next_y] == 1) {
					checked[next_x][next_y] = true;
					depth[next_x][next_y] = depth[x.first][x.second] + 1;
					q.push_back(make_pair(next_x, next_y));
				}
			}
		}
	
	}
}
int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			miro[i][j] = s.at(j-1) - 48;
		}
	}
	bfs();
	cout << depth[n][m];
	return 0;
}