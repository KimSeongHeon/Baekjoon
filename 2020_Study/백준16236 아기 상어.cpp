#include<iostream>
#include<queue>
#include<algorithm>
#include<memory.h>
#include<vector>
using namespace std;
int n;
int map[21][21];
int depth[21][21];//x,y,size,eat
pair<int, int> start;
int shark = 2;
int eat = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int ans = 0;
int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) start = make_pair(i, j);
		}
	}
	while (1){
		memset(depth, -1, sizeof(depth));
		queue<pair<int, int>> q;
		q.push(start);
		depth[start.first][start.second] = 0;
		map[start.first][start.second] = 0;
		vector <pair<int, int>> target;
		while (!q.empty()) {
			pair<int, int> temp = q.front(); q.pop();
			int x = temp.first;
			int y = temp.second;
			if (map[x][y] > 0 && map[x][y] < shark) target.push_back(make_pair(x, y));
			for (int i = 0; i < 4; i++) {
				int next_x = x + dx[i];
				int next_y = y + dy[i];
				if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
					if (depth[next_x][next_y] == -1 && map[next_x][next_y] <= shark) {
						q.push(make_pair(next_x, next_y));
						depth[next_x][next_y] = depth[x][y] + 1;
					}
				}
			}
		}
		if (target.size() == 0) break;
		int temp = 987654321;
		for (int i = 0; i < target.size(); i++) {
			temp = min(temp, depth[target[i].first][target[i].second]);
		}
		pair<int, int> p = make_pair(987654321,987654321);
		for (int i = 0; i < target.size(); i++) {
			if (temp == depth[target[i].first][target[i].second]) {
				if (target[i].first < p.first) {
					p = target[i];
				}
				else if (target[i].first == p.first) {
					if (target[i].second < p.second) {
						p = target[i];
					}
				}
			}
		}
		eat++;
		if (eat == shark) {
			eat = 0;
			shark++;
		}
		ans = ans + depth[p.first][p.second];
		start = p;
		target.clear();
	}
	cout << ans;


}