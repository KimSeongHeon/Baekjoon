#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m;
int maze[101][101];
int parent[101][101];
bool checked[101][101];
queue<pair<int, int>> q;
void bfs() {
	while (!q.empty()) {
		pair<int,int> x = q.front(); q.pop();
		//cout << "bfs : " << x.first << " " << x.second << endl;
		for (int i = 0; i < 4; i++) {
			int vx = x.first + dx[i];
			int vy = x.second + dy[i];
			if (vx < 0 || vy < 0 || vx >= n || vy >= m) continue;
			else {
				if (!checked[vx][vy]) {
					checked[vx][vy] = true;
					if (maze[x.first][x.second] == 1 && maze[vx][vy] == 1) {
						q.push(make_pair(vx, vy));
						parent[vx][vy] = min(parent[vx][vy], parent[x.first][x.second] + 1);
					}
				}
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			maze[i][j] = s[j] - 48;
			parent[i][j] = 999999;
		}
	}
	parent[0][0] = 1;
	checked[0][0] = true;
	q.push(make_pair(0, 0));
	bfs();
	cout << parent[n-1][m-1];
	return 0;
}