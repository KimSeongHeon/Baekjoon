#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<memory.h>
using namespace std;
struct status {
	int remain;
	int current;
	bool operator<(const status& s) const {
		if (current == s.current) return remain<s.remain;
		return current < s.current;
	}
};
int visited[101][1<<15];
//map<status, int> visited;
map<int, int> match;
queue<status> q;
int main() {
	memset(visited, -1, sizeof(visited));
	int n, m, k;
	set<int> jewel_island;
	vector<int> map[101];
	int weight[101][101];
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int element;
		cin >> element;
		jewel_island.insert(element);
		match.insert({ element, i+1 });
	}
	for (int i = 0; i < m; i++) {
		int start, dest, w;
		cin >> start >> dest >> w;
		map[start].push_back(dest);
		map[dest].push_back(start);
		weight[start][dest] = w;
		weight[dest][start] = w;
	}
	if (jewel_island.find(1) != jewel_island.end()) {
		int temp = 0;
		temp = (temp | (1 << (match[1]-1)));
		status s = {temp,1};
		q.push(s);
		visited[1][temp] = 1;
	}
	status s = { 0,1 };
	q.push(s);		
	visited[1][0] = 0;
	int answer = 0;
	while (!q.empty()) {
		status s = q.front(); q.pop();
		int remain = s.remain;
		int current = s.current;
		if (current == 1) answer = max(answer, visited[current][remain]);
		for (int i = 0; i < map[current].size(); i++) {
			int nx = map[current][i];
			if (visited[current][remain] <= weight[current][nx]) {
				if (match.find(nx) != match.end()) {
					if ((remain & (1 << (match[nx] - 1))) != (1 << (match[nx] - 1))) {
						int temp = remain;
						temp = (temp | (1 << (match[nx] - 1)));
						status next_state = { temp,nx };
						if (visited[nx][temp] == -1) {
							q.push(next_state);
							visited[nx][temp] = visited[current][remain]+1;
						}
					}
				}
				status next_state = { remain,nx };
				if (visited[nx][remain] == -1) {
					q.push(next_state);
					visited[nx][remain] = visited[current][remain];
				}
			}
		}
	}
	cout << answer << endl;
	
	return 0;
}