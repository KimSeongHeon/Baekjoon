#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int visited[22][22][22][22];
int row, col;
bool rangeout(int x, int y) {
	if (x > row || y > col || x < 1 || y < 1) return true;
	else return false;
}
struct coin {
	int x1;
	int y1;
	int x2;
	int y2;
};
int main() {
	char map[22][22];
	pair<int, int> start[2];
	cin >> row >> col;
	int index = 0;
	for (int i = 1; i <= row; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= col; j++) {
			map[i][j] = s[j-1];
			if (map[i][j] == 'o') {
				start[index++] = { i,j };
			}
		}
	}
	memset(visited, -1, sizeof(visited));
	queue<coin> q;
	q.push({ start[0].first,start[0].second,start[1].first,start[1].second });
	visited[start[0].first][start[0].second][start[1].first][start[1].second] = 0;
	while (!q.empty()) {
		coin temp = q.front(); q.pop();
		if (rangeout(temp.x1, temp.y1) && rangeout(temp.x2, temp.y2)) continue;
		else if (!rangeout(temp.x1, temp.y1) && rangeout(temp.x2, temp.y2)) {
			cout << visited[temp.x1][temp.y1][temp.x2][temp.y2] << endl;
			return 0;
		}
		else if (rangeout(temp.x1, temp.y1) && !rangeout(temp.x2, temp.y2)) {
			cout << visited[temp.x1][temp.y1][temp.x2][temp.y2] << endl;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int next_x1 = temp.x1 + dx[i];
			int next_y1 = temp.y1 + dy[i];
			int next_x2 = temp.x2 + dx[i];
			int next_y2 = temp.y2 + dy[i];
			if (map[next_x1][next_y1] == '#') {
				next_x1 = temp.x1;
				next_y1 = temp.y1;
			}
			if (map[next_x2][next_y2] == '#') {
				next_x2 = temp.x2;
				next_y2 = temp.y2;
			}
			if (visited[next_x1][next_y1][next_x2][next_y2] == -1) {
				q.push({ next_x1,next_y1,next_x2,next_y2 });
				visited[next_x1][next_y1][next_x2][next_y2] = visited[temp.x1][temp.y1][temp.x2][temp.y2] + 1;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}