#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<string>
using namespace std;
//* + - /
string depth[1000][1000];
bool visited[1000][1000];
int s, t;
vector<string> ans_list;
queue<pair<int,int>> q;
int main() {
	cin >> s >> t;
	if (s == t) {
		cout << 0;
		return 0;
	}
	q.push(make_pair(1, 0));
	visited[1][0] = true;
	depth[1][0] = "";
	while (!q.empty()) {
		pair<int,int> x = q.front(); q.pop();
		int sum = pow(s,x.first) * pow(2,x.second);
		cout << sum << endl;
		if (sum == t) {
			ans_list.push_back(depth[x.first][x.second]);
		}
		if (sum>0 && sum<=pow(10,9)) {
			if (!visited[x.first * 2][x.second]) {
				q.push(make_pair(x.first * 2, x.second));
				visited[x.first * 2][x.second] = true;
				depth[x.first * 2][x.second] = depth[x.first][x.second] + "*";
			}
			if (!visited[x.first][x.second*2]) {
				q.push(make_pair(x.first, x.second *2));
				visited[x.first][x.second*2] = true;
				depth[x.first][x.second*2] = depth[x.first][x.second] + "+";
			}
			if (!visited[0][0] && sum != 0) {
				q.push(make_pair(0, 0));
				visited[0][0] = true;
				depth[0][0] = depth[x.first][x.second] + "/";
			}
		}
	}
	if(ans_list.size() == 0) cout << -1;
	else {
		for (int i = 0; i < ans_list.size(); i++) {
			cout << ans_list[i] << " ";
		}
		/*int len = 987654321;
		vector<string> real_ans;
		for (int i = 0; i < ans_list.size(); i++) {
			int s = ans_list[i].length();
			len = min(len, s);
		}
		string ans = "////////////";
		for (int i = 0; i < ans_list.size(); i++) {
			if (ans_list[i].length() == len) {
				ans = min(ans, ans_list[i]);
			}
		}
		cout << ans;*/
	}
	return 0;
}