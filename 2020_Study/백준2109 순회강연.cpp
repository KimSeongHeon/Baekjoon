#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
vector<pair<int, int>> v;
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first > b.first;
}
int main(){
	int n;
	set<int> s;
	int max_day = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, p;
		cin >> p >> d;
		max_day = max(max_day, d);
		v.push_back(make_pair(p, d));
	}
	for (int i = 1; i <= max_day; i++) {
		s.insert(i);
	}
	sort(v.begin(), v.end(), compare);
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (s.find(v[i].second) != s.end()) {
			ans = ans + v[i].first;
			s.erase(v[i].second);
		}
		else {
			for (int j = v[i].second - 1; j >= 1; j--) {
				if (s.find(j) != s.end()) {
					ans = ans + v[i].first;
					s.erase(j);
					break;
				}
			}
		}
	}
	cout << ans;

}