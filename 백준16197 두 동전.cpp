#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
char board[21][21];
vector<pair<int, int>> start;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int answer = 987654321;
int n, m;
void move(pair<int,int> p,int count) {
	int one_x = start[0].first + p.first;
	int one_y = start[0].second + p.second;
	int two_x = start[1].first + p.first;
	int two_y = start[1].second + p.second;
	cout << one_x << " " << one_y << "\t" << two_x << " " << two_y << endl;
	if (board[one_x][one_y] != '#') start[0] = make_pair(one_x,one_y);
	if (board[two_x][two_y] != '#') start[1] = make_pair(two_x, two_y);
	if (((start[0].first >= n || start[0].second >= m) && (start[1].first >= n || start[1].second >= m))
		|| ((start[0].first < 0 || start[0].second <) && (start[1].first >= n || start[1].second >= m))) {
		return;
	}
	else if ((one_x >= n || one_y >= m) && (two_x < n && two_y < m)) {
		answer = min(answer, count);
		return;
	}
	else if ((two_x >= n || two_y >= m) && (one_x < n && one_y < m)) {
		answer = min(answer, count);
		return;
	}
	for (int i = 0; i < 4; i++) {
		move(make_pair(p.first + dx[i], p.second + dy[i]), count + 1);
	}
}
int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o') start.push_back(make_pair(i, j));
		}
	}
	move(make_pair(0, 0), 0);
	cout << answer;


}