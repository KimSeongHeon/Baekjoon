#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
int N, M;
int map[101];
int depth[101];
bool visited[101];
queue<int> q;
void bfs() {
	while (!q.empty()) {
		int x = q.front(); q.pop();
		if (x == 100) return;
		if (map[x] != -1) {
			depth[map[x]] = depth[x];
			x = map[x];
			visited[x] = true;
		}
		for (int i = 1; i <= 6; i++) {
			if (x + i <= 100) {
				if (!visited[x + i]) {
					q.push(x + i);
					visited[x + i] = true;
					depth[x + i] = depth[x] + 1;
				}
			}
		}
	}
	
}
int main() {
	memset(map, -1, sizeof(map));
	memset(depth, 0, sizeof(depth));
	memset(visited, false, sizeof(visited));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		map[start] = end;
	}
	for (int j = 0; j < M; j++) {
		int start, end;
		cin >> start >> end;
		map[start] = end;
	}
	q.push(1);
	visited[1] = true;
	bfs();
	cout << depth[100];
}