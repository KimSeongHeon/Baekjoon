#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;

int group[20001];
vector<int> edge[20001];

void dfs(int x,int g) {
	//cout << "x :" << x << " g : " << g << endl;
	group[x] = g;
	for (int i = 0; i < edge[x].size(); i++) {
		if (group[edge[x][i]] == 0) {
			dfs(edge[x][i],3-g);
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int n, m;
		cin >> n >> m;
		memset(edge, 0, sizeof(edge));
		memset(group, 0, sizeof(group));
		for (int i = 1; i <= m; i++) {
			int v1, v2;
			cin >> v1 >> v2;
			edge[v1].push_back(v2);
			edge[v2].push_back(v1);
		}
		
		for (int i = 1; i <= n; i++) {
			if(group[i] == 0) dfs(i,1);
		}
		bool check = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < edge[i].size(); j++) {
				if (group[edge[i][j]] == group[i]) {
					check = false;
				}
			}
		}
		if (check) cout << "YES"<<endl;
		else cout << "NO"<<endl;
	}
	return 0;
}