#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<vector>
#include<memory.h>
#include<set>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m;
queue<pair<int, int>> q;
vector<pair<int, int>> v;
int map[1001][1001];
int group[1001][1001];
int group_count = 0;
int each_element_count[1000001];
void bfs(int x,int y) {
	q.push(make_pair(x, y));
	group[x][y] = group_count;
	int element_count = 0;
	while (!q.empty()) {
		pair<int, int> ele = q.front(); q.pop();
		element_count++;
		for (int i = 0; i < 4; i++) {
			int next_x = ele.first + dx[i];
			int next_y = ele.second + dy[i];
			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
				if (group[next_x][next_y] == -1 && map[next_x][next_y] == 0) {
					q.push(make_pair(next_x, next_y));
					group[next_x][next_y] = group_count;
				}
			}
		}
	}
	each_element_count[group_count] = element_count;
	group_count++;
}
int main() {
	memset(group, -1, sizeof(group));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = (int)s[j] - 48;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (group[i][j] != -1 || map[i][j] ==1) continue;
			bfs(i, j);
		}
	}//그룹 지정
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) continue;
			set<int> temp;
			for (int k = 0; k < 4; k++) {
				int next_x = i + dx[k];
				int next_y = j + dy[k];
				if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
					if (map[next_x][next_y] == 0) {
						temp.insert(group[next_x][next_y]);
					}
				}
			}
			int value = 0;
			for (set<int>::iterator iter = temp.begin(); iter != temp.end(); iter++) {
				value = value + each_element_count[*iter];
			}
			map[i][j] = (value + 1) % 10;
		}
	}
	//cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	return 0;

}