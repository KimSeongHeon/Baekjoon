#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<memory.h>
using namespace std;
char board[51][51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool checked[51][51];
int init_x, init_y;
int n, m;
int num = 0;
bool answer = false;

vector<pair<int, int>> stack;
void dfs(int x, int y) {
	//cout << "x " << x << " y " << y;
	//cout << " init_x" << init_x << " init_y " << init_y << " num" << num <<endl;
	bool check = false;
	checked[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int vx = x + dx[i];
		int vy = y + dy[i];
		if (vx < 0 || vy < 0 || vx >= n || vy >= m) continue;
		if (vx == init_x && vy == init_y) {
			if (num >= 4) answer = true;
		}
		if (!checked[vx][vy] && board[x][y] == board[vx][vy]) {
			num++;
			dfs(vx, vy);
			check = true;
		}
	}
	if (!check) num = 1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			num = 1;
			memset(checked, false, sizeof(checked));
			init_x = i;
			init_y = j;
			dfs(i, j);
			if (answer) {
				cout << "Yes";
				return 0;
			}			
		}
	}
	cout << "No";
	return 0;
}