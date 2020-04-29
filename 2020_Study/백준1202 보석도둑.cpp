#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<set>
using namespace std;
vector<pair<int, int>> v;
vector<int> bag;
bool compare(const pair<int, int>&a, const pair<int, int>&b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}
int main() {
	int a, b;
	cin >> a >> b;
	int element;
	int value;
	multiset<int> ms;
	for (int i = 0; i < a; i++) {
		cin >> element >> value;
		v.push_back(make_pair(element, value));
	}
	for (int i = 0; i < b; i++) {
		cin >> element;
		ms.insert(element);
	}
	sort(v.begin(), v.end(), compare);
	unsigned long long ans = 0;
	for (int i = 0; i < v.size(); i++) {
		auto iter = ms.lower_bound(v[i].first);
		if (iter != ms.end()) {
			ans = ans + v[i].second;
			ms.erase(iter);
		}
		if (ms.empty()) break;
	}
	cout << ans;
	return 0;
}