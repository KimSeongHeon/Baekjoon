#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<memory.h>
using namespace std;
int T;
bool visited[10001];
string depth[10001];
void bfs(string start, string end,queue<int> q) {
	while (!q.empty()) {
		int x = q.front(); q.pop();
		//cout << x << endl;
		if (x < 0 || x>10000) continue;
		if (x == atoi(end.c_str())) return;
		//D
		if (!visited[(2 * x)%10000]) {
			visited[(2 * x)%10000] = true;
			depth[(2 * x)%10000] = depth[x] + "D";
			q.push((2 * x)%10000);
		}
		//S
		if (x == 0) {
			if (!visited[9999]) {
				visited[9999] = true;
				depth[9999] = depth[x] + "S";
				q.push(9999);
			}
		}
		else {
			if (!visited[x-1]) {
				visited[x - 1] = true;
				depth[x - 1] = depth[x] + "S";
				q.push(x - 1);
			}
		}
		//L
		int first, second, third, fourth;
		if (x / 10 == 0) {
			first = 0; second = 0;
			third = 0; fourth = x;
		}
		else if (x / 100 == 0) {
			first = 0; second = 0;
			third = x / 10; fourth = x % 10;
		}
		else if (x / 1000 == 0) {
			first = 0; second = x / 100;
			third = (x % 100)/10; fourth = (x % 100) % 10;
		}
		else {
			first = x / 1000; second = (x % 1000) / 100;
			third = ((x % 1000) % 100) / 10; fourth = ((x % 1000) % 100) % 10;
		}
		int next_s = second*1000 + third*100 + fourth *10 + first;
		if (!visited[next_s]) {
			visited[next_s] = true;
			depth[next_s] = depth[x] + "L";
			q.push(next_s);
		}
		//R
		next_s = fourth * 1000 + first * 100 + second * 10 + third;
		if (!visited[next_s]) {
			visited[next_s] = true;
			depth[next_s] = depth[x] + "R";
			q.push(next_s);
		}
	}
}
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 10000; i++) {
			depth[i] = "";
		}
		queue<int> q;
		string start, end;
		cin >> start >> end;
		int i_start = atoi(start.c_str());
		int i_end = atoi(end.c_str());
		if (i_start/ 10 == 0) {
			start = "000" + start;
		}
		q.push(i_start);
		visited[i_start] = true;
		depth[i_start] = "";
		bfs(start, end,q);
		cout << depth[i_end] << endl;
	}
	return 0;
}