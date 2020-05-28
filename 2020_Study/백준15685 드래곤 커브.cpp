#include<iostream>
#include<vector>
#include<set>
using namespace std;
set<pair<int, int>> s;
int dest = 0;
void dfs(int x,int y,int d,int g) {
	cout << "ÀÔÀå";
	cout << x << " " << y << endl;
	if (g == dest+1) {
		return;
	}
	int prev = d;
	int next_x = x;
	int next_y = y;
	for (int i = 0; i <= g; i++) {
		if (prev == 0) next_x = next_x + 1;
		else if (prev == 1) next_y = next_y - 1;
		else if (prev == 2) next_x = next_x - 1;
		else if (prev == 3) next_y = next_y + 1;
		prev = (prev + 1) % 4;
		cout << next_x << " " << next_y << endl;
		s.insert({ next_x,next_y });
	}
	dfs(next_x, next_y, prev, g + 1);
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		dest = g;
		dfs(x, y, d, 0);
	}
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		//cout << (*iter).first << " " << (*iter).second << endl;
	}
}