#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n, m;
int matrix[51][51];
int goal[51][51];
int ans = 0;
void flip(int a,int b) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrix[a + i][b + j] == 0) {
				matrix[a + i][b + j] = 1;
			}
			else {
				matrix[a + i][b + j] = 0;
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			matrix[i][j] = (int)s[j] - 48;
		}
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			goal[i][j] = (int)s[j] - 48;
		}
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (matrix[i][j] !=  goal[i][j]) {
				ans = ans + 1;
				flip(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] != goal[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans;

	return 0;
}