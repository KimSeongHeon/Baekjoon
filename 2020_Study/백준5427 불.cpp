#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int visited[1002][1002];
char map[1002][1002];
int main() {
		memset(visited, -1, sizeof(visited));
		memset(map, 0, sizeof(map));
		int ans = -1;
		int row, col;
		cin >> row >> col;
		pair<int, int> start;
		vector<pair<int, int>> fire;
		for (int i = 1; i <= row; i++) {
			string str;
			cin >> str;
			for (int j = 1; j <= col; j++) {
				map[i][j] = str[j-1];
				if (str[j-1] == 'J') start = { i,j };
				if (str[j-1] == 'F') fire.push_back({ i,j });
			}
		}
		queue<pair<int,int>> q1;
		queue<pair<int,int>> q2;
		q1.push(start);
		visited[start.first][start.second] = 0;
		for (int i = 0; i < fire.size(); i++) {
			q2.push(fire[i]);
		}
		int prev = -1;
		while (!q1.empty()) {
			pair<int, int> temp = q1.front(); q1.pop();
			int x = temp.first;
			int y = temp.second;
			if (x <= 0 || x > row || y <= 0 || y > col) {
				ans = visited[x][y];
				break;
			}
			if (prev != visited[x][y]) {
				vector<pair<int, int>> a;
				prev = visited[x][y];
				while (!q2.empty()) {
					pair<int, int> temp = q2.front(); q2.pop();
					a.push_back(temp);
				}
				for (int i = 0; i < a.size(); i++) {
					int x = a[i].first;
					int y = a[i].second;
					for (int j = 0; j < 4; j++) {
						int next_x = x + dx[j];
						int next_y = y + dy[j];
						if (next_x >= 1 && next_x <= row && next_y >= 1 && next_y <= col) {
							if (map[next_x][next_y] == '.' || map[next_x][next_y] == 'J') {
								q2.push({ next_x,next_y });
								map[next_x][next_y] = 'F';
							}
						}
						
					}
				}
			}
			for (int i = 0; i < 4; i++) {
				int next_x = temp.first + dx[i];
				int next_y = temp.second + dy[i];
				if (map[next_x][next_y] == '.' || map[next_x][next_y] == 0) {
					if (visited[next_x][next_y] == -1) {
						q1.push({ next_x,next_y });
						visited[next_x][next_y] = visited[x][y] + 1;
					}
				}
			}
		}
		if (ans == -1) cout << "IMPOSSIBLE" << endl;
		else cout << ans << endl;

	return 0;
}