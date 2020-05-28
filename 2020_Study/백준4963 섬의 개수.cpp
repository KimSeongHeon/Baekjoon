#include<iostream>
#include<vector>

using namespace std;
int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,0,1,-1,0,1,-1};
bool checked[51][51];
int land[51][51];

void dfs(int x,int y,int n,int m) {
	//cout << "dfs : " << x << " " << y << endl;
	checked[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int vx = x + dx[i];
		int vy = y + dy[i];
		if (vx < 0 || vy < 0 || vx >= m || vy >= n) continue;
		//cout << "vx : " << vx << "vy : " << vy <<" " << land[vx][vy] <<endl;
		if (!checked[vx][vy] && land[vx][vy] == 1) dfs(vx, vy,n,m);
	}


}

int main() {
	while (1) {
		int n, m;
		int answer = 0;
		cin >> n >> m;
		if (n == 0 && m == 0) return 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> land[i][j];
				checked[i][j] = false;
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!checked[i][j] && land[i][j]) {
					dfs(i,j,n,m);
					answer++;
				}
			}
		}
		cout << answer << endl;
	}
}