#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int n, k, degree[1001]; 
vector<int> rule[1001];
int result[1001];
int sum[1001];
int time[1001];
int answer = 0;
void topologySort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
			sum[i] = time[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (q.empty()) return;
		int x = q.front();
		q.pop();
		//cout << x << endl;
		result[i] = x;
		for (int j = 0; j < rule[x].size(); j++) {
			int next = rule[x][j];
			//cout << next << endl;
			if (degree[next] > 0) sum[next] = max(sum[next],sum[x] + time[next]);
			if (--degree[next] == 0) q.push(next);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		memset(degree, 0, sizeof(degree));
		memset(rule, 0, sizeof(rule));
		memset(result, 0, sizeof(result));
		memset(time, 0, sizeof(time));
		memset(sum, 0, sizeof(sum));
		answer = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int element;
			cin >> element;
			time[i + 1] = element;
		}
		for (int i = 0; i < k; i++) {
			int first, second;
			cin >> first >> second;
			rule[first].push_back(second);
			degree[second]++;
		}
		int finish;
		cin >> finish;
		topologySort();
		cout << sum[finish] << endl;
	}
	return 0;
}