#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;

int n;
int island[101][101];
bool checked[101][101];
int dx[4] = { 0,0,1,-1};
int dy[4] = { 1,-1,0,0};
int num = 0;
int answer = 999999;
queue<pair<int,int>> q;
int depth[101][101];
void dfs(int x, int y) {
	checked[x][y] = true;
	island[x][y] = num;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n) continue;
		if (!checked[next_x][next_y]) {
			if (island[x][y] && island[next_x][next_y])
				dfs(next_x, next_y);
		}
	}

}
void bfs(int x, int y,int init) {
	checked[x][y] = true; q.push(make_pair(x, y));
	while (!q.empty()) {
		pair<int, int> front = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = front.first+ dx[i];
			int next_y = front.second + dy[i];
			if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n) continue;
			if (!checked[next_x][next_y]) {
				checked[next_x][next_y] = true;
				q.push(make_pair(next_x, next_y));
				depth[next_x][next_y] = depth[front.first][front.second] + 1;
				if (island[next_x][next_y] != 0 && init != island[next_x][next_y]) {
					//cout << x << "," << y << " ÀÏ ‹š ÃÖ¼Ú°ª : " << next_x << "," <<next_y << endl;
					answer = min(answer, depth[next_x][next_y]);
				}
			}
		}
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> island[i][j];
		}
	}
	for (int i = 0; i<n; i++) {
		for (int j = 0; j < n; j++) {
			if (!checked[i][j] && island[i][j] == 1) {
				num++;
				dfs(i, j);
			}
		}
	}
	//cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cout << island[i][j] << " ";
		}
		//cout << endl;
	}
	memset(checked, false, sizeof(checked));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			memset(checked, false, sizeof(checked));
			memset(depth, 0, sizeof(depth));
			if (island[i][j] != 0) {
				bfs(i, j, island[i][j]);
				//cout << "i : " << i << " j : " << j << " answer : " <<answer << endl;
			}
		}
	}
	cout << answer -1 ;
	return 0;
}