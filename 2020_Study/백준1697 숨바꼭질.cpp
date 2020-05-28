#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>
#include<stack>
using namespace std;

int n, m;
bool checked[200002];//n에서 x까지 걸리는 시간
int depth[200002];
int parent[200002];
int answer;
queue<int> q;
void bfs(int n) {
	q.push(n); checked[n] = true;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		//cout << x << endl;
		if (x == m) return;
		if (x + 1 <= 100000 && x + 1 >= 0) {
			if (!checked[x + 1]) {
				q.push(x + 1);
				checked[x + 1] = true;
				depth[x + 1] = depth[x] + 1;
				parent[x + 1] = x;
			}
		}
		if (x - 1 <= 100000 && x - 1 >= 0) {
			if (!checked[x - 1]) {
				q.push(x - 1);
				checked[x - 1] = true;
				depth[x - 1] = depth[x] + 1;
				parent[x - 1] = x;
			}
		}
		if (2 * x <= 100000 && 2 * x >= 0) {
			if (!checked[2 * x]) {
				q.push(2 * x);
				checked[2 * x] = true;
				depth[2 * x] = depth[x] + 1;
				parent[2 * x] = x;
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	memset(parent, -1, sizeof(parent));
	depth[n] = 0;
	bfs(n);
	cout << depth[m] << endl;
	stack<int> st;
	int temp = m;
	while (temp != -1) {
		st.push(temp);
		temp = parent[temp];
	}
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}

}