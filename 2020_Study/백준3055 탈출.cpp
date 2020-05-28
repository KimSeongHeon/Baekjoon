#include<iostream>
#include<algorithm>
#include<memory.h>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
char map[51][51];
int n, m;
queue<pair<int, int>> run_q;
queue<pair<int, int>> flow_q;
pair<int, int> start;
pair<int, int> des;
vector<pair<int, int>> flow;
int run_depth[51][51];
int flow_depth[51][51];
void map_bfs() {
	for (int i = 0; i < flow.size(); i++) {
		flow_q.push(make_pair(flow[i].first,flow[i].second));
		flow_depth[flow[i].first][flow[i].second] = 0;
	}
	while (!flow_q.empty()) {
		pair<int, int> temp = flow_q.front(); flow_q.pop();
		int x = temp.first;
		int y = temp.second;
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
				if (map[next_x][next_y] == '.' && flow_depth[next_x][next_y] == -1) {
					flow_q.push(make_pair(next_x,next_y));
					flow_depth[next_x][next_y] = flow_depth[x][y] + 1;
				}
			}
		}
	}
}
void bfs() {
	run_q.push(start);
	run_depth[start.first][start.second] = 0;
	while (!run_q.empty()) {
		pair<int, int> temp = run_q.front(); run_q.pop();
		int x = temp.first;
		int y = temp.second;
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
				if ((map[next_x][next_y] == '.') && run_depth[next_x][next_y] == -1) {
					//지금 가려고 하는 데가 홍수로 차있지 않으면
					//flow_depth가 1이다 = 하룻밤 지나고 찼다
					//flow_depth가 2이다 = 둘쩃밤 지나고 찼다.
					if (flow_depth[next_x][next_y] > run_depth[x][y]+1 || flow_depth[next_x][next_y] == -1) {
						run_q.push(make_pair(next_x, next_y));
						run_depth[next_x][next_y] = run_depth[x][y] + 1;
					}
				}
			}
		}
	}

}
int main() {
	memset(flow_depth, -1, sizeof(flow_depth));
	memset(run_depth, -1, sizeof(flow_depth));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'S') start = make_pair(i, j);
			else if (map[i][j] == 'D') des = make_pair(i, j);
			else if (map[i][j] == '*') flow.push_back(make_pair(i, j));
		}
	}
	map_bfs();
	bfs();
	int x = des.first;
	int y = des.second;
	int ans = 987654321;
	bool find = false;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
			if (run_depth[next_x][next_y] != -1) {
				find = true;
				ans = min(ans, run_depth[next_x][next_y]);
			}
		}
	}
	if (find) cout << ans+1;
	else cout << "KAKTUS";
	return 0;
}