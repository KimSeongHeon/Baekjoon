#include<iostream>
#include<string>
#include<queue>
#include<memory.h>
using namespace std;
int n, m;
int cnt;
char map[21][21];
pair<char, pair<int, int>> info[10];
pair<int, int> start; pair<int, int> dest;
int depth[21][21];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int bfs() {
	depth[start.first][start.second] = 0;
	q.push({ depth[start.first][start.second],{start.first,start.second} });
	while (!q.empty()) {
		pair<int, pair<int, int> > temp = q.top(); q.pop();
		int dep = temp.first; int x = temp.second.first; int y = temp.second.second;
		//cout << dep << " " << x << " " << y << endl;
		if (temp.second == dest) return temp.first;
		for (int i = 0; i <= 1; i++) {//ÁÂ¿ì
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if ((next_x >= 0 && next_x < n) && (next_y >= 0 && next_y < m)) {
				if (depth[next_x][next_y] == -1 && (map[next_x][next_y] == '#' || map[next_x][next_y] == 'B')) {
					depth[next_x][next_y] = depth[x][y] + 1;
					q.push({ depth[next_x][next_y],{next_x,next_y } });
				}
				if (depth[next_x][next_y] == -1 &&(map[next_x][next_y] >= '0' && map[next_x][next_y] <= '9')) {
					int num = map[next_x][next_y] - '0';
					int mod = depth[x][y] % (info[num].second.first + info[num].second.second);
					if (info[num].first == '-') {
						if (mod >= 0 && mod < info[num].second.first) {
							depth[next_x][next_y] = dep + 1;
							q.push({ depth[next_x][next_y], { next_x,next_y } });
						}
						else {
							depth[x][y] = dep + 1;
							q.push({ depth[x][y], {x,y} });
						}
					}
					else {
						if (mod >= 0 && mod < info[num].second.second) {
							depth[x][y] = dep + 1;
							q.push({ depth[x][y], {x,y} });
						}
						else {
							depth[next_x][next_y] = dep + 1;
							q.push({ depth[next_x][next_y],{next_x,next_y} });
						}
					}
				}
			}
		}
		for (int i = 2; i <= 3; i++) {//»óÇÏ
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if ((next_x >= 0 && next_x < n) && (next_y >= 0 && next_y < m)) {
				if (depth[next_x][next_y] == -1 && (map[next_x][next_y] == '#' || map[next_x][next_y] == 'B')) {
					depth[next_x][next_y] = dep + 1;
					q.push({ depth[next_x][next_y],{next_x,next_y } });
				}
				if (depth[next_x][next_y] == -1 && (map[next_x][next_y] >= '0' && map[next_x][next_y] <= '9')) {
					int num = map[next_x][next_y] - '0';
					int mod = depth[x][y] % (info[num].second.first + info[num].second.second);
					if (info[num].first == '|') {
						if (mod >= 0 && mod < info[num].second.second) {
							depth[next_x][next_y] = dep + 1;
							q.push({ depth[next_x][next_y], { next_x,next_y } });
						}
						else {
							depth[x][y] = dep + 1;
							q.push({ depth[x][y], {x,y} });
						}
					}
					else {
						if (mod >= 0 && mod < info[num].second.first) {
							depth[x][y] = dep + 1;
							q.push({ depth[x][y], {x,y} });
						}
						else {
							depth[next_x][next_y] = dep + 1;
							q.push({ depth[next_x][next_y],{next_x,next_y} });
						}
					}
				}
			}
		}

	}
	return -1;
}
int main() {
	while (1) {
		while (!q.empty()) {
			q.pop();
		}
		memset(depth, -1, sizeof(depth));
		cnt = 0; memset(map, 0, sizeof(map));
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				map[i][j] = s[j];
				if (map[i][j] == 'A') start = { i,j };
				if (map[i][j] == 'B') dest = { i,j };
				if (map[i][j] >= '0' && map[i][j] <= '9') cnt++;
			}
		}
		for (int i = 0; i < cnt; i++) {
			int num, lr, ud;
			char dir;
			cin >> num >> dir >> lr >> ud;
			info[num] = { dir,{lr,ud} };
		}
		int ans = bfs();
		if (ans == -1) cout << "impossible" << endl;
		else cout << ans << endl;
	}
	return 0;
}