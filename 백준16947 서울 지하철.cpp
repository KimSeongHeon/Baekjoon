#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> edge[3001];
vector<int> cycle_node;
vector<int> temp;
bool iscycle[3001];
bool checked[3001];
int init_x;
int answer = 0;

void dfs_for_cycle(int x,int depth) { //사이클 찾기
	//cout << "dfs : " << x <<" depth :"<<depth <<endl;
	bool check = false;
	checked[x] = true;
	temp.push_back(x);
	for (int i = 0; i < edge[x].size(); i++) {
		if (depth > 1) {
			if (edge[x][i] == init_x) {
				temp.push_back(init_x);
				//cout << "answer : " << x << endl;
				for (int i = 0; i < temp.size(); i++) {
					cycle_node.push_back(temp[i]);
					iscycle[temp[i]] = true;
				}
				temp.clear();
			}
		}
	}
	for (int i = 0; i < edge[x].size(); i++) {
		if (!checked[edge[x][i]]) {
			check = true;
			dfs_for_cycle(edge[x][i], depth + 1);
		}
	}
	if (!check) temp.clear();
}

void dfs(int x,int depth) {
	checked[x] = true;
	for (int i = 0; i < cycle_node.size(); i++) {
		if (x == cycle_node[i]) answer = min(answer, depth);
	}
	for (int i = 0; i < edge[x].size(); i++) {
		if (!checked[edge[x][i]]) dfs(edge[x][i], depth + 1);
	}

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		edge[n1].push_back(n2);
		edge[n2].push_back(n1);
	}
	for (int i = 1; i <= n; i++) {
		//cout << "-------------------" << endl;
		memset(checked, false, sizeof(checked));
		init_x = i;
		temp.clear();
		if (!checked[i] && !iscycle[i]) dfs_for_cycle(i,0);
 	}
	/*for (int i = 1; i <= n; i++) {
		if (iscycle[i]) cout << "isCycle" << endl;
		else cout << "NO" << endl;
	}*/
	for (int i = 1; i <= n; i++) {
		memset(checked, false, sizeof(checked));
		answer = 99999;
		if (!iscycle[i]) {
			dfs(i,0);
			cout << answer << " ";
		}
		else {
			cout << 0 << " ";
		}
	}
	return 0;
}