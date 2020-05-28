#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int cube[7] = { -1,0,0,0,0,0,0 };
int dx[4] = { 0,0,-1,1 };
int dy[4] = {1,-1,0,0};
int main() {
	cin.tie(NULL);
	int map[21][21];
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int match[7] = { -1,6,5,4,3,2,1 };
	int left[7] = { -1,};
	int right[7] = { -1,4,4,2,5,4,4};
	int up[7] = {-1,2,6,6,1,1,5};
	int down[7] = {-1,5,1,1,6,6,3};
	int current = 1;
	for (int i = 0; i < k; i++) {
		int direction;
		cin >> direction;
		int nx = x + dx[direction-1];
		int ny = y + dy[direction-1];
		int next_cube[7] = {-1,};
		if (!(nx >= 0 && nx < n && ny >= 0 && ny < m)) continue;
		if (direction == 1) {
			next_cube[3] = cube[1];
			next_cube[1] = cube[4];
			next_cube[4] = cube[6];
			next_cube[6] = cube[3];
			next_cube[2] = cube[2];
			next_cube[5] = cube[5];
		}
		else if (direction == 2) {
			next_cube[1] = cube[3];
			next_cube[3] = cube[6];
			next_cube[6] = cube[4];
			next_cube[4] = cube[1];
			next_cube[2] = cube[2];
			next_cube[5] = cube[5];;
		}
		else if (direction == 3) {
			next_cube[1] = cube[5];
			next_cube[5] = cube[6];
			next_cube[6] = cube[2];
			next_cube[2] = cube[1];
			next_cube[3] = cube[3];
			next_cube[4] = cube[4];
		}
		else if (direction == 4) {
			next_cube[1] = cube[2];
			next_cube[2] = cube[6];
			next_cube[6] = cube[5];
			next_cube[5] = cube[1];
			next_cube[3] = cube[3];
			next_cube[4] = cube[4];
		}
		if (map[nx][ny] != 0) {
			next_cube[6] = map[nx][ny];
			map[nx][ny] = 0;
		}
		else map[nx][ny] = next_cube[6];
		cout << next_cube[1];
		for (int i = 0; i < 7; i++) {
			cube[i] = next_cube[i];
		}
		x = nx;
		y = ny;
		cout << endl;

	}
	return 0;
}