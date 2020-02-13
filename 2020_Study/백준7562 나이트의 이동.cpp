#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int dx[8] = {2,2,1,1,-1,-1,-2,-2};
int dy[8] = {1,-1,2,-2,2,-2,1,-1};
int parent[301][301];
bool checked[301][301];
queue<pair<int, int>> q;

void bfs(int c_x, int c_y, int g_x, int g_y,int l) {
	while (!q.empty()) {
		pair<int, int> x = q.front(); q.pop();
		//cout << "bfs : " << x.first << " " << x.second << endl;
		for (int i = 0; i < 8; i++) {
			int vx = x.first + dx[i];
			int vy = x.second + dy[i];
			if (vx < 0 || vy < 0 || vx >= l || vy >= l) continue;
			if (!checked[vx][vy]) {
				checked[vx][vy] = true;
				q.push(make_pair(vx, vy));
				parent[vx][vy] = min(parent[vx][vy],parent[x.first][x.second]+1);
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int l;
		int current_x, current_y;
		int goal_x, goal_y;
		cin >> l;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				parent[i][j] = 999999;
				checked[i][j] = false;
			}
		}
		cin >> current_x >> current_y;
		parent[current_x][current_y] = 0;
		q.push(make_pair(current_x, current_y));
		cin >> goal_x >> goal_y;
		bfs(current_x, current_y, goal_x, goal_y,l);
		cout << parent[goal_x][goal_y] << endl;
	}

}