#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int answer = 0;
vector<pair<int, int>> comb;
bool check(int count, int x, int y) { //걸리는지 검사하는 함수
	for (int i = 0; i < comb.size(); i++) {
		for (int j = comb[i].first; j < N; j++) {
			if (x == j && y == comb[i].second) return false;
		}//x축 ++ 검사
		for (int j = comb[i].first; j >= 0; j--) {
			if (x == j && y == comb[i].second) return false;
		}//x축 -- 검사
		for (int j = comb[i].second; j < N; j++) {
			if (x == comb[i].first && y == j) return false;
		}//y축 ++ 검사
		for (int j = comb[i].second; j >= 0; j--) {
			if (x == comb[i].first && y == j) return false;
		}//y축 -- 검사
		int index = 0;
		while (1) {
			if (comb[i].first + index >= N || comb[i].second + index >= N ||
				comb[i].second + index < 0 || comb[i].second + index < 0) break;
			if (comb[i].first + index == x && comb[i].second + index == y) return false;
			index++;
		}
		index = 0;
		while (1) {
			if (comb[i].first + index >= N || comb[i].second + index >= N ||
				comb[i].second + index < 0 || comb[i].second + index < 0) break;
			if (comb[i].first + index == x && comb[i].second - index == y) return false;
			index++;
		}
		index = 0;
		while (1) {
			if (comb[i].first + index >= N || comb[i].second + index >= N ||
				comb[i].second + index < 0 || comb[i].second + index < 0) break;
			if (comb[i].first - index == x && comb[i].second + index == y) return false;
			index++;
		}
		index = 0;
		while (1) {
			if (comb[i].first + index >= N || comb[i].second + index >= N ||
				comb[i].second + index < 0 || comb[i].second + index < 0) break;
			if (comb[i].first - index == x && comb[i].second - index == y) return false;
			index++;
		}
	}
	return true;
}
void cal(int x, int y,int count) {
	for (int i = 0; i < comb.size(); i++) {
		if (comb[i] == make_pair(x, y)) return;
	}
	if (x < 0 || y < 0 || x >= N || y >= N) return;
	comb.push_back(make_pair(x, y));
	for (int i = x; i < N; i++) {
		for (int j = y; j < N; j++) {
			if (check(count, i, j)) {
				cal(i, j, count + 1);
			}
		}
	}
	if (comb.size() == N) {
		for (int i = 0; i < comb.size(); i++) {
			//cout << comb[i].first << " " << comb[i].second << " " << "\t";
		}
		answer++;
		//cout << endl;
	}
	comb.pop_back();
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cal(i, j, 0);
		}
	}
	cout << answer;
	return 0;
}