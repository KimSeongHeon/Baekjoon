#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
//vector<int> start;
//vector<int> dest;
vector<pair<int, int>> total;
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		//start.push_back(a);
		//dest.push_back(b);
		total.push_back(make_pair(a, b));
	}
	sort(total.begin(), total.end(), compare);
	int ans = 0;
	int start_minimum = 0;
	int index = 0;
	for (int i = 0; i < total.size(); i++) {
		int select = 987654321;
		if (total[i].first < start_minimum) continue;
		select = min(select, total[i].second);
		if (select == total[i].second) {
			ans++;
			start_minimum = total[i].second;
		}
	}
	cout << ans;
	
	return 0;
}