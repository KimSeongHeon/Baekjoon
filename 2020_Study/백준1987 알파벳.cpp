#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
char board[21][21];
int row, col;
int answer = -987654321;
vector<char> comb;
void cal(int x,int y) {
	for (int i = 0; i < comb.size(); i++) {
		if (comb[i] == board[x][y]) return;
	}
	if (x < 0 || y < 0 || x>=row || y>=col) return;
	comb.push_back(board[x][y]);
	answer = max(answer,(int)comb.size());
	for (int i = 0; i < 4; i++) {
		cal(x + dx[i], y + dy[i]);
	}
	comb.pop_back();
}
int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			board[i][j] = (char)s[j];
		}
	}
	cal(0, 0);
	cout << answer;
	return 0;
}