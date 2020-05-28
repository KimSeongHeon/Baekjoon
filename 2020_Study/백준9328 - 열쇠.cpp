#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int row, col;
		int visited[101][101];
		set<char> have;
		set<pair<int, int>> ans;
		vector<pair<int, int>> start;
		cin >> row >> col;
		char map[101][101];
		for (int i = 0; i < row; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < col; j++) {
				map[i][j] = str[j];
				if ((i == 0 || j == 0 || i == row-1 || j == col-1)) {
					start.push_back({ i,j });
				}
			}
		}
		string str;
		cin >> str;
		if (str != "0") {
			for (int i = 0; i < str.length(); i++) have.insert(str[i]);
		}
		int pre = -1;
		while (have.size() != pre) {
			pre = have.size();
			queue<pair<int, int>> q;
			memset(visited, -1, sizeof(visited));
			for (int i = 0; i < start.size(); i++) {
				int x = start[i].first;
				int y = start[i].second;
				if (map[x][y] == '.' || (map[x][y] >= 'a' && map[x][y]<='z')) {
					//cout << x << " " << y << endl;
					q.push(start[i]);
					visited[start[i].first][start[i].second] = 0;
				}
				else if (map[x][y] >= 'A' && map[x][y] <= 'Z') {
					if (have.find(map[x][y] + 32) != have.end()) {
						//cout << x << " " << y << endl;
						q.push({ x,y });
						visited[x][y] = 0;
					}
				}
				else if (map[x][y] == '$') {
					ans.insert(start[i]);
					q.push(start[i]);
					visited[start[i].first][start[i].second] = 0;
				}
				
			}
			while (!q.empty()) {
				pair<int, int> temp = q.front(); q.pop();
				int x = temp.first;
				int y = temp.second;
				for (int i = 0; i < 4; i++) {
					int next_x = x + dx[i];
					int next_y = y + dy[i];
					if (next_x < row && next_x >= 0 && next_y < col && next_y >= 0) {
						if (visited[next_x][next_y] == -1) {
							if (map[next_x][next_y] >= 'A' && map[next_x][next_y] <= 'Z') {
								if (have.find(map[next_x][next_y] + 32) != have.end()) {
									q.push({ next_x,next_y });
									visited[next_x][next_y] = visited[x][y] + 1;
								}
							}
							else if (map[next_x][next_y] >= 'a' && map[next_x][next_y] <= 'z') {
								q.push({ next_x,next_y });
								visited[next_x][next_y] = visited[x][y] + 1;
								have.insert(map[next_x][next_y]);
							}
							else if (map[next_x][next_y] == '.') {
								q.push({ next_x,next_y });
								visited[next_x][next_y] = visited[x][y] + 1;
							}
							else if (map[next_x][next_y] == '$') {
								ans.insert({ next_x,next_y });
								q.push({ next_x,next_y });
								visited[next_x][next_y] = visited[x][y] + 1;
							}
						}
					}
				}

			}
		}
		cout << ans.size() << endl;
	}
	return 0;
}