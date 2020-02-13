#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int ability[21][21];
vector<int> team1;
vector<int> team2;
int num;
int answer = 987654321;

void cal(int n) {
	if (n >= num || n < 0) return;
	if (team1.size() >= num / 2) return;
	team1.push_back(n);
	for (int i = 1; i < num; i++) {
		cal(n + i);
	}
	if (team1.size() == num / 2) {
		int temp1 = 0;
		int temp2 = 0;
		for (int i = 0; i < num; i++) {
			bool check = false;
			for (int j = 0; j < team1.size(); j++) {
				if (i == team1[j]) {
					check = true;
					break;
				}
			}
			if (!check) team2.push_back(i);
		}
		for (int i = 0; i < team1.size(); i++) {
			for (int j = i; j < team1.size(); j++) {
				temp1 = temp1 + ability[team1[i]][team1[j]];
				temp1 = temp1 + ability[team1[j]][team1[i]];
				temp2 = temp2 + ability[team2[i]][team2[j]];
				temp2 = temp2 + ability[team2[j]][team2[i]];
			}
		}
		answer = min(answer, abs(temp1 - temp2));
		team2.clear();
	}
	team1.pop_back();
}
int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> ability[i][j];
		}
	}
	for (int i = 0; i < num; i++) {
		cal(i);
	}
	cout << answer;
	return 0;
}