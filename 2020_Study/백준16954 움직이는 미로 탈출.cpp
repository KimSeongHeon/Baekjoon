#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int dx[9] = {0,0,0,1,1,1,-1,-1,-1};
int dy[9] = { 0,1,-1,0,1,-1,0,1,-1 };
char map[8][8];
bool visited[8][8];
int depth[8][8];
vector<pair<int, int>> wall;
queue<pair<int, int>> q;
bool answer = false;
void map_down() {
	for (int i = 0; i < wall.size(); i++) {
		if (wall[i].first <= 6) {
			map[wall[i].first][wall[i].second] = '.';
			wall[i] = make_pair(wall[i].first + 1, wall[i].second);
			map[wall[i].first][wall[i].second] = '#';
		}
		else if (wall[i].first == 7) {
			map[wall[i].first][wall[i].second] = '.';
			wall[i] = make_pair(wall[i].first + 1, wall[i].second);
		}
	}
}
void bfs(){
	int pre_depth = 0;
	while (!q.empty()) {
		pair<int, int> x = q.front(); q.pop();
		cout << x.first << " " << x.second << endl;
		if(pre_depth != depth[x.first][x.second]) map_down();
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cout << map[i][j];
			}
			cout << endl;
		}
		if (x == make_pair(0, 7)) {
			answer = true;
			return;
		}
		bool check = false;
		for (int i = 0; i < wall.size(); i++) {
			if (wall[i] == x) {
				check = true;
			}
		}
		if (check) continue;
		for (int i = 0; i < 8; i++) {
			int next_x = x.first + dx[i];
			int next_y = x.second + dy[i];
			if (next_x >= 0 && next_x <= 7 && next_y >= 0 && next_y <= 7) {
				if (map[next_x][next_y] == '.' && !visited[next_x][next_y]) {
					q.push(make_pair(next_x, next_y));
					depth[next_x][next_y] = depth[x.first][x.second] + 1;
					visited[next_x][next_y] = true;
				}
			}	
		}
		pre_depth = depth[x.first][x.second];
	}
}
int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') wall.push_back(make_pair(i, j));
		}
	}
	visited[7][0] = true;
	q.push(make_pair(7, 0));
	depth[7][0] = 0;
	bfs();
	cout << answer;
	return 0;
}