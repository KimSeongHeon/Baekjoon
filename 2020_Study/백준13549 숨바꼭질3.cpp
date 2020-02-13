#include<iostream>
#include<algorithm>
#include<deque>
#include<memory.h>
using namespace std;

int n, m;
int depth[200001];
deque<int> q;
void bfs() {
	q.push_front(n); depth[n] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop_front();
		//cout << x << endl;
		int i = 2*x;
		if (2 * x <= 100000 && 2 * x > 0) {
			for (i = 2 * x; i <= 100000; i = i * 2) {
				if (depth[i] == -1) {
					depth[i] = depth[x];
					q.push_front(i);
				}
			}
			if (depth[i] == -1) {
				q.push_front(i);
				depth[i] = depth[x];

			}
		}
		
		if (x + 1 > 0 && x + 1 <= 100000) {
			if (depth[x + 1] == -1) {
				depth[x + 1] = depth[x] + 1;
				q.push_back(x + 1);
			}
		}
		if (x - 1 > 0 && x - 1 <= 100000) {
			if (depth[x - 1] == -1) {
				depth[x - 1] = depth[x] + 1;
				q.push_back(x - 1);
			}
		}

	}
}

int main()
{
	memset(depth, -1, sizeof(depth));
	cin >> n >> m;
	bfs();
	cout << depth[m];
}