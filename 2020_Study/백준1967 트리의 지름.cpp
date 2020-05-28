#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
vector<pair<int,int>> edge[100001];
bool checked[100001];
int answer = -99999999;
void dfs(int x,int weight) {
	//cout << x << endl;
	checked[x] = true;
	bool haveSon = false;
	for (int i = 0; i<edge[x].size(); i++) {
		if (!checked[edge[x][i].first]) {
			dfs(edge[x][i].first,weight + edge[x][i].second);
			haveSon = true;
		}
	}
	if (!haveSon) answer = max(answer, weight);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n-1; i++) {
		int parent,son ,weight;
		cin >> parent >> son >> weight; 
		edge[parent].push_back(make_pair(son,weight));
		edge[son].push_back(make_pair(parent, weight));
	}
	for (int i = 1; i <= n; i++) {
		memset(checked, false, sizeof(checked));
		dfs(i, 0);
	}
	cout << answer;
	return 0;
}