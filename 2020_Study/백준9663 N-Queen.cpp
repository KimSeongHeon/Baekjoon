#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int answer = 0;
bool check_col[40];
bool check_dig[40];
bool check_dig2[40];
bool a[16][16];
bool check(int row, int col) { //걸리는지 검사하는 함수
	if (check_col[col]) return false;
	if (check_dig[row + col]) return false;
	if (check_dig2[row - col + N]) return false;
	return true;
}

void cal(int row) {
	if (row == N) {
		answer++;
	}
	for (int col = 0; col < N; col++) {
		if (check(row, col)) {
			check_col[col] = true;
			check_dig[row + col] = true;
			check_dig2[row - col + N] = true;
			a[row][col] = true;
			cal(row + 1);
			a[row][col] = false;
			check_col[col] = false;
			check_dig[row + col] = false;
			check_dig2[row - col + N] = false;
		}
		
	}
}
int main() {
	cin >> N;
	cal(0);
	cout << answer;
	return 0;
}