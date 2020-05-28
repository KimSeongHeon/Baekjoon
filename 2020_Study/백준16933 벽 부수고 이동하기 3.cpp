#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
int n, m, k;
int map[1001][1001];
int depth[1001][1001][11][2];
queue<pair<pair<int,int>,pair<int,int>>> q;
int dx[4] = {0,0,1,-1 };
int dy[4] = {1,-1,0,0 };
//0:낮 , 1:밤
void bfs() {
	while (!q.empty()) {
		pair<pair<int, int>, pair<int, int>> temp = q.front(); q.pop();
		int x = temp.first.first;
		int y = temp.first.second;
		int crush = temp.second.first;
		int daytime = temp.second.second;
		for (int i = 0; i < 4; i++) {//움직이는 경우
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
				if (daytime == 0) {
					//낮 일때
					if (map[next_x][next_y] == 0 && depth[next_x][next_y][crush][1] == -1) { //다음것이 0
						q.push(make_pair(make_pair(next_x, next_y), make_pair(crush,1)));
						depth[next_x][next_y][crush][1] = depth[x][y][crush][0] + 1;
					}
					else if (map[next_x][next_y] == 1 && depth[next_x][next_y][crush+1][1] == -1 && crush<k) {
						q.push(make_pair(make_pair(next_x, next_y), make_pair(crush+1, 1)));
						depth[next_x][next_y][crush+1][1] = depth[x][y][crush][0] + 1;
					}
				}
				else if (daytime == 1) {
					//밤 일때
					if (map[next_x][next_y] == 0 && depth[next_x][next_y][crush][0] == -1) { //다음것이 0
						q.push(make_pair(make_pair(next_x, next_y), make_pair(crush, 0)));
						depth[next_x][next_y][crush][0] = depth[x][y][crush][1] + 1;
					}
					//가만히 있는것은 밤일때만 의미가 있음
					if (depth[x][y][crush][0] == -1) {
						q.push(make_pair(make_pair(x, y), make_pair(crush, 0)));
						depth[x][y][crush][0] = depth[x][y][crush][1] + 1;
					}
				}
			}
		}
	}
}
int main(){
	memset(depth, -1, sizeof(depth));
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = (int)s[j] - 48;
		}
	}
	q.push(make_pair(make_pair(0,0),make_pair(0,0)));
	depth[0][0][0][0] = 1;
	bfs();
	int ans = 987654321;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < 2; j++) {
			if (depth[n - 1][m - 1][i][j] != -1) ans = min(ans, depth[n - 1][m - 1][i][j]);
		}
	}
	if (ans == 987654321) cout << -1;
	else cout << ans;
	return 0;
}