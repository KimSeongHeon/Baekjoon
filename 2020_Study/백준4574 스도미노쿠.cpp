#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<memory.h>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int sdoku[10][10]; // 스도쿠
vector<pair<int, int>> comb; // 다 된 수열을 넣음.
int n;
void cal(pair<int,int> seq,int spot_x,int spot_y) {
	for (int i = 0; i < comb.size(); i++) {
		if (seq == comb[i]) return;
	}
	if (comb.size() >= 36) return;
	for (int i = 0; i < 4; i++) {
		if (sdoku[spot_x + dx[i]][spot_y + dy[i]] == 0) {
			sdoku[spot_x][spot_y] = seq.first;
			sdoku[spot_x + dx[i]][spot_y + dy[i]] = seq.second;
			comb.push_back(seq);
			for (int i = 1; i <= 9; i++) {
				for (int j = i; j <= 9; j++) {
					for (int k = 0; k < 9; k++) {
						for (int l = 0; l < 9; l++) {
							if (sdoku[k][l] != 0) continue;
							else cal(make_pair(i, j), k, l);
						}
					}
				}
			}
			if (comb.size() == 36) {
				return;
			}// 답을 찾았을 때.
			sdoku[spot_x][spot_y] = 0;
			sdoku[spot_x + dx[i]][spot_y + dy[i]] = 0;
			comb.pop_back();
		}
	}
}
int main() {
	while (1) {
		memset(sdoku, false, sizeof(sdoku));
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			int element1,element2;
			string location1,location2;
			cin >> element1 >> location1;
			sdoku[(int)location1.at(0) - 65][(int)location1.at(1)-49] = element1;
			cin >> element2 >> location2;
			sdoku[(int)location2.at(0) - 65][(int)location2.at(1) - 49] = element2;
			comb.push_back(make_pair(element1, element2));
		}
		for (int i = 0; i < 9; i++) {
			string location;
			cin >> location;
			sdoku[(int)location.at(0) - 65][(int)location.at(1) - 49] = i+1;
		}
	}
	
}