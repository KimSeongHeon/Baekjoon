#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int tomato[1001][1001];
bool checked[1001][1001];
int n, m;
queue<pair<int,int>> q;
int parent[1001][1001];

void bfs() {
	while (!q.empty()) {
		pair<int, int> x = q.front(); q.pop();
		for(int i = 0; i < 4; i++) {
			if (x.first + dx[i] < 0 || x.second + dy[i] < 0 || x.first + dx[i] >= m || x.second + dy[i] >= n) continue;
			else {
				if (!checked[x.first + dx[i]][x.second + dy[i]]) {
					checked[x.first + dx[i]][x.second + dy[i]] = true;
					if (tomato[x.first + dx[i]][x.second + dy[i]] == 0 && tomato[x.first][x.second] == 1) {
						tomato[x.first + dx[i]][x.second + dy[i]] = 1;
						parent[x.first + dx[i]][x.second + dy[i]] = parent[x.first][x.second] + 1;
						q.push(make_pair(x.first + dx[i], x.second + dy[i]));

					}
				}
			}
			
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push(make_pair(i, j));
				parent[i][j] = 0;
			}
		}
	}
	bfs();
	int answer = -1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			answer = max(answer, parent[i][j]);
			if (tomato[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << answer;

	return 0;
}