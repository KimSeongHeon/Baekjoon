#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int n, m;
int paper[501][501];
vector<pair<int, int>> comb;
int answer = -987654321;
int ghcnf = 0;
//폴리오미노 구하기
void cal(pair<int, int> p) {
	if (comb.size() >= 1) {
		if (abs(comb.back().first - p.first) >= 2 || abs(comb.back().second - p.second) >= 2) return;
	}
	if (p.first < 0 || p.second < 0 || p.first >= n || p.second >= m) return;
	for (int i = 0; i < comb.size(); i++)
		if (comb[i] == p) return;
	if (comb.size() > 4) return;
	comb.push_back(p);
	cal(make_pair(p.first + 1, p.second));
	cal(make_pair(p.first - 1, p.second));
	cal(make_pair(p.first, p.second+1));
	cal(make_pair(p.first, p.second-1));
	if (comb.size() == 4) {
		int temp = 0;
		for (int i = 0; i < 4; i++) {
			//cout << comb[i].first << " " << comb[i].second << "\t";
			temp = temp + paper[comb[i].first][comb[i].second];
		}
		answer = max(answer, temp);
	}
	comb.pop_back();
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cal(make_pair(i, j));
		}
	}
	int ex_max = -987654321;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp = 0, temp1 = 0, temp2 = 0, temp3 = 0;
			if(j+2<m && i+1<n) temp = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i+1][j+1];
			if(i+2<n && j+1<m) temp1 = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 1][j + 1];
			if (j+2<m && i-1>=0) temp2 = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i - 1][j + 1];
			if (j-1>=0 && i+2<n) temp3 = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 1][j - 1];
			//cout << i << " " << j << " 일 때 : ";
			//cout << "temp2 : " << temp2 << endl;
			ex_max = max(ex_max,max(temp, max(temp1, max(temp2, temp3))));
		}
	}
	cout << max(ex_max, answer);
	return 0;
}