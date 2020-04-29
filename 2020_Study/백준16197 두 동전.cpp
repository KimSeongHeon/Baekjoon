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
void move(pair<int,int> coin1,pair<int,int> coin2,int count) {
	if ((coin1.first > n || coin1.second > m) && (coin2.first > n || coin2.second > m)) return;
	if ((coin1.first < 0|| coin1.second < 0) && (coin2.first < 0 || coin2.second < 0)) return;
	//coin1만 밖으로 나감
	cout << coin1.first << " " << coin1.second << " " << coin2.first << " " << coin2.second << endl;
	if (coin2.first >= 0 && coin2.first < n && coin2.first >= 0 && coin2.second < m){
		if ((coin1.first < 0 || coin1.second < 0) || (coin1.first >= n || coin1.second >= m)) {
			answer = min(answer, count);
			return;
		}	
	}
	//coin2만 밖으로 나감
	if (coin1.first >= 0 && coin1.first < n && coin1.first >= 0 && coin1.second < m) {
		if ((coin2.first < 0 || coin2.second < 0) || (coin2.first >= n || coin2.second >= m)) {
			answer = min(answer, count);
			return;
		}
	}
	for (int i = 0; i < 4; i++) {
		if ((board[coin1.first + dx[i]][coin1.second + dy[i]] == '.' || board[coin1.first + dx[i]][coin1.second + dy[i]] == 'o')
			&& board[coin2.first + dx[i]][coin2.second + dy[i]] != '#') {
			move(make_pair(coin1.first + dx[i], coin1.second + dy[i]), make_pair(coin2.first + dx[i], coin2.second + dy[i]), count + 1);
		}
		else if (board[coin1.first + dx[i]][coin1.second + dy[i]] == '#' && 
			(board[coin1.first + dx[i]][coin1.second + dy[i]] == '.' || board[coin1.first + dx[i]][coin1.second + dy[i]] == 'o')) {
			move(make_pair(coin1.first, coin1.second), make_pair(coin2.first + dx[i], coin2.second + dy[i]), count + 1);
		}
		else if ((board[coin1.first + dx[i]][coin1.second + dy[i]] == '.' || board[coin1.first + dx[i]][coin1.second + dy[i]] == 'o')
			&& board[coin2.first + dx[i]][coin2.second + dy[i]] == '#') {
			move(make_pair(coin1.first + dx[i], coin1.second + dy[i]), make_pair(coin2.first, coin2.second), count + 1);
		}
		/*else if (board[coin1.first + dx[i]][coin1.second + dy[i]] == '#' && board[coin2.first + dx[i]][coin2.second + dy[i]] == '#') {
			move(make_pair(coin1.first, coin1.second), make_pair(coin2.first, coin2.second), count + 1);
		}*/	
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
	move(start[0],start[1], 0);
	cout << answer;


}