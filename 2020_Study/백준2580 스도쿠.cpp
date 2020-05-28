#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int real_sdoku[9][9];
int sdoku[9][9];
int answer[9][9];
vector<pair<int,int>> v;
vector<int> solve;
bool find_answer = false;
void cal(int n,int value) {//n은 v의 index
	if (find_answer) return;
	if (solve.size() == v.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				answer[i][j] = sdoku[i][j];
			}
		}
		find_answer = true;
		return;
	}
	//가로 검사
	for (int i = v[n].first + 1; i < 9; i++) {
		if (value == sdoku[i][v[n].second]) return ;
	}
	for (int i = v[n].first - 1; i >= 0; i--) {
		if (value == sdoku[i][v[n].second]) return ;
	}
	//세로 검사
	for (int i = v[n].second + 1; i < 9; i++) {
		if (value == sdoku[v[n].first][i]) return ;
	}
	for (int i = v[n].second - 1; i >= 0; i--) {
		if (value == sdoku[v[n].first][i]) return ;
	}
	//9칸 검사
	for (int i = (v[n].first / 3) * 3; i < (v[n].first / 3) * 3 + 3; i++) {
		for (int j = (v[n].second / 3) * 3; j < (v[n].second / 3) * 3 + 3; j++) {
			if (value == sdoku[i][j]) return ;
		}
	}
	sdoku[v[n].first][v[n].second] = value;
	solve.push_back(n);
	for (int i = 1; i <= 9; i++) {
		cal(n + 1, i);
	}
	solve.pop_back();
	sdoku[v[n].first][v[n].second] = 0;
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> real_sdoku[i][j];
			if (real_sdoku[i][j] == 0) v.push_back(make_pair(i, j));
		}
	}
	for (int i = 1; i <= 9; i++) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				sdoku[i][j] = real_sdoku[i][j];
			}
		}
		cal(0, i);
	}
	cout << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}