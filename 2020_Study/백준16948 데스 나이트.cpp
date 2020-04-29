#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>
using namespace std;
int N;
int chess[201][201];
bool visited[201][201];
int depth[201][201];
int start1, start2;
int end1, end2;
queue<pair<int, int>> q;
void bfs() {
	while (!q.empty()) {
		pair<int,int> x = q.front(); q.pop();
		if (x.first == end1 && x.second == end2) return;
		if (x.first >= N || x.second >= N || x.first < 0 || x.second < 0) continue;
		for (int i = -1; i <= 1; i++) {
			if (i != 0) {
				if (depth[x.first + 2 * i][x.second - 1] == -1) {
					depth[x.first + 2 * i][x.second - 1] = depth[x.first][x.second] + 1;
					q.push(make_pair(x.first + 2 * i, x.second - 1));
				}
				if (depth[x.first + 2 * i][x.second + 1] == -1) {
					depth[x.first + 2 * i][x.second + 1] = depth[x.first][x.second] + 1;
					q.push(make_pair(x.first + 2 * i, x.second + 1));
				}
			}
			else {
				if (depth[x.first + 2 * i][x.second - 2] == -1) {
					depth[x.first + 2 * i][x.second - 2] = depth[x.first][x.second] + 1;
					q.push(make_pair(x.first + 2 * i, x.second - 2));
				}
				if (depth[x.first + 2 * i][x.second + 2] == -1) {
					depth[x.first + 2 * i][x.second + 2] = depth[x.first][x.second] + 1;
					q.push(make_pair(x.first + 2 * i, x.second + 2));
				}
				
			}	
		}
	}
}
int main() {
	memset(depth, -1, sizeof(depth));
	cin >> N;
	cin >> start1 >> start2;
	cin >> end1 >> end2;
	q.push(make_pair(start1, start2));
	depth[start1][start2] = 0;
	bfs();
	cout << depth[end1][end2];
	return 0;
}