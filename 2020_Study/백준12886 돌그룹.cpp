#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
queue<pair<int,int>> q;
int sum = 0;
vector<int> v;
bool visited[1500][1500];
bool bfs() {
	while (!q.empty()) {
		pair<int, int> x = q.front(); q.pop();
		int a = x.first;
		int b = x.second;
		int c = sum - a - b;
		if (a < 0 || b < 0 || c < 0) continue;
		if (a == b && b == c) return true;
		//a->b
		if (a > b) {
			if (!visited[a-b][b+b]) {
				q.push(make_pair(a - b, b + b));
				visited[a - b][b + b] = true;
			}
		}
		else if (a < b) {
			if (!visited[a + a][b - a]) {
				q.push(make_pair(a + a, b - a));
				visited[a + a][b - a] = true;
			}
		}
		//b->c
		if (b > c) {
			if (!visited[b - c][c + c]) {
				q.push(make_pair(b - c, c + c));
				visited[b - c][c + c] = true;
			}
		}
		else if (b < c) {
			if (!visited[b+b][c-b]) {
				q.push(make_pair(b + b, c - b));
				visited[b + b][c - b] = true;
			}
		}
		//c->a
		if (c > a) {
			if (!visited[c-a][a+a]) {
				q.push(make_pair(c - a, a + a));
				visited[c - a][a + a] = true;
			}
		}
		else if (c < a) {
			if (!visited[c + c][a - c]) {
				q.push(make_pair(c + c, a - c));
				visited[c + c][a - c] = true;
			}
		}
	}
	return false;
}
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	sum = a + b + c;
	q.push(make_pair(a, b));
	visited[a][b] = true;
	cout << bfs();

	
}