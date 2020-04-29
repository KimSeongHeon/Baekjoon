#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>
using namespace std;
bool visited[12][6];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
char map[12][6];
vector<pair<int, int>> rm;
int ans;
void dfs(int x,int y,char c) {
	rm.push_back({ x,y });
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6) {
			if (!visited[nx][ny]) {
				if (map[nx][ny] == c) {
					dfs(nx, ny, c);
				}
			}
		}
		
	}
}
int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}
	int cnt = 0;
	while (1) {
		//cout << cnt++ << endl;
		memset(visited, false, sizeof(visited));
		vector<pair<int, int>> total;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] == '.') continue;
				else {
					dfs(i, j, map[i][j]);
					if (rm.size() >= 4) {
						for (int k = 0; k < rm.size(); k++) {
							total.push_back(rm[k]);
						}
					}
					rm.clear();
				}
			}
		}
		if (total.size() >= 4) {
			ans++;
			int down[6] = { 0,0,0,0,0,0 };
			for (int k = 0; k < total.size(); k++) {
				down[total[k].second]++;
				map[total[k].first][total[k].second] = '.';
			}
			/*for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 6; j++) {
					cout << map[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;*/
			char c_map[12][6];
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 6; j++) {
					c_map[i][j] = map[i][j];
				}
			}
			for (int col = 0; col < 6; col++) {
				for (int row = 11; row >= 0; row--) {
					for (int k = 11; k >= row; k--) {
						if (map[k][col] == '.') {
							map[row][col] = '.';
							map[k][col] = c_map[row][col];
							break;
						}
					}
				}
			}
			/*for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 6; j++) {
					cout << map[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;*/
		}
		else break;
		total.clear();
	}
	
	cout << ans;
	return 0;
}