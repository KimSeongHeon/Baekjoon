#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
int map[101][101];
int group[101][101];
int group_count = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main(){
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < num; j++) {
			map[i][j] = s[j];
		}
	}
	memset(group, -1, sizeof(group));
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (group[i][j] != -1) continue;
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			group[i][j] = group_count;
			while (!q.empty()) {
				pair<int, int> p = q.front(); q.pop();
				int x = p.first;
				int y = p.second;
				for (int i = 0; i < 4; i++) {
					int next_x = x + dx[i];
					int next_y = y + dy[i];
					if (next_x >= 0 && next_x < num && next_y >= 0 && next_y < num) {
						if (map[next_x][next_y] == map[x][y] && group[next_x][next_y] == -1) {
							q.push(make_pair(next_x, next_y));
							group[next_x][next_y] = group[x][y];
						}
					}
				}
			}
			group_count++;
		}
	}
	cout << group_count << " ";
	memset(group, -1, sizeof(group));
	group_count = 0;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (group[i][j] != -1) continue;
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			group[i][j] = group_count;
			while (!q.empty()) {
				pair<int, int> p = q.front(); q.pop();
				int x = p.first;
				int y = p.second;
				for (int i = 0; i < 4; i++) {
					int next_x = x + dx[i];
					int next_y = y + dy[i];
					if (next_x >= 0 && next_x < num && next_y >= 0 && next_y < num) {
						if (map[x][y] == 'R' || map[x][y] == 'G') {
							if ((map[next_x][next_y] == 'R' || map[next_x][next_y] == 'G') &&
								group[next_x][next_y] == -1) {
								q.push(make_pair(next_x, next_y));
								group[next_x][next_y] = group[x][y];
							}
						}
						else {
							if (map[next_x][next_y] == map[x][y] && group[next_x][next_y] == -1) {
								q.push(make_pair(next_x, next_y));
								group[next_x][next_y] = group[x][y];
							}
						}
						
					}
				}
			}
			group_count++;
		}
	}
	cout << group_count;
	return 0;
}