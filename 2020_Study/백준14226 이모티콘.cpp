#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n;
bool checked[1001];
int depth[1001][1001]; //n까지 왔을 때, 클리
queue<pair<int,int>> q;
void bfs() {
	q.push(make_pair(1,0)); depth[1][0] = 0;
	while (!q.empty()) {
		pair<int,int> x = q.front(); q.pop();
		if (depth[x.first][x.first] == -1) { //복사
			depth[x.first][x.first] = depth[x.first][x.second] + 1;
			q.push(make_pair(x.first,x.first));
		}
		if (x.first + x.second <= n && depth[x.first + x.second][x.second] == -1)//붙여넣기
		{
			depth[x.first + x.second][x.second] = depth[x.first][x.second] + 1;
			q.push(make_pair(x.first + x.second, x.second));
		}
		if (x.first - 1 >= 0 && depth[x.first - 1][x.second] == -1) {
			depth[x.first - 1][x.second] = depth[x.first][x.second] + 1;
			q.push(make_pair(x.first - 1, x.second));
		}
		
	}
}

int main() {
	memset(depth, -1, sizeof(depth));
	cin >> n;
	bfs();
	int mini = 987654321;
	for (int i = 1; i < n; i++) {
		mini = min(mini, depth[n][i]);
	}
	cout << mini;
	return 0;
}