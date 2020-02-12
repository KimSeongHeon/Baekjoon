#include<iostream>
#include<vector>
#include<memory.h>
#include<string>
#include<algorithm>
using namespace std;

int n;
int square[30][30];
bool checked[30][30];
int answer[20000];
int dx[4] = { 0,1 ,-1 ,0 };
int dy[4] = { 1,0 ,0, -1 };
int a_index = 0;
int last_x = 0;
int last_y = 0;

void dfs(int x, int y) {//x,y 에서 1인 지점을 따라가는 dfs
	if (x < 0 || y < 0 || x >= n || y >= n) {
		return;
	}
	cout << "dfs" << x << " " << y << endl;
	last_x = x;
	last_y = y;
	checked[x][y] = true;
	answer[a_index]++;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= n || y + dy[i] >= n) {
			continue;
		}
		else {
			if (!checked[x + dx[i]][y + dy[i]]) {
				if (square[x][y] == 1 && square[x + dx[i]][y + dy[i]] == 1) {
					dfs(x + dx[i], y + dy[i]);
				}
			}
		}
	}
	return;
}

int search(int x, int y) { //완전 탐색
	checked[x][y] = true;
	if (x >= n || y >= n || x < 0 || y < 0) {
		return 0;
	}
	if (square[x][y] == 1) {
		dfs(x, y);
		a_index++;
		x = last_x;
		y = last_y;
	}
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= n || y + dy[i] >= n) {
			continue;
		}
		else {
			if (!checked[x + dx[i]][y + dy[i]]) {
				search(x + dx[i], y + dy[i]);
			}
		}
	}
	return 0;

}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &square[i][j]);
		}
	}
	search(0, 0);
	cout << a_index << endl;
	sort(answer, answer + a_index);
	for (int i = 0; i < a_index; i++) {
		 cout << answer[i] << endl;

	}

	return 0;
}